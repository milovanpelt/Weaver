#ifndef WEAVERWINDOW_H
#define WEAVERWINDOW_H

#include <QMainWindow>
#include <fileio.h>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui {
class WeaverWindow;
}
QT_END_NAMESPACE

class WeaverWindow : public QMainWindow
{
    Q_OBJECT

public:
    WeaverWindow(QWidget *parent = nullptr);
    ~WeaverWindow();
private:
    Ui::WeaverWindow *ui;
    QVector<QString> dialogueList;
    FileIO fileio;
    QJsonObject dialogueObject;
    QString dialogueFile;
private:
    void on_saveDialogue_clicked();
};
#endif // WEAVERWINDOW_H
