#include "resultstablesaver.h"

#include <chrono>
#include <fstream>

#include <spdlog/spdlog.h>

#include "resultstable.h"

ResultsTableSaver::ResultsTableSaver(const std::string &save_filename)
    : _filename{save_filename}
{

}

void ResultsTableSaver::update(const res_table_t &table)
{
    std::ofstream ofs(_filename, std::ios::out | std::ios::binary);

    if (!ofs) {
        spdlog::warn("Can't open results file!");
        return;
    }

    const auto to_save = _convert_to_json(table);
    ofs << to_save;

    spdlog::debug("Saved {} results to {}", _get_records_count(to_save), _filename);
}

res_table_t ResultsTableSaver::load()
{
    std::ifstream in(_filename);

    if (!in) {
        spdlog::warn("Couldn't load results table from {}", _filename);
        return {};
    }

    nlohmann::json j;
    in >> j;

    spdlog::debug("Loaded {} results from {}", _get_records_count(j), _filename);

    return _convert_from_json(j);
}

res_table_t ResultsTableSaver::_convert_from_json(const nlohmann::json &j)
{
    res_table_t results;

    for (auto& [size, results_dict] : j["results"].items()) {
        auto size_int = std::stoi(size);

        for (const auto &result : results_dict) {
            auto name = result["name"].get<std::string>();
            auto time = result["time"].get<int>();

            auto date = result["date"].get<std::time_t>();
            auto date_chrono = std::chrono::system_clock::from_time_t(date);

            results[size_int].emplace_back(time, date_chrono, GameOptions{name, size_int});
        }
    }

    return results;
}

nlohmann::json ResultsTableSaver::_convert_to_json(const res_table_t &table)
{
    nlohmann::json j;

    for (const auto &size_category : table) {
        auto size = size_category.first;
        nlohmann::json list_of_results = nlohmann::json::array();

        for (const auto &result : size_category.second) {
            nlohmann::json dict;

            dict["name"] = result.options.player_name;
            dict["time"] = result.elapsed_time;
            dict["date"] = std::chrono::system_clock::to_time_t(result.date);

            list_of_results.push_back(dict);
        }

        j["results"][std::to_string(size)] = list_of_results;
    }

    return j;
}

int ResultsTableSaver::_get_records_count(const nlohmann::json &j)
{
    auto counter = 0;

    for (const auto &size : j["results"].items()) {
        counter += size.value().size();
    }

    return counter;
}
