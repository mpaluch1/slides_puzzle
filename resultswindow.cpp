#include "resultswindow.h"
#include "ui_resultswindow.h"

#include <QTableWidget>

ResultsWindow::ResultsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    ui->size_choice->addItems(QStringList({"2", "3", "4"})); // TODO from config
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::on_exit_button_clicked()
{
    this->hide();
}

void ResultsWindow::on_show_results_button_clicked()
{
    auto size = ui->size_choice->currentIndex() + 2;
    _box->notify_show_results(size); // TODO Change me^
}

void ResultsWindow::show_results(const result_view_t &to_show)
{
    ui->results_table->clear();

    int rows = to_show.size() - 1;
    int cols = to_show[0].size();
    ui->results_table->setRowCount(rows);
    ui->results_table->setColumnCount(cols);

    QStringList headers;
    for (const auto &header : to_show[0]) {
        headers.append(QString::fromStdString(header));
    }

    ui->results_table->setHorizontalHeaderLabels(headers);

    for (int i = 1; i <= rows; ++i) {
        for (unsigned j = 0; j < to_show[i].size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(to_show[i][j]));
            ui->results_table->setItem(i-1, j, item);
        }
    }
}
