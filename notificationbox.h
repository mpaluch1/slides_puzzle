#ifndef NOTIFICATIONBOX_H
#define NOTIFICATIONBOX_H

#include <string>

class Game;

class NotificationBox
{
public:
    NotificationBox(Game &game);

    void notify_new_game(const std::string &player_name, int size);
    void notify_renew_game();
    void notify_tile_clicked(int row, int column);

private:
    Game &_game;
};

#endif // NOTIFICATIONBOX_H
