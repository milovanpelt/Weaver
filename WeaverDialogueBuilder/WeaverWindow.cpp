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

    //ui->CurrentSpeaker->setText("LONGGGGGGGGGGGGG CHARACTER NAMEEEEEEEEE");
    ui->CurrentSpeaker->setText("NPC");
    ui->CurrentSpeaker->setStyleSheet
    (
        "QLabel {"
        "   color: black;"
        "   background-color: white;"
        "   border: 1px solid black;"
        "   border-radius: 2px;"
        "}"
    );

}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
}
