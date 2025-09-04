#include "WeaverWindow.h"
#include "DialogueContainer.h"
#include "CharacterCreation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeaverWindow mainWindow;
    mainWindow.show();

    DialogueContainer dialogueContainer;
    dialogueContainer.show();

    CharacterCreation characterCreation;
    characterCreation.show();

    return a.exec();
}
