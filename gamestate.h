#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>

#include "gameoptions.h"
#include "ihaveconfig.h"
#include "tilestable.h"

class Result;

class GameState: public IHaveConfig
{
public:
    GameState(const Config &config, const GameOptions &options);

    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();
    Result save_result();

private:
    GameOptions _options;
    TilesTable _tiles_table;
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
};

#endif // GAMESTATE_H
