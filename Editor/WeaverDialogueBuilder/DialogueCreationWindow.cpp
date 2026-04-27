#include "DialogueCreationWindow.h"
#include "ui_DialogueCreationWindow.h"

DialogueCreationWindow::DialogueCreationWindow(StoryStackController* controller, UUIDv4::UUID SceneID, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueCreationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Character");

    currentSceneID = SceneID;
    storyStackController = controller;
    characterCreationWindow = new CharacterCreationWindow();

    // signal from character creation window to weaver controller to create character
    QObject::connect(characterCreationWindow, &CharacterCreationWindow::CreateCharacterRequested,
                     controller, &StoryStackController::on_CharacterCreatedRequested);

    // signal from dialogue creation window to weaver controller to create dialogue
    QObject::connect(this, &DialogueCreationWindow::CreateDialogue,
                     controller, &StoryStackController::on_CreateDialogueRequested);

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

    StoryStack::DialogueTypes dialogueType;
    if (selectedDialogueType == "Dialogue")
    {
        dialogueType = StoryStack::DialogueTypes::Dialogue;
    }
    if (selectedDialogueType == "Choice")
    {
        dialogueType = StoryStack::DialogueTypes::Choice;
    }
    if (selectedDialogueType == "Reply")
    {
        dialogueType = StoryStack::DialogueTypes::Reply;
    }

    UUIDv4::UUID selectecCharacterID = StoryStack::GetCharacterIdFromName(selectedCharacterName);
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

