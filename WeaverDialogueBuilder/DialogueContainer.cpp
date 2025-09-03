#include "DialogueContainer.h"
#include "ui_DialogueContainer.h"

DialogueContainer::DialogueContainer(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueContainer)
{
    ui->setupUi(this);

    int testItemAmount = 35;
    for (int i = 0; i < testItemAmount; i++)
    {
        ui->CharacterList->addItem(QString::number(i) + "- Character Name");
    }

    ui->DialogueTextBox->setStyleSheet
    (
        "QLineEdit {"
        "   color: black;"
        "   background-color: white;"
        "   border: 1px solid gray;"
        "   border-radius: 4px;"
        "}"
        "QLineEdit:placeholder {"
        "   color: lightgray;"
        "}"
    );
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
