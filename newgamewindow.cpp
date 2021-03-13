#include "gameoptions.h"
#include "newgamewindow.h"
#include "ui_newgamewindow.h"

#include <algorithm>

#include <QMessageBox>

NewGameWindow::NewGameWindow(const Config &config, QWidget *parent) :
    QDialog(parent),
    IHaveConfig(config),
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
    QStringList list;
    std::transform(_config.problem_sizes.begin(), _config.problem_sizes.end(),
                   std::back_inserter(list), [](auto el){
        return QString::number(el);
    });

    ui->problem_size_combo_box->addItems(list);
}

void NewGameWindow::on_play_button_clicked()
{
    auto player_name = ui->name_text_edit->toPlainText();
    if (player_name.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Imię nie może być puste.");
        msgBox.exec();

        return;
    }

    auto idx = ui->problem_size_combo_box->currentIndex();
    auto problem_size = _config.problem_sizes[idx];

    _box->notify_new_game(player_name.toStdString(), problem_size);
}

void NewGameWindow::on_exit_button_clicked()
{
    QCoreApplication::quit();
}
