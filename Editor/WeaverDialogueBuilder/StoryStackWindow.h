#ifndef STORYSTACKWINDOW_H
#define STORYSTACKWINDOW_H

#include <QMainWindow>
#include <fileio.h>
#include <QJsonObject>
#include <StoryStackLibrary.h>
#include "StoryStackController.h"

class DialogueCreationWindow;

QT_BEGIN_NAMESPACE
namespace Ui {
class StoryStackWindow;
}
QT_END_NAMESPACE

class StoryStackWindow : public QMainWindow
{
    Q_OBJECT

public:
    StoryStackWindow(QWidget *parent = nullptr);
    ~StoryStackWindow();
signals:
    void SavingDialogueRequested(const std::string& filename);
public slots:
    void on_CreateDialogue(UUIDv4::UUID speakerID, StoryStack::DialogueTypes type, const std::string& dialogue);
private slots:
    void on_AddDialogue_clicked();

    void on_SaveDialogue_clicked();

private:
    Ui::StoryStackWindow *ui;

    std::string dialogueFile;
    UUIDv4::UUID SceneID;

    DialogueCreationWindow* dialogueCreationWindow = nullptr;
    StoryStackController* controller;
};
#endif // STORYSTACKWINDOW_H
