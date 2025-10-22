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
    characterCreationWindow->setAttribute(Qt::WA_DeleteOnClose);

    // signal from character creation window to weaver controller to create character
    QObject::connect(characterCreationWindow, &CharacterCreationWindow::CreateCharacterRequested,
                     controller, &WeaverController::on_CharacterCreatedRequested);

    // signal from dialogue creation window to weaver controller to create dialogue
    QObject::connect(this, &DialogueCreationWindow::CreateDialogue,
                     controller, &WeaverController::on_CreateDialogueRequested);

    QObject::connect(characterCreationWindow, &QObject::destroyed, [this]() {
        characterCreationWindow = nullptr;
    });
}

DialogueCreationWindow::DialogueCreationWindow(UUIDv4::UUID SceneID, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueCreationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Character");

    currentSceneID = SceneID;
    characterCreationWindow = new CharacterCreationWindow();
    characterCreationWindow->setAttribute(Qt::WA_DeleteOnClose);

    QObject::connect(characterCreationWindow, &QObject::destroyed, [this]() {
        characterCreationWindow = nullptr;
    });
}



DialogueCreationWindow::~DialogueCreationWindow()
{
    delete ui;
}

void DialogueCreationWindow::on_button_Confirm_clicked()
{
    // 1. get character name and its id
    // 2. get dialogue type
    // 3. get typed dialogue
    // 4. emit DialogueCreationWindow::CreateDialogue(currentSceneID, speakerID, type, dialogue);

    UUIDv4::UUID speakerID = UUIDv4::UUID();
    emit CreateDialogue(currentSceneID, speakerID, Weaver::DialogueTypes::Dialogue, "cool");

    close();
}


void DialogueCreationWindow::on_button_Cancel_clicked()
{
    close();
}


void DialogueCreationWindow::on_button_AddCharacter_clicked()
{
    if (!characterCreationWindow)
    {
        characterCreationWindow = new CharacterCreationWindow();

        characterCreationWindow->setAttribute(Qt::WA_DeleteOnClose);

        QObject::connect(characterCreationWindow, &QObject::destroyed, [this]() {
            characterCreationWindow = nullptr;
        });
    }

    characterCreationWindow->show();
}

void DialogueCreationWindow::on_CharacterCreated(const std::string& name)
{
    std::cout << "[QT - DialogueCreationWindow] Name added: " + name << std::endl;
}

