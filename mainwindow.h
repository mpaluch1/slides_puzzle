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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
