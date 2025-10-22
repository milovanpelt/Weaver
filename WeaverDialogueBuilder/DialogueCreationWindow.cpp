#include "DialogueCreationWindow.h"
#include "ui_DialogueCreationWindow.h"

DialogueCreationWindow::DialogueCreationWindow(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueCreationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Character");
}

DialogueCreationWindow::~DialogueCreationWindow()
{
    delete ui;
}

void DialogueCreationWindow::on_button_Confirm_clicked()
{
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

