#include "CharacterCreation.h"
#include "ui_CharacterCreation.h"

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

