#ifndef DIALOGUECONTAINER_H
#define DIALOGUECONTAINER_H

#include <QFrame>
#include "DialogueManager.h"
#include "uuid_v4.h"

namespace Ui {
class DialogueContainer;
}

class DialogueContainer : public QFrame
{
    Q_OBJECT

public:
    explicit DialogueContainer(QWidget *parent = nullptr, UUIDv4::UUID sceneID = 0, Weaver::DialogueTypes type = Weaver::DialogueTypes::Dialogue);
    ~DialogueContainer();
private:
    Ui::DialogueContainer *ui;
};

#endif // DIALOGUECONTAINER_H
