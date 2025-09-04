#ifndef DIALOGUECONTAINER_H
#define DIALOGUECONTAINER_H

#include <QFrame>

namespace Ui {
class DialogueContainer;
}

class DialogueContainer : public QFrame
{
    Q_OBJECT

public:
    explicit DialogueContainer(QWidget *parent = nullptr, QString type = "speaker");
    ~DialogueContainer();

private:
    Ui::DialogueContainer *ui;
};

#endif // DIALOGUECONTAINER_H
