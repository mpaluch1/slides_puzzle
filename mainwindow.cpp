#include "mainwindow.h"

#include <string>

#include <QFileDialog>
#include <QMouseEvent>
#include <QPixmap>
#include <QString>
#include <QtWidgets/QLabel>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_tiles(const std::map<std::pair<int, int>, std::string> &tiles)
{
    _clear_tiles();

    for (const auto &tile : tiles) {
        auto label = new QLabel(ui->gridLayoutWidget);
        if (!tile.second.empty()) {
            auto pic = QPixmap(QString::fromStdString(tile.second));
            label->setPixmap(pic);
        }

        ui->gridLayout->addWidget(label, tile.first.first, tile.first.second);
    }
}

#include <iostream>
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget * const widget = childAt(event->pos());
    if (!widget) {
        return;
    }

    const QLabel * const label = qobject_cast<QLabel *>(widget);
    if (!label) {
        return;
    }

    const int index = ui->gridLayout->indexOf(widget);
    if (index == -1) {
        return;
    }

    auto row = 0;
    auto col = 0;
    auto dummy = 0;
    ui->gridLayout->getItemPosition(index, &row, &col, &dummy, &dummy);

    _box->notify_tile_clicked(row, col);
}

void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    _game_timer = std::make_unique<QTimer>();
    _game_time = QTime(0, 0, 0);

    connect(_game_timer.get(), SIGNAL(timeout()), this, SLOT(_update_timer()));
    _game_timer->start(1000);
}

void MainWindow::_clear_tiles()
{
    qDeleteAll(ui->gridLayoutWidget->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
}

void MainWindow::on_results_table_button_clicked()
{
    _game_timer->stop();
    _box->notify_show_results_table();
}

void MainWindow::on_exit_button_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_new_game_button_clicked()
{
    _game_timer->stop();
    _box->notify_restart_game();
}

void MainWindow::on_change_pic_button_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Wybierz obraz"), "", tr("Image Files (*.jpg)"));

    std::cout << fileName.toStdString() << std::endl;
}

void MainWindow::_update_timer()
{
    _game_time = _game_time.addSecs(1);
    ui->time_label->setText(_game_time.toString("hh:mm:ss"));
}
