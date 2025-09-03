#include "DialogueContainerr.h"
#include "ui_DialogueContainer.h"

DialogueContainer::DialogueContainer(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::DialogueContainer)
{
    ui->setupUi(this);
}

DialogueContainer::~DialogueContainer()
{
    delete ui;
}
