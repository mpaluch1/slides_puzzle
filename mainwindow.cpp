#include "mainwindow.h"

#include <string>

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

void MainWindow::display_tiles(const std::map<std::pair<int, int>, int> &tiles)
{
    for (const auto &tile : tiles) {
        auto label = new QLabel(ui->gridLayoutWidget);
        auto idx = std::to_string(tile.second);

        label->setText(QString::fromStdString(idx));
        ui->gridLayout->addWidget(label, tile.first.first, tile.first.second, Qt::AlignCenter);
    }
}
