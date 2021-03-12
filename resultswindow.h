#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QDialog>

#include "iabletonotify.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog, public IAbleToNotify
{
    Q_OBJECT

public:
    explicit ResultsWindow(QWidget *parent = nullptr);
    ~ResultsWindow();

private slots:
    void on_exit_button_clicked();

private:
    Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
