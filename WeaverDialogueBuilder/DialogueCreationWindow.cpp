#include "DialogueCreationWindow.h"
#include "ui_DialogueCreationWindow.h"

DialogueCreationWindow::DialogueCreationWindow(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueCreationWindow)
{
    ui->setupUi(this);
}

DialogueCreationWindow::~DialogueCreationWindow()
{
    delete ui;
}
