#include "CharacterCreation.h"
#include "ui_CharacterCreation.h"
#include "DialogueManager.h"

CharacterCreation::CharacterCreation(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::CharacterCreation)
{
    ui->setupUi(this);
}

CharacterCreation::~CharacterCreation()
{
    delete ui;
}

void CharacterCreation::on_CancelButton_clicked()
{
    close();
}

void CharacterCreation::on_ConfirmButton_clicked()
{
    const std::string characterName = ui->NameTextBox->text().toStdString();
    Weaver::DialogueManager::AddCharacter(characterName);
    close();
}

