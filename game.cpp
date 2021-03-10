#include "game.h"

#include <chrono>

#include <spdlog/spdlog.h>

#include "result.h"

Game::Game()
{
    _box = std::make_shared<NotificationBox>(*this);
}

void Game::start()
{
    spdlog::info("Starting game");

    _view.set_notification_box(_box);
    _view.start();
}

void Game::new_game(const std::string &name, int size, bool renew)
{
    spdlog::info("Creating new game with name {} and size {}", name, size);

    auto options = GameOptions(name, size);
    if (renew && _cached_options) {
        options = *_cached_options;
    }

    _cached_options = std::make_unique<GameOptions>(options);

    _model.start_new_game(options);
    _view.show_game_window();
    _view.display_tiles(_transform_tiles_for_frontend());
}

void Game::move_tile(int row, int column)
{
    spdlog::debug("Moving tile at {},{}", row, column);

    auto moved = _model.move_tile(row, column);
    if (!moved) {
        return;
    }

    _view.display_tiles(_transform_tiles_for_frontend());
    auto solved = _model.is_solved();
    if (solved) {
        spdlog::info("Solved!");
        auto result = _model.save_result();
        _game_won(result);
    }
}

std::map<std::pair<int, int>, int> Game::_transform_tiles_for_frontend()
{
    auto tiles = _model.get_tiles();
    int n = tiles.size();
    auto tiles_map = std::map<std::pair<int, int>, int>();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tiles_map[{i, j}] = tiles[i][j].index;
        }
    }

    return tiles_map;
}

void Game::_game_won(const Result &result)
{
    auto name = result.options.player_name;

    std::time_t tmp = std::chrono::system_clock::to_time_t(result.date);
    auto date = std::ctime(&tmp);

    auto seconds = result.elapsed_time % 60;
    auto minutes = result.elapsed_time / 60;
    auto hours = result.elapsed_time / 3600;

    char time_buf[9] = {0};
    std::snprintf(time_buf, 9, "%02d:%02d:%02d", hours, minutes, seconds);

    _view.show_congrats_window(name, {time_buf}, date);
}
