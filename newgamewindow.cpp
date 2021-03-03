#include "newgamewindow.h"
#include "ui_newgamewindow.h"

NewGameWindow::NewGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameWindow)
{
    ui->setupUi(this);
}

NewGameWindow::~NewGameWindow()
{
    delete ui;
}
