#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <array>
#include <string>
#include <vector>

#include <QDialog>

#include "iabletonotify.h"
#include "ihaveconfig.h"

using result_view_t = std::vector<std::array<std::string, 4>>;

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog, public IAbleToNotify, public IHaveConfig
{
    Q_OBJECT

public:
    explicit ResultsWindow(const Config &config, QWidget *parent = nullptr);
    ~ResultsWindow();

    void show_results(const result_view_t &to_show);

private slots:
    void on_exit_button_clicked();

    void on_show_results_button_clicked();

private:
    Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
