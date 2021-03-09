#include "resultstable.h"

#include <ctime>

#include <spdlog/spdlog.h>

ResultsTable::ResultsTable()
{

}

void ResultsTable::add(const Result &result)
{
    std::time_t tmp = std::chrono::system_clock::to_time_t(result.date);
    spdlog::info("Added result with name {}, duration {} and date {} to results table",
                 result.options.player_name,
                 result.elapsed_time,
                 std::ctime(&tmp)
                 );

    auto size = result.options.problem_size;
    _table[size].push_back(result);
}
