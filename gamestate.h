#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameoptions.h"
#include "tilestable.h"

class GameState
{
public:
    GameState(const GameOptions &options);

private:
    GameOptions _options;
    TilesTable _tiles_table;
};

#endif // GAMESTATE_H
