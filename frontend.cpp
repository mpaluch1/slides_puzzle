#include "frontend.h"

Frontend::Frontend(const std::vector<int> &sizes)
    : _new_game_window(sizes)
    , _results_window(sizes)
{

}

void Frontend::start()
{
    _new_game_window.set_notification_box(_box);
    _main_window.set_notification_box(_box);
    _congrats_window.set_notification_box(_box);
    _results_window.set_notification_box(_box);

    _main_window.hide();
    _congrats_window.hide();

    _new_game_window.show();
}

void Frontend::show_game_window()
{
    _new_game_window.hide();
    _congrats_window.hide();
    _main_window.show();
}

void Frontend::display_tiles(const std::map<std::pair<int, int>, std::string> &tiles)
{
    _main_window.display_tiles(tiles);
}

void Frontend::show_congrats_window(const std::string &name, const std::string &time, const std::string &date)
{
    _main_window.hide();
    _congrats_window.set_result(name, time, date);
    _congrats_window.show();
}

void Frontend::show_results_window()
{
    _results_window.show();
}

void Frontend::show_results(const result_view_t &to_show)
{
    _results_window.show_results(to_show);
}
