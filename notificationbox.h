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
    void notify_restart_game();
    void notify_tile_clicked(int row, int column);
    void notify_show_results_table();
    void notify_show_results(int problem_size);
    void notify_change_picture(const std::string &new_pic);

private:
    Game &_game;
};

#endif // NOTIFICATIONBOX_H
