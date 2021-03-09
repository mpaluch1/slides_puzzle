#ifndef BACKEND_H
#define BACKEND_H

#include <memory>

#include "gameoptions.h"
#include "gamestate.h"
#include "tilestable.h"

class Backend
{
public:
    Backend();

    void start_new_game(const GameOptions &options);
    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();

private:
    std::unique_ptr<GameState> _state;
};

#endif // BACKEND_H
