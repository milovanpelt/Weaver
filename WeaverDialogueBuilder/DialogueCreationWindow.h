#ifndef DIALOGUECREATIONWINDOW_H
#define DIALOGUECREATIONWINDOW_H

#include <QFrame>
#include "DialogueManager.h"
#include "CharacterCreationWindow.h"
#include "uuid_v4.h"

namespace Ui {
class DialogueCreationWindow;
}

class DialogueCreationWindow : public QFrame
{
    Q_OBJECT

public:
    explicit DialogueCreationWindow(UUIDv4::UUID SceneID, QWidget *parent = nullptr);
    ~DialogueCreationWindow();
signals:
    void CreateDialogue(UUIDv4::UUID sceneID, UUIDv4::UUID speakerID, Weaver::DialogueTypes type, const std::string& dialogue);
public slots:
    void on_CharacterCreated(const std::string& name);
private slots:
    void on_button_Confirm_clicked();
    void on_button_Cancel_clicked();
    void on_button_AddCharacter_clicked();
private:
    Ui::DialogueCreationWindow *ui;
    CharacterCreationWindow* characterCreationWindow = nullptr;
    UUIDv4::UUID currentSceneID;
};

#endif // DIALOGUECREATIONWINDOW_H
