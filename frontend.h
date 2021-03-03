#ifndef FRONTEND_H
#define FRONTEND_H

#include "newgamewindow.h"

class Frontend
{
public:
    Frontend();
    void start();

 private:
    NewGameWindow _new_game_window;
};

#endif // FRONTEND_H
