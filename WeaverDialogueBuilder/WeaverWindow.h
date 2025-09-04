#ifndef WEAVERWINDOW_H
#define WEAVERWINDOW_H

#include <QMainWindow>
#include <fileio.h>
#include <QJsonObject>
#include <WeaverLibrary.h>

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
private slots:
    void on_AddDialogue_clicked();

    void on_AddCharacter_clicked();

private:
    Ui::WeaverWindow *ui;

    std::string dialogueFile;
private:
    void on_saveDialogue_clicked();
};
#endif // WEAVERWINDOW_H
