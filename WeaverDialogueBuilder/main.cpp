#include "WeaverWindow.h"
#include "DialogueContainer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeaverWindow mainWindow;
    mainWindow.show();

    DialogueContainer dialogueContainer;
    dialogueContainer.show();
    return a.exec();
}
