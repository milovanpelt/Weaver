#ifndef WEAVERWINDOW_H
#define WEAVERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class WeaverWindow;
}
QT_END_NAMESPACE

class WeaverWindow : public QMainWindow
{
    Q_OBJECT

public:
    WeaverWindow(QWidget *parent = nullptr);
    ~WeaverWindow();
private:
    Ui::WeaverWindow *ui;
    QVector<QString> dialogueList;
private:
    void on_saveDialogue_clicked();
};
#endif // WEAVERWINDOW_H
