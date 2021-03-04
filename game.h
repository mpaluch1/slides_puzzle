#ifndef GAME_H
#define GAME_H

#include <memory>

#include "frontend.h"

class Game
{
public:
    Game();
    void start();

private:
    std::shared_ptr<NotificationBox> _box;
    Frontend _frontend;
};

#endif // GAME_H
