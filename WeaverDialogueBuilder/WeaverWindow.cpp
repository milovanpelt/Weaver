#include "WeaverWindow.h"
#include "ui_WeaverWindow.h"
#include "DialogueContainer.h"
#include "CharacterCreation.h"

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
    DialogueContainer* newDialogue = new DialogueContainer(this, "speaker");

    // add empty item to dialogue list
    ui->DialogueListContainer->addItem(item);

    // set empty item to new dialogue widget
    ui->DialogueListContainer->setItemWidget(item, newDialogue);

    // set the size of the dialogue widget
    item->setSizeHint(QSize(400,123));
}


void WeaverWindow::on_AddCharacter_clicked()
{
    CharacterCreation* characterCreation = new CharacterCreation();
    characterCreation->show();
}

