#include "gamestate.h"

GameState::GameState(const GameOptions &options)
    : _options(options)
{
    _tiles_table.set_table_size(_options.problem_size);
    _tiles_table.shuffle();
    _start_time = std::chrono::steady_clock::now();
}

tile_matrix GameState::get_tiles()
{
    return _tiles_table.get_tiles();
}
