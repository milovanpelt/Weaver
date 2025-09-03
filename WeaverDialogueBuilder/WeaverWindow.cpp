#include "WeaverWindow.h"
#include "ui_WeaverWindow.h"


WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);

    int testItemAmount = 35;
    for (int i = 0; i < testItemAmount; i++)
    {
        ui->DialogueListContainer->addItem(QString::number(i));
    }

}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
}
