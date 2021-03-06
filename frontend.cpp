#include "frontend.h"

Frontend::Frontend()
{

}

void Frontend::start()
{
    _new_game_window.set_notification_box(_box);
    _main_window.set_notification_box(_box);
    _new_game_window.show();
}

void Frontend::show_game_window()
{
    _new_game_window.hide();
    _main_window.show();
}

void Frontend::display_tiles(const std::map<std::pair<int, int>, int> &tiles)
{
    _main_window.display_tiles(tiles);
}
