#include "gameoptions.h"
#include "newgamewindow.h"
#include "ui_newgamewindow.h"

NewGameWindow::NewGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameWindow)
{
    ui->setupUi(this);
    _setup();
}

NewGameWindow::~NewGameWindow()
{
    delete ui;
}

void NewGameWindow::_setup()
{
    ui->problem_size_combo_box->addItems(QStringList({"2", "3", "4"}));
}

void NewGameWindow::on_play_button_clicked()
{
    // TODO do not take empty or default names
    auto player_name = ui->name_text_edit->toPlainText();
    // TODO Change me to use model from somewhere
    auto problem_size = ui->problem_size_combo_box->currentIndex() + 2;

    _box->notify_new_game(player_name.toStdString(), problem_size, false);
}

void NewGameWindow::on_exit_button_clicked()
{
    QCoreApplication::quit();
}
