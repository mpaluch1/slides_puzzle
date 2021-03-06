#ifndef TILESTABLE_H
#define TILESTABLE_H

#include <vector>
#include <utility>

#include "tile.h"

using tile_matrix = std::vector<std::vector<Tile>>;

class TilesTable
{
public:
    TilesTable();

    void set_table_size(int size);
    void shuffle(int moves = 50); //TODO change magic number
    tile_matrix get_tiles();

    void print_state();

private:
    tile_matrix _table;

    void _initialise_tiles();
    void _sort_tiles();
    std::pair<int, int> _find_empty_slot();

};

#endif // TILESTABLE_H
