#include "game.h"

#include <spdlog/spdlog.h>

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

void Game::new_game(const std::string &name, int size)
{
    spdlog::info("Creating new game with name {} and size {}", name, size);
    auto options = GameOptions(name, size);
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
        // TODO show gratulations window
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
