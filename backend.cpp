#include "backend.h"

#include "result.h"

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

bool Backend::is_solved()
{
    return _state->is_solved();
}

Result Backend::save_result()
{
    auto result = _state->save_result();
    _results_table.add(result);

    return result;
}
