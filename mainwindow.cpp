#include "mainwindow.h"

#include <string>

#include <QMouseEvent>
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
    _clear_tiles();

    for (const auto &tile : tiles) {
        auto label = new QLabel(ui->gridLayoutWidget);
        auto idx = std::to_string(tile.second);

        label->setText(QString::fromStdString(idx));
        label->setAlignment(Qt::AlignCenter);
        label->setFrameStyle(QFrame::Plain | QFrame::Box);
        label->setLineWidth(2);
        ui->gridLayout->addWidget(label, tile.first.first, tile.first.second);
    }
}

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
    auto row = 0;
    auto col = 0;
    auto dummy = 0;
    ui->gridLayout->getItemPosition(index, &row, &col, &dummy, &dummy);

    _box->notify_tile_clicked(row, col);
}

void MainWindow::_clear_tiles()
{
    qDeleteAll(ui->gridLayoutWidget->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
}


void MainWindow::on_results_table_button_clicked()
{
    _box->notify_show_results_table();
}
