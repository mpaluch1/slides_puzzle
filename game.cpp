#include "game.h"

Game::Game()
    : _box{std::make_shared<NotificationBox>(*this)}
{

}

void Game::start()
{
    _frontend.set_notification_box(_box);
    _frontend.start();
}
