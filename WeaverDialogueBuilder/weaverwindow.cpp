#include "weaverwindow.h"
#include "ui_weaverwindow.h"

WeaverWindow::WeaverWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeaverWindow)
{
    ui->setupUi(this);
}

WeaverWindow::~WeaverWindow()
{
    delete ui;
}
