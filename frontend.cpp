#include "frontend.h"

Frontend::Frontend()
    : _new_game_window(std::make_unique<NewGameWindow>())
{

}

void Frontend::start()
{
    _new_game_window->show();
}
