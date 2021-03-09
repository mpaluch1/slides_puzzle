#ifndef TILESTABLE_H
#define TILESTABLE_H

#include <array>
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
    bool move_tile(int row, int col);

    void print_state();

private:
    tile_matrix _table;
    const std::array<std::pair<int, int>, 4> _legal_dir_vecs = {{
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0}
    }};

    void _initialise_tiles();
    void _sort_tiles();
    std::pair<int, int> _get_tile_with_index(int idx);

};

#endif // TILESTABLE_H
