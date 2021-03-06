#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <chrono>

#include "gameoptions.h"
#include "tilestable.h"

class Result;

class GameState
{
public:
    GameState(int shuffle_count, const GameOptions &options);

    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();
    Result save_result();
    void set_picture(const std::string &path);

private:
    GameOptions _options;
    TilesTable _tiles_table;
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
};

#endif // GAMESTATE_H
