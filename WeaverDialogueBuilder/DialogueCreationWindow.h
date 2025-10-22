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
signals:


private:
    Ui::DialogueCreationWindow *ui;
private slots:

    void on_button_Confirm_clicked();
    void on_button_Cancel_clicked();
    void on_button_AddCharacter_clicked();
};

#endif // DIALOGUECREATIONWINDOW_H
