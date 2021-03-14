#include "resultstable.h"

#include <ctime>

#include <spdlog/spdlog.h>

ResultsTable::ResultsTable(const std::string &res_filename)
    : _saver{res_filename}
{
    _table = _saver.load();
}

void ResultsTable::add(const Result &result)
{
    spdlog::info("Added result with name {}, duration {} and date {} to results table",
                 result.options.player_name,
                 result.elapsed_time,
                 result.date_to_string()
                 );

    auto size = result.options.problem_size;
    _table[size].push_back(result);

    _saver.update(_table);
}

std::vector<Result> ResultsTable::get(int problem_size)
{
    return _table[problem_size];
}
