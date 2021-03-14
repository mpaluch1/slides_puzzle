#ifndef BACKEND_H
#define BACKEND_H

#include <vector>
#include <memory>

#include "gameoptions.h"
#include "gamestate.h"
#include "resultstable.h"
#include "tilestable.h"

class Result;

class Backend
{
public:
    Backend(const std::string &res_filename);

    void start_new_game(const GameOptions &options, int shuffle_count);
    tile_matrix get_tiles();
    bool move_tile(int row, int col);
    bool is_solved();
    Result save_result();
    std::vector<Result> get_result_table(int problem_size);
    void set_picture(const std::string &path);

private:
    std::unique_ptr<GameState> _state;
    ResultsTable _results_table;
};

#endif // BACKEND_H
