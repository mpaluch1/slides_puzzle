#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>

#include "gameoptions.h"
#include "tilestable.h"

class GameState
{
public:
    GameState(const GameOptions &options);

    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();

private:
    GameOptions _options;
    TilesTable _tiles_table;
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
};

#endif // GAMESTATE_H
