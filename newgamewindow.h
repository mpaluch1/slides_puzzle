#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>
#include "iabletonotify.h"

namespace Ui {
class NewGameWindow;
}

class NewGameWindow : public QDialog, public IAbleToNotify
{
    Q_OBJECT

public:
    explicit NewGameWindow(QWidget *parent = nullptr);
    ~NewGameWindow();

private slots:
    void on_play_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::NewGameWindow *ui;

    void _setup();
};

#endif // NEWGAMEWINDOW_H
