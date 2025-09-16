#include "DialogueContainer.h"
#include "ui_DialogueContainer.h"

DialogueContainer::DialogueContainer(QWidget *parent, UUIDv4::UUID sceneID, Weaver::DialogueTypes type)
    : QFrame(parent)
    , ui(new Ui::DialogueContainer)
{
    ui->setupUi(this);

    if (type == Weaver::DialogueTypes::Dialogue)
    {
        UUIDv4::UUID newLineID = Weaver::DialogueManager::CreateDialogueEntry(sceneID, type);

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

        for (int i = 0; i < Weaver::DialogueManager::GetCharacterNames().size(); i++)
        {
            QString character = QString::fromStdString(Weaver::DialogueManager::GetCharacterNames()[i]);
            ui->CharacterList->addItem(character);
        }
    }
    else if (type == Weaver::DialogueTypes::Choice)
    {
        return;
    }
    else if (type == Weaver::DialogueTypes::Reply)
    {
        return;
    }
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
