#ifndef CONGRATSWINDOW_H
#define CONGRATSWINDOW_H

#include <string>

#include <QDialog>
#include "iabletonotify.h"

namespace Ui {
class CongratsWindow;
}

class CongratsWindow : public QDialog, public IAbleToNotify
{
    Q_OBJECT

public:
    explicit CongratsWindow(QWidget *parent = nullptr);
    ~CongratsWindow();

    void set_result(const std::string &name, const std::string &time, const std::string &date);

private slots:
    void on_new_game_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::CongratsWindow *ui;
};

#endif // CONGRATSWINDOW_H
