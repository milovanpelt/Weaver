#include "weaverwindow.h"
#include "ui_weaverwindow.h"


WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);
    connect(ui->btnSavingDialogue, &QPushButton::clicked, this, &WeaverWindow::on_saveDialogue_clicked);

    dialogueFile = "qt-dialogue.json";
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
    std::vector<DialogueEntry> characters;

    DialogueEntry character1;
    DialogueEntry character2;
    DialogueEntry character3;

    character1.speaker = ui->Char1_Name->text().toStdString();
    character2.speaker = ui->Char2_Name->text().toStdString();
    character3.speaker = ui->Char3_Name->text().toStdString();

    std::cout << "character 1: " << character1.speaker << std::endl;
    std::cout << "character 2: " << character2.speaker << std::endl;
    std::cout << "character 3: " << character3.speaker << std::endl;

    character1.lines.push_back(ui->Char1_Dialogue1->text().toStdString());
    character1.lines.push_back(ui->Char1_Dialogue2->text().toStdString());
    character1.lines.push_back(ui->Char1_Dialogue3->text().toStdString());

    character2.lines.push_back(ui->Char2_Dialogue1->text().toStdString());
    character2.lines.push_back(ui->Char2_Dialogue2->text().toStdString());
    character2.lines.push_back(ui->Char2_Dialogue3->text().toStdString());

    character3.lines.push_back(ui->Char3_Dialogue1->text().toStdString());
    character3.lines.push_back(ui->Char3_Dialogue2->text().toStdString());
    character3.lines.push_back(ui->Char3_Dialogue3->text().toStdString());

    characters.push_back(character1);
    characters.push_back(character2);
    characters.push_back(character3);

    Weaver::FileIO::SaveDialogueToJSON(dialogueFile, characters);

    // output data from file onto console
    std::vector<DialogueEntry> data = Weaver::FileIO::ReadDialogueFromJSON(dialogueFile);
    for (const auto& entry : data)
    {
        std::cout << "Speaker name: " << entry.speaker << std::endl;

        for (size_t i = 0 ; i < entry.lines.size(); i++)
        {
            std::cout << "Line " << (i + 1) << " : " << entry.lines[i] << std::endl;
        }
    }
}
