#ifndef GAME_H
#define GAME_H

#include <map>
#include <memory>
#include <string>
#include <utility>

#include "backend.h"
#include "frontend.h"
#include "gameoptions.h"

class Result;

class Game
{
public:
    Game();
    void start();

    void new_game(const std::string &name, int size);
    void renew_game();
    void move_tile(int row, int column);

private:
    std::shared_ptr<NotificationBox> _box;
    Frontend _view;
    Backend _model;
    std::unique_ptr<GameOptions> _cached_options;

    std::map<std::pair<int, int>, int> _transform_tiles_for_frontend();
    void _game_won(const Result &result);
};

#endif // GAME_H
