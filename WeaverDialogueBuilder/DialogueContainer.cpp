#include "DialogueContainer.h"
#include "ui_DialogueContainer.h"

DialogueContainer::DialogueContainer(QWidget *parent, QString type)
    : QFrame(parent)
    , ui(new Ui::DialogueContainer)
{
    ui->setupUi(this);

    int testItemAmount = 35;
    for (int i = 0; i < testItemAmount; i++)
    {
        ui->CharacterList->addItem(QString::number(i) + "- Character Name");
    }

    if (type == "dialogue")
    {
        ui->DialogueTextBox->setStyleSheet
        (
            "QPlainTextEdit {"
            "   color: black;"
            "   background-color: white;"
            "   border: 1px solid gray;"
            "   border-radius: 4px;"
            "}"
            "QPlainTextEdit:placeholder {"
            "   color: lightgray;"
            "}"
        );
    }
    else if (type == "choice")
    {
        return;
    }
    else if (type == "reply")
    {
        return;
    }
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
