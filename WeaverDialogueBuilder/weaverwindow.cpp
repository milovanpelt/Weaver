#include "weaverwindow.h"
#include "ui_weaverwindow.h"
#include <QFile>

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
    QFile file("dialogue.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qCritical() << file.errorString();
        return;
    }

    QTextStream out(&file);

    dialogueList[0] = ui->dialogueFirst->text();
    dialogueList[1] = ui->dialogueSecond->text();
    dialogueList[2] = ui->dialogueThird->text();

    for (int i = 0; i < dialogueList.size(); i++)
    {
        int dialogueLineNumber = i + 1;
        QString dialogueText = "Dialogue " + QString::number(dialogueLineNumber) + " " + dialogueList.at(i);
        qInfo() << dialogueText;
        out << dialogueText << "\n";
    }

    file.close();
}
