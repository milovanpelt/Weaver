#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

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

private:
    Ui::CharacterCreation *ui;
};

#endif // CHARACTERCREATION_H
