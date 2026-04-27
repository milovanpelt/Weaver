#include "StoryStackWindow.h"
#include "ui_StoryStackWindow.h"
#include "DialogueContainer.h"
#include "DialogueCreationWindow.h"

StoryStackWindow::StoryStackWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StoryStackWindow)
{
    ui->setupUi(this);
    controller = new StoryStackController(this);

    SceneID = StoryStack::CreateScene("main");
    dialogueFile = "StoryStackDialogue.json";
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

    // signal from storystack window to storystack controller to save dialogue
    QObject::connect(this, &StoryStackWindow::SavingDialogueRequested,
                     controller, &StoryStackController::on_SavingDialogueRequested);

    // signal from storystack controller to storystack window to create dialogue ui
    QObject::connect(controller, &StoryStackController::DialogueCreated,
                     this, &StoryStackWindow::on_CreateDialogue);

    // signal from storystack controller to dialogue creation window  to update character list
    QObject::connect(controller, &StoryStackController::CharacterCreated,
                     dialogueCreationWindow, &DialogueCreationWindow::on_CharacterCreated);

}

StoryStackWindow::~StoryStackWindow()
{
    delete ui;
}

void StoryStackWindow::on_AddDialogue_clicked()
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

void StoryStackWindow::on_SaveDialogue_clicked()
{
    emit SavingDialogueRequested(dialogueFile);
}

void StoryStackWindow::on_CreateDialogue(UUIDv4::UUID speakerID, StoryStack::DialogueTypes type, const std::string& dialogue)
{
    if (type == StoryStack::DialogueTypes::Dialogue)
    {
        std::cout << "[StoryStack Window]: Dialogue Container created with type: 'Dialogue'" << std::endl;

        // create empty list item
        auto* item = new QListWidgetItem();

        const std::string characterName = StoryStack::GetCharacterNameFromID(speakerID);

        // create new dialogue widget
        DialogueContainer* newDialogue = new DialogueContainer(characterName, dialogue, this);

        // add empty item to dialogue list
        ui->DialogueListContainer->addItem(item);

        // set empty item to new dialogue widget
        ui->DialogueListContainer->setItemWidget(item, newDialogue);

        // set the size of the dialogue widget
        item->setSizeHint(QSize(250,123));
    }
    else if (type == StoryStack::DialogueTypes::Choice)
    {
        return;
    }
    else if (type == StoryStack::DialogueTypes::Reply)
    {
        return;
    }
}

