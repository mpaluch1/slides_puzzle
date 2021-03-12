#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QTime>
#include <QTimer>

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
    virtual void showEvent(QShowEvent* event);

private slots:
    void on_results_table_button_clicked();

    void on_exit_button_clicked();

    void on_new_game_button_clicked();

    void on_change_pic_button_clicked();

    void _update_timer();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<QTimer> _game_timer;
    QTime _game_time;

    void _clear_tiles();
};
#endif // MAINWINDOW_H
