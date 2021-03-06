#include "game.h"

Game::Game()
{
    _box = std::make_shared<NotificationBox>(*this);
}

void Game::start()
{
    _view.set_notification_box(_box);
    _view.start();
}

void Game::new_game(const std::string &name, int size)
{
    auto options = GameOptions(name, size);
    _model.start_new_game(options);

    // get tiles and show them
    _view.show_game_window();
    _view.display_tiles(_transform_tiles_for_frontend());
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
