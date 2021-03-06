#ifndef FRONTEND_H
#define FRONTEND_H

#include "iabletonotify.h"
#include "mainwindow.h"
#include "newgamewindow.h"

class Frontend
    : public IAbleToNotify
{
public:
    Frontend();

    void start();
    void show_game_window();
    void display_tiles(const std::map<std::pair<int, int>, int> &tiles);

 private:
    NewGameWindow _new_game_window;
    MainWindow _main_window;

};

#endif // FRONTEND_H
