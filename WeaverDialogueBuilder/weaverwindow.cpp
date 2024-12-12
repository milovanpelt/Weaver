#include "weaverwindow.h"
#include "ui_weaverwindow.h"


WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);
    connect(ui->btnSavingDialogue, &QPushButton::clicked, this, &WeaverWindow::on_saveDialogue_clicked);

    dialogueFile = "dialogue.json";
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
    characterNames.append(ui->Char1_Name->text());
    characterNames.append(ui->Char2_Name->text());
    characterNames.append(ui->Char3_Name->text());

    for (const auto &name : characterNames)
    {
        if (!name.isEmpty())
        {
            characterDialoguesList.append(qMakePair(name, QVector<QString>{}));
        }
    }

    qDebug() << "character 1: " << characterNames[0];
    qDebug() << "character 2: " << characterNames[1];
    qDebug() << "character 3: " << characterNames[2];

    characterDialoguesList[0].second.append(ui->Char1_Dialogue1->text());
    characterDialoguesList[0].second.append(ui->Char1_Dialogue2->text());
    characterDialoguesList[0].second.append(ui->Char1_Dialogue3->text());

    characterDialoguesList[1].second.append(ui->Char2_Dialogue1->text());
    characterDialoguesList[1].second.append(ui->Char2_Dialogue2->text());
    characterDialoguesList[1].second.append(ui->Char2_Dialogue3->text());

    characterDialoguesList[2].second.append(ui->Char3_Dialogue1->text());
    characterDialoguesList[2].second.append(ui->Char3_Dialogue2->text());
    characterDialoguesList[2].second.append(ui->Char3_Dialogue3->text());

    for (const auto &entry : characterDialoguesList)
    {
        qDebug() << entry.first << entry.second;
    }

    fileio.SaveDialogueToJSON(dialogueFile, characterDialoguesList);
}
