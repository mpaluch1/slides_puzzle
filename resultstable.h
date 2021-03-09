#ifndef RESULTSTABLE_H
#define RESULTSTABLE_H

#include <map>
#include <vector>

#include "result.h"

using res_table_t = std::map<int, std::vector<Result>>;

class ResultsTable
{
public:
    ResultsTable();

    void add(const Result &result);

private:
    res_table_t _table;
};

#endif // RESULTSTABLE_H
