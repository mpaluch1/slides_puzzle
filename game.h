#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>

#include "backend.h"
#include "frontend.h"
#include "gameoptions.h"

class Game
{
public:
    Game();
    void start();

    void new_game(const std::string &name, int size);

private:
    std::shared_ptr<NotificationBox> _box;
    Frontend _view;
    Backend _model;
};

#endif // GAME_H
