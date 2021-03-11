#ifndef RESULTSTABLESAVER_H
#define RESULTSTABLESAVER_H

#include <string>

#include <nlohmann/json.hpp>

#include "result.h"

using res_table_t = std::map<int, std::vector<Result>>;

class ResultsTableSaver
{
public:
    // TODO get def name from config
    ResultsTableSaver(const std::string &save_filename = ".results.json");

    void update(const res_table_t &table);
    res_table_t load();

private:
    std::string _filename;

    nlohmann::json _convert_to_json(const res_table_t &table);
    res_table_t _convert_from_json(const nlohmann::json &j);
    int _get_records_count(const nlohmann::json &j);
};

#endif // RESULTSTABLESAVER_H
