#ifndef WEAVERWINDOW_H
#define WEAVERWINDOW_H

#include <QMainWindow>
#include <fileio.h>
#include <QJsonObject>
#include <WeaverLibrary.h>
#include "WeaverController.h"

class DialogueCreationWindow;

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
signals:
    void SavingDialogueRequested(const std::string& filename);
public slots:
    void on_CreateDialogue(Weaver::DialogueTypes type);
private slots:
    void on_AddDialogue_clicked();

    void on_SaveDialogue_clicked();

private:
    Ui::WeaverWindow *ui;

    std::string dialogueFile;
    UUIDv4::UUID SceneID;

    DialogueCreationWindow* dialogueCreationWindow = nullptr;
    WeaverController* controller;
};
#endif // WEAVERWINDOW_H
