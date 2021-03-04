#include "backend.h"

Backend::Backend()
{

}

void Backend::start_new_game(const GameOptions &options)
{
    _state = std::make_unique<GameState>(options);
}
