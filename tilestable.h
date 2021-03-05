#ifndef TILESTABLE_H
#define TILESTABLE_H

#include <vector>

#include "tile.h"

class TilesTable
{
public:
    TilesTable();

    void set_table_size(int size);
    void shuffle(int moves = 50); //TODO change magic number

    void print_state();

private:
    std::vector<std::vector<Tile>> _table;

    void _initialise_tiles();
    void _sort_tiles();
};

#endif // TILESTABLE_H
