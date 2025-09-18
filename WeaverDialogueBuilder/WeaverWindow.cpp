#include "WeaverWindow.h"
#include "ui_WeaverWindow.h"
#include "DialogueContainer.h"
#include "CharacterCreation.h"
#include "DialogueManager.h"

WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);

    ui->CurrentSpeaker->setText("NPC");
    ui->CurrentSpeaker->setStyleSheet
    (
        "QLabel {"
        "   color: black;"
        "   background-color: white;"
        "   border: 1px solid black;"
        "   border-radius: 2px;"
        "}"
    );

    SceneID = Weaver::DialogueManager::CreateScene("main");
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}

void WeaverWindow::on_saveDialogue_clicked()
{
}

void WeaverWindow::on_AddDialogue_clicked()
{
    // create empty list item
    auto* item = new QListWidgetItem();

    // create new dialogue widget
    DialogueContainer* newDialogue = new DialogueContainer(this, SceneID, Weaver::DialogueTypes::Dialogue);

    // add empty item to dialogue list
    ui->DialogueListContainer->addItem(item);

    // set empty item to new dialogue widget
    ui->DialogueListContainer->setItemWidget(item, newDialogue);

    // set the size of the dialogue widget
    item->setSizeHint(QSize(250,123));
}


void WeaverWindow::on_AddCharacter_clicked()
{
    CharacterCreation* characterCreation = new CharacterCreation();
    characterCreation->show();
}


void WeaverWindow::on_SaveDialogue_clicked()
{
    Weaver::FileIO::SaveDialogueToJSON("Dialogue.json", Weaver::DialogueManager::GetCharacters(), Weaver::DialogueManager::GetScenes());
}

