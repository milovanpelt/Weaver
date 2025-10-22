#include "CharacterCreationWindow.h"
#include "ui_CharacterCreationWindow.h"

CharacterCreationWindow::CharacterCreationWindow(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CharacterCreation)
{
    ui->setupUi(this);
}

CharacterCreationWindow::~CharacterCreationWindow()
{
    delete ui;
}

void CharacterCreationWindow::on_CancelButton_clicked()
{
    close();
}

void CharacterCreationWindow::on_ConfirmButton_clicked()
{
    const std::string characterName = ui->NameTextBox->text().toStdString();
    emit CreateCharacterRequested(characterName);
    close();
}

