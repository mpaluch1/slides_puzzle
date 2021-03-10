#include "notificationbox.h"

#include "game.h"

NotificationBox::NotificationBox(Game &game)
    : _game(game)
{

}

void NotificationBox::notify_new_game(const std::string &player_name, int size, bool renew)
{
    _game.new_game(player_name, size, renew);
}

void NotificationBox::notify_tile_clicked(int row, int column)
{
    _game.move_tile(row, column);
}
