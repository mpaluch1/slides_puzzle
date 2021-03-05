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
}
