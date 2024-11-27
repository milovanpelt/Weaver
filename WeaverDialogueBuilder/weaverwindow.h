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
};
#endif // WEAVERWINDOW_H
