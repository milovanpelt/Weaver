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

    QObject::connect(characterCreationWindow, &CharacterCreationWindow::CreateCharacterRequested,
                     controller, &WeaverController::on_CharacterCreatedRequested);

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
            qDebug() << "Frame was destroyed";
            characterCreationWindow = nullptr;
        });
    }

    characterCreationWindow->show();
}

void DialogueCreationWindow::on_CharacterCreated(const std::string& name)
{
    std::cout << "[QT - DialogueCreationWindow] Name added: " + name << std::endl;
}

