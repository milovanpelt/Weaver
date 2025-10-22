#ifndef CHARACTERCREATIONWINDOW_H
#define CHARACTERCREATIONWINDOW_H

#include <QFrame>

namespace Ui {
class CharacterCreation;
}

class CharacterCreationWindow : public QFrame
{
    Q_OBJECT

public:
    explicit CharacterCreationWindow(QWidget *parent = nullptr);
    ~CharacterCreationWindow();

private slots:
    void on_CancelButton_clicked();

    void on_ConfirmButton_clicked();

private:
    Ui::CharacterCreation *ui;
};

#endif // CHARACTERCREATIONWINDOW_H
