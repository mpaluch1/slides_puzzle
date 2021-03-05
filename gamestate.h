#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>

#include "gameoptions.h"
#include "tilestable.h"

class GameState
{
public:
    GameState(const GameOptions &options);

private:
    GameOptions _options;
    TilesTable _tiles_table;
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
};

#endif // GAMESTATE_H
