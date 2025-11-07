#include "DialogueContainer.h"
#include "ui_DialogueContainer.h"
#include "DialogueManager.h"

DialogueContainer::DialogueContainer(const std::string& characterName, const std::string& dialogue, QWidget *parent)
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

    ui->CharacterList->clear();

    for (int i = 0; i < Weaver::GetCharacterNames().size(); i++)
    {
        QString character = QString::fromStdString(Weaver::GetCharacterNames()[i]);
        ui->CharacterList->addItem(character);
    }

    const QString QcharacterName = QString::fromStdString(characterName);

    int index = ui->CharacterList->findText(QcharacterName);
    if (index != -1)
    {
        ui->CharacterList->setCurrentIndex(index);
    }

    ui->DialogueTextBox->setPlainText(QString::fromStdString(dialogue));
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
