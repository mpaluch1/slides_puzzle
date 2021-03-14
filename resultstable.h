#ifndef RESULTSTABLE_H
#define RESULTSTABLE_H

#include <map>
#include <vector>

#include "result.h"
#include "resultstablesaver.h"

using res_table_t = std::map<int, std::vector<Result>>;

class ResultsTable
{
public:
    ResultsTable(const std::string &res_filename);

    void add(const Result &result);
    std::vector<Result> get(int problem_size);

private:
    res_table_t _table;
    ResultsTableSaver _saver;
};

#endif // RESULTSTABLE_H
