#include "DialogueCreationWindow.h"
#include "ui_DialogueCreationWindow.h"

DialogueCreationWindow::DialogueCreationWindow(WeaverController* controller, UUIDv4::UUID SceneID, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueCreationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Character");

    currentSceneID = SceneID;
    weaverController = controller;
    characterCreationWindow = new CharacterCreationWindow();

    // signal from character creation window to weaver controller to create character
    QObject::connect(characterCreationWindow, &CharacterCreationWindow::CreateCharacterRequested,
                     controller, &WeaverController::on_CharacterCreatedRequested);

    // signal from dialogue creation window to weaver controller to create dialogue
    QObject::connect(this, &DialogueCreationWindow::CreateDialogue,
                     controller, &WeaverController::on_CreateDialogueRequested);

    ui->DialogueTypes->addItem("Dialogue");
    ui->DialogueTypes->addItem("Choice");
    ui->DialogueTypes->addItem("Reply");
}

DialogueCreationWindow::~DialogueCreationWindow()
{
    delete ui;
}

void DialogueCreationWindow::on_button_Confirm_clicked()
{
    const std::string selectedCharacterName = ui->CharacterNames->currentText().toStdString();
    const std::string selectedDialogueType = ui->DialogueTypes->currentText().toStdString();
    const std::string currentDialogue = ui->DialogueText->toPlainText().toStdString();

    // Dialogue can only be created if a character is created and selected
    if (selectedCharacterName == "")
    {
        std::cout << "[DialogueCreationWindow] No name created" << std::endl;
        return;
    }

    Weaver::DialogueTypes dialogueType;
    if (selectedDialogueType == "Dialogue")
    {
        dialogueType = Weaver::DialogueTypes::Dialogue;
    }
    if (selectedDialogueType == "Choice")
    {
        dialogueType = Weaver::DialogueTypes::Choice;
    }
    if (selectedDialogueType == "Reply")
    {
        dialogueType = Weaver::DialogueTypes::Reply;
    }

    UUIDv4::UUID selectecCharacterID = Weaver::GetCharacterIdFromName(selectedCharacterName);
    emit CreateDialogue(currentSceneID, selectecCharacterID, dialogueType, currentDialogue);

    ui->DialogueText->clear();
    close();
}


void DialogueCreationWindow::on_button_Cancel_clicked()
{
    close();
}


void DialogueCreationWindow::on_button_AddCharacter_clicked()
{
    characterCreationWindow->show();
}

void DialogueCreationWindow::on_CharacterCreated(const std::string& name)
{
    const QString& Qname = QString::fromStdString(name);
    ui->CharacterNames->addItem(Qname);
    std::cout << "[DialogueCreationWindow] Name added: " + name << std::endl;
}

