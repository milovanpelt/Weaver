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
    explicit DialogueContainer(const std::string& characterName, const std::string& dialogue, QWidget *parent = nullptr);
    ~DialogueContainer();
private:
    Ui::DialogueContainer *ui;
};

#endif // DIALOGUECONTAINER_H
