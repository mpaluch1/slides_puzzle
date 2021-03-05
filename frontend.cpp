#include "frontend.h"

Frontend::Frontend()
{

}

void Frontend::start()
{
    _new_game_window.set_notification_box(_box);
    _new_game_window.show();
}

