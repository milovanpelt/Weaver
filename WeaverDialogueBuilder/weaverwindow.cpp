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
            characterDialogues[name];
        }
    }

    characterDialogues[characterNames[0]].append(ui->Char1_Dialogue1->text());
    characterDialogues[characterNames[0]].append(ui->Char1_Dialogue2->text());
    characterDialogues[characterNames[0]].append(ui->Char1_Dialogue3->text());

    characterDialogues[characterNames[1]].append(ui->Char2_Dialogue1->text());
    characterDialogues[characterNames[1]].append(ui->Char2_Dialogue2->text());
    characterDialogues[characterNames[1]].append(ui->Char2_Dialogue3->text());

    characterDialogues[characterNames[2]].append(ui->Char3_Dialogue1->text());
    characterDialogues[characterNames[2]].append(ui->Char3_Dialogue2->text());
    characterDialogues[characterNames[2]].append(ui->Char3_Dialogue3->text());
}
