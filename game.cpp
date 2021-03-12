#include "game.h"

#include <algorithm>
#include <chrono>
#include <string>

#include <spdlog/spdlog.h>

#include "result.h"

Game::Game()
{
    _box = std::make_shared<NotificationBox>(*this);
}

void Game::start()
{
    spdlog::info("Starting game");

    _view.set_notification_box(_box);
    _view.start();
}

void Game::new_game(const std::string &name, int size)
{
    spdlog::info("Creating new game with name {} and size {}", name, size);

    auto options = GameOptions(name, size);
    _cached_options = std::make_unique<GameOptions>(options);

    _model.start_new_game(options);
    _view.show_game_window();
    _view.display_tiles(_transform_tiles_for_frontend());
}

void Game::renew_game()
{
    if (!_cached_options) {
        spdlog::error("Trying to renew game without first start!");
        return;
    }

    spdlog::info("Recreating game with name {} and size {}",
                 _cached_options->player_name, _cached_options->problem_size);

    _model.start_new_game(*_cached_options);
    _view.show_game_window();
    _view.display_tiles(_transform_tiles_for_frontend());
}

void Game::move_tile(int row, int column)
{
    spdlog::debug("Moving tile at {},{}", row, column);

    auto moved = _model.move_tile(row, column);
    if (!moved) {
        return;
    }

    _view.display_tiles(_transform_tiles_for_frontend());
    auto solved = _model.is_solved();
    if (solved) {
        spdlog::info("Solved!");
        auto result = _model.save_result();
        _game_won(result);
    }
}

void Game::show_results_table()
{
    spdlog::debug("Showing results window");
    _view.show_results_window();
}

void Game::show_results(int problem_size)
{
    const auto results_count = 10; // TODO get from config
    spdlog::debug("Showing {} results with problem size {}", results_count, problem_size);

    auto results = _model.get_result_table(problem_size);
    auto res_to_show = _get_n_best_results(results, results_count);

    _view.show_results(res_to_show);
}

std::map<std::pair<int, int>, int> Game::_transform_tiles_for_frontend()
{
    auto tiles = _model.get_tiles();
    int n = tiles.size();
    auto tiles_map = std::map<std::pair<int, int>, int>();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tiles_map[{i, j}] = tiles[i][j].index;
        }
    }

    return tiles_map;
}

void Game::_game_won(const Result &result)
{
    auto name = result.options.player_name;
    auto date = result.date_to_string();

    _view.show_congrats_window(name, _time_from_seconds(result.elapsed_time), date);
}

std::string Game::_time_from_seconds(int secs)
{
    auto seconds = secs % 60;
    auto minutes = (secs / 60) % 60;
    auto hours = secs / 3600;
    char time_buf[9] = {0};

    std::snprintf(time_buf, 9, "%02d:%02d:%02d", hours, minutes, seconds);

    return {time_buf};
}

result_view_t Game::_get_n_best_results(std::vector<Result> &results, int n)
{
    if (n > static_cast<int>(results.size())) {
        n = results.size();
    }

    std::sort(results.begin(), results.end(), [](auto &l, auto &r) {
        return l.elapsed_time < r.elapsed_time;
    });

    result_view_t ret;
    ret.push_back({"Pozycja", "Czas", "Gracz", "Data"}); // TODO config?

    // transform vector of Result objects to vector of string arrays
    auto counter = 1;
    std::transform(results.begin(), results.begin()+n, std::back_inserter(ret),
        [&counter, this](auto &res) {
            auto position = std::to_string(counter++);
            auto time = _time_from_seconds(res.elapsed_time);
            auto name = res.options.player_name;
            auto date = res.date_to_string();

            std::array<std::string, 4> arr{position, time, name, date};
            return arr;
        }
    );

    return ret;
}
