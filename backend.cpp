#include "backend.h"

#include "result.h"

Backend::Backend(const std::string &res_filename)
    : _results_table{res_filename}
{

}

void Backend::start_new_game(const GameOptions &options, int shuffle_count)
{
    _state = std::make_unique<GameState>(shuffle_count, options);
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

std::vector<Result> Backend::get_result_table(int problem_size)
{
    return _results_table.get(problem_size);
}

void Backend::set_picture(const std::string &path)
{
    _state->set_picture(path);
}
