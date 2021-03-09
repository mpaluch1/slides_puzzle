#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "iabletonotify.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IAbleToNotify
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void display_tiles(const std::map<std::pair<int, int>, int> &tiles);

protected:
    virtual void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    void _clear_tiles();
};
#endif // MAINWINDOW_H
