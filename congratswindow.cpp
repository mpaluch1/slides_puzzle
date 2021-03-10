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

void CongratsWindow::set_result(const std::string &name, const std::string &time, const std::string &date)
{
    ui->name_label->setText(QString::fromStdString(name));
    ui->time_label->setText(QString::fromStdString(time));
    ui->date_label->setText(QString::fromStdString(date));
}
