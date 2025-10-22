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
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_AddDialogue_clicked()
{
    if (!dialogueCreationWindow)
    {
        dialogueCreationWindow = new DialogueCreationWindow(SceneID);

        dialogueCreationWindow->setAttribute(Qt::WA_DeleteOnClose);

        QObject::connect(dialogueCreationWindow, &QObject::destroyed, [this]() {
            dialogueCreationWindow = nullptr;
        });
    }

    dialogueCreationWindow->show();

    // // create empty list item
    // auto* item = new QListWidgetItem();

    // // create new dialogue widget
    // DialogueContainer* newDialogue = new DialogueContainer(this, SceneID, Weaver::DialogueTypes::Dialogue);

    // // add empty item to dialogue list
    // ui->DialogueListContainer->addItem(item);

    // // set empty item to new dialogue widget
    // ui->DialogueListContainer->setItemWidget(item, newDialogue);

    // // set the size of the dialogue widget
    // item->setSizeHint(QSize(250,123));
}

void WeaverWindow::on_SaveDialogue_clicked()
{
    emit SavingDialogueRequested(dialogueFile);
}

void WeaverWindow::on_CreateDialogue(Weaver::DialogueTypes type)
{

}

