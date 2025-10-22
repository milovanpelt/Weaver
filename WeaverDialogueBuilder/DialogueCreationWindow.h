#ifndef DIALOGUECREATIONWINDOW_H
#define DIALOGUECREATIONWINDOW_H

#include <QFrame>

namespace Ui {
class DialogueCreationWindow;
}

class DialogueCreationWindow : public QFrame
{
    Q_OBJECT

public:
    explicit DialogueCreationWindow(QWidget *parent = nullptr);
    ~DialogueCreationWindow();

private:
    Ui::DialogueCreationWindow *ui;
};

#endif // DIALOGUECREATIONWINDOW_H
