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

private:
    Ui::CongratsWindow *ui;
};

#endif // CONGRATSWINDOW_H
