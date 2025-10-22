#ifndef CHARACTERCREATIONWINDOW_H
#define CHARACTERCREATIONWINDOW_H

#include <QFrame>

namespace Ui {
class CharacterCreation;
}

class CharacterCreation : public QFrame
{
    Q_OBJECT

public:
    explicit CharacterCreation(QWidget *parent = nullptr);
    ~CharacterCreation();

private slots:
    void on_CancelButton_clicked();

    void on_ConfirmButton_clicked();

private:
    Ui::CharacterCreation *ui;
};

#endif // CHARACTERCREATIONWINDOW_H
