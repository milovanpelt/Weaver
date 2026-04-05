#include "WeaverWindow.h"
#include "ui_WeaverWindow.h"
#include "DialogueContainer.h"
#include "DialogueCreationWindow.h"

WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);
    controller = new WeaverController(this);

    SceneID = Weaver::CreateScene("main");
    dialogueFile = "WeaverDialogue.json";
    dialogueCreationWindow = new DialogueCreationWindow(controller, SceneID);

    // ui->CurrentSpeaker->setText("NPC");
    // ui->CurrentSpeaker->setStyleSheet
    // (
    //     "QLabel {"
    //     "   color: black;"
    //     "   background-color: white;"
    //     "   border: 1px solid black;"
    //     "   border-radius: 2px;"
    //     "}"
    // );

    // signal from weaver window to weaver controller to save dialogue
    QObject::connect(this, &WeaverWindow::SavingDialogueRequested,
                     controller, &WeaverController::on_SavingDialogueRequested);

    // signal from weaver controller to weaver window to create dialogue ui
    QObject::connect(controller, &WeaverController::DialogueCreated,
                     this, &WeaverWindow::on_CreateDialogue);

    // signal from weaver controller to dialogue creation window  to update character list
    QObject::connect(controller, &WeaverController::CharacterCreated,
                     dialogueCreationWindow, &DialogueCreationWindow::on_CharacterCreated);

}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_AddDialogue_clicked()
{
    if (!dialogueCreationWindow)
    {
        dialogueCreationWindow = new DialogueCreationWindow(controller, SceneID);

        dialogueCreationWindow->setAttribute(Qt::WA_DeleteOnClose);

        QObject::connect(dialogueCreationWindow, &QObject::destroyed, [this]() {
            dialogueCreationWindow = nullptr;
        });
    }

    dialogueCreationWindow->show();
}

void WeaverWindow::on_SaveDialogue_clicked()
{
    emit SavingDialogueRequested(dialogueFile);
}

void WeaverWindow::on_CreateDialogue(UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue)
{
    if (type == Weaver::DialogueTypes::Dialogue)
    {
        std::cout << "[Weaver Window]: Dialogue Container created with type: 'Dialogue'" << std::endl;

        // create empty list item
        auto* item = new QListWidgetItem();

        const std::string characterName = Weaver::GetCharacterNameFromID(speakerID);

        // create new dialogue widget
        DialogueContainer* newDialogue = new DialogueContainer(characterName, dialogue, this);

        // add empty item to dialogue list
        ui->DialogueListContainer->addItem(item);

        // set empty item to new dialogue widget
        ui->DialogueListContainer->setItemWidget(item, newDialogue);

        // set the size of the dialogue widget
        item->setSizeHint(QSize(250,123));
    }
    else if (type == Weaver::DialogueTypes::Choice)
    {
        return;
    }
    else if (type == Weaver::DialogueTypes::Reply)
    {
        return;
    }
}

