#include "WeaverWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeaverWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
