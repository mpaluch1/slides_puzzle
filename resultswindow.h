#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <array>
#include <string>
#include <vector>

#include <QDialog>

#include "iabletonotify.h"

using result_view_t = std::vector<std::array<std::string, 4>>;

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog, public IAbleToNotify
{
    Q_OBJECT

public:
    explicit ResultsWindow(const std::vector<int> &sizes, QWidget *parent = nullptr);
    ~ResultsWindow();

    void show_results(const result_view_t &to_show);

private slots:
    void on_exit_button_clicked();

    void on_show_results_button_clicked();

private:
    Ui::ResultsWindow *ui;
    const std::vector<int> _sizes;
};

#endif // RESULTSWINDOW_H
