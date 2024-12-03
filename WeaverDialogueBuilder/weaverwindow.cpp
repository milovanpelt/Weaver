#include "weaverwindow.h"
#include "ui_weaverwindow.h"

WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);
    connect(ui->btnSavingDialogue, &QPushButton::clicked, this, &WeaverWindow::on_saveDialogue_clicked);

    int reservedItems = 3;
    dialogueList.reserve(reservedItems);
    for (qsizetype i = 0; i < reservedItems; i++)
    {
        dialogueList.push_back("");
    }
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
    dialogueList[0] = ui->dialogueFirst->text();
    dialogueList[1] = ui->dialogueSecond->text();
    dialogueList[2] = ui->dialogueThird->text();

    for (int i = 0; i < dialogueList.size(); i++)
    {
        int dialogueLineNumber = i + 1;
        qInfo() << "Dialogue " + QString::number(dialogueLineNumber) << dialogueList.at(i);
    }
}
