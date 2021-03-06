#include "gamestate.h"

#include <chrono>

#include <spdlog/spdlog.h>

#include "picture.h"
#include "result.h"

GameState::GameState(int shuffle_count, const GameOptions &options)
    : _options{options}
    , _tiles_table{shuffle_count}
{
    _tiles_table.set_table_size(_options.problem_size);
    _tiles_table.shuffle();
    _start_time = std::chrono::steady_clock::now();

    spdlog::debug("Created GameState with start time {}",
                  _start_time.time_since_epoch().count());
}

tile_matrix GameState::get_tiles()
{
    return _tiles_table.get_tiles();
}

bool GameState::move_tile(int row, int col)
{
    return _tiles_table.move_tile(row, col);
}

bool GameState::is_solved()
{
    return _tiles_table.is_solved();
}

Result GameState::save_result()
{
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time =
            std::chrono::duration_cast<std::chrono::seconds>(end_time - _start_time);
    auto now_real_time = std::chrono::system_clock::now();

    return Result(elapsed_time.count(), now_real_time, _options);
}

void GameState::set_picture(const std::string &path)
{
    auto pic = Picture(path);

    std::string directory;
    const size_t last_slash_idx = path.rfind('/');
    if (std::string::npos != last_slash_idx) {
        directory = path.substr(0, last_slash_idx);
    }

    auto paths = pic.save_fragmented(directory, _options.problem_size);
    _tiles_table.set_image_fragment_paths(paths);
}
