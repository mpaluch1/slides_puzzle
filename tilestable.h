#ifndef TILESTABLE_H
#define TILESTABLE_H

#include <vector>

#include "tile.h"

class TilesTable
{
public:
    TilesTable();

    void set_table_size(int size);

private:
    std::vector<std::vector<Tile>> _table;
};

#endif // TILESTABLE_H
