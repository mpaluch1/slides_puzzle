#ifndef FRONTEND_H
#define FRONTEND_H

#include <memory>

#include "newgamewindow.h"

class Frontend
{
public:
    Frontend();
    void start();

 private:
    std::unique_ptr<NewGameWindow> _new_game_window;
};

#endif // FRONTEND_H
