#include "backend.h"

Backend::Backend()
{

}

void Backend::start_new_game(const GameOptions &options)
{
    _state = std::make_unique<GameState>(options);
}

tile_matrix Backend::get_tiles()
{
    return _state->get_tiles();
}

bool Backend::move_tile(int row, int col)
{
    return _state->move_tile(row, col);
}
