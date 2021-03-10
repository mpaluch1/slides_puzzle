#ifndef CONGRATSWINDOW_H
#define CONGRATSWINDOW_H

#include <QDialog>

namespace Ui {
class CongratsWindow;
}

class CongratsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CongratsWindow(QWidget *parent = nullptr);
    ~CongratsWindow();

private:
    Ui::CongratsWindow *ui;
};

#endif // CONGRATSWINDOW_H
