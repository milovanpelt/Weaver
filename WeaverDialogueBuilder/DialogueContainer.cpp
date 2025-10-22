#include "DialogueContainer.h"
#include "ui_DialogueContainer.h"

DialogueContainer::DialogueContainer(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueContainer)
{
    ui->setupUi(this);

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


    //     ui->CharacterList->clear();

    //     for (int i = 0; i < Weaver::DialogueManager::GetCharacterNames().size(); i++)
    //     {
    //         QString character = QString::fromStdString(Weaver::DialogueManager::GetCharacterNames()[i]);
    //         ui->CharacterList->addItem(character);
    //     }
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
