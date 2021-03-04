#ifndef BACKEND_H
#define BACKEND_H

#include <memory>

#include <gameoptions.h>
#include "gamestate.h"

class Backend
{
public:
    Backend();

    void start_new_game(const GameOptions &options);

private:
    std::unique_ptr<GameState> _state;
};

#endif // BACKEND_H