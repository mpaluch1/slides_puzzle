#ifndef FRONTEND_H
#define FRONTEND_H

#include <memory>

#include "iabletonotify.h"
#include "newgamewindow.h"

class Frontend
    : public IAbleToNotify
{
public:
    Frontend();

    void start();

 private:
    NewGameWindow _new_game_window;
};

#endif // FRONTEND_H
