#include "congratswindow.h"
#include "ui_congratswindow.h"

CongratsWindow::CongratsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CongratsWindow)
{
    ui->setupUi(this);
}

CongratsWindow::~CongratsWindow()
{
    delete ui;
}
