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

}


void DialogueCreationWindow::on_button_Cancel_clicked()
{

}


void DialogueCreationWindow::on_button_AddCharacter_clicked()
{

}

