#ifndef GAME_H
#define GAME_H

#include "frontend.h"

class Game
{
public:
    Game();
    void start();

private:
    Frontend _frontend;
};

#endif // GAME_H
