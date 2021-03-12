#include "notificationbox.h"

#include "game.h"

NotificationBox::NotificationBox(Game &game)
    : _game(game)
{

}

void NotificationBox::notify_new_game(const std::string &player_name, int size)
{
    _game.new_game(player_name, size);
}

void NotificationBox::notify_renew_game()
{
    _game.renew_game();
}

void NotificationBox::notify_tile_clicked(int row, int column)
{
    _game.move_tile(row, column);
}

void NotificationBox::notify_show_results_table()
{
    _game.show_results_table();
}
