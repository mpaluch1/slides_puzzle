#include "config.h"

#include <exception>
#include <fstream>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

struct ConfigNotFoundException: public std::exception {
    const char * what() const throw ()
    {
        return "Config file not found";
    }
};

Config::Config(const std::string &filename)
{
    std::ifstream in(filename);
    if (!in) {
        spdlog::error("Config file {} not found!", filename);
        throw ConfigNotFoundException();
    }

    nlohmann::json j;
    in >> j;

    problem_sizes = j["config"]["problem_sizes"].get<std::vector<int>>();
    results_view_count = j["config"]["results_view_count"].get<int>();
    results_view_headers = j["config"]["results_view_headers"].get<std::vector<std::string>>();
    results_filename = j["config"]["results_filename"].get<std::string>();
    default_shuffle_moves_count = j["config"]["default_shuffle_moves_count"].get<int>();
}
