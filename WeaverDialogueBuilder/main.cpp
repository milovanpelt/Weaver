#include "weaverwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeaverWindow w;
    w.show();
    return a.exec();
}
