#include "StoryStackWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StoryStackWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
