#ifndef FRONTEND_H
#define FRONTEND_H

#include "congratswindow.h"
#include "iabletonotify.h"
#include "mainwindow.h"
#include "newgamewindow.h"
#include "resultswindow.h"

class Frontend
    : public IAbleToNotify
{
public:
    Frontend(const std::vector<int> &sizes);

    void start();
    void show_game_window();
    void display_tiles(const std::map<std::pair<int, int>, std::string> &tiles);
    void show_congrats_window(const std::string &name, const std::string &time, const std::string &date);
    void show_results_window();
    void show_results(const result_view_t &to_show);

 private:
    NewGameWindow _new_game_window;
    MainWindow _main_window;
    CongratsWindow _congrats_window;
    ResultsWindow _results_window;
};

#endif // FRONTEND_H
