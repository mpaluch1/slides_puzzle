#include "gamestate.h"

GameState::GameState(const GameOptions &options)
    : _options(options)
{
    _tiles_table.set_table_size(_options.problem_size);
    _start_time = std::chrono::steady_clock::now();
}
