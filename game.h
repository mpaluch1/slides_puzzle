#ifndef GAME_H
#define GAME_H

#include <map>
#include <memory>
#include <string>
#include <utility>

#include "backend.h"
#include "config.h"
#include "frontend.h"
#include "gameoptions.h"

class Result;

class Game
{
public:
    Game(const Config &config);
    void start();

    void new_game(const std::string &name, int size);
    void renew_game();
    void move_tile(int row, int column);
    void show_results_table();
    void show_results(int problem_size);

private:
    const Config _config;

    std::shared_ptr<NotificationBox> _box;
    Frontend _view;
    Backend _model;
    std::unique_ptr<GameOptions> _cached_options;

    std::map<std::pair<int, int>, std::string> _transform_tiles_for_frontend();
    void _game_won(const Result &result);
    std::string _time_from_seconds(int secs);
    result_view_t _get_n_best_results(std::vector<Result> &results, int n);
};

#endif // GAME_H
