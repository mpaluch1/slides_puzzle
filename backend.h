#ifndef BACKEND_H
#define BACKEND_H

#include <memory>

#include "gameoptions.h"
#include "gamestate.h"
#include "resultstable.h"
#include "tilestable.h"

class Result;

class Backend
{
public:
    Backend();

    void start_new_game(const GameOptions &options);
    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();
    Result save_result();

private:
    std::unique_ptr<GameState> _state;
    ResultsTable _results_table;
};

#endif // BACKEND_H
