#include "tilestable.h"

#include <iostream>
#include <utility>

TilesTable::TilesTable()
{

}

void TilesTable::set_table_size(int size)
{
    _table.resize(size);
    for (auto &column : _table) {
        column.resize(size);
    }

    _initialise_tiles();
    print_state();
}

void TilesTable::shuffle(int moves)
{
    _sort_tiles();

    // for every move count
    // find empty slot
    // get random direction from generator
    // if not applicable, get again
    // swap empty slot and selected tile
}

void TilesTable::print_state()
{
    for (unsigned i = 0; i < _table.size(); ++i) {
        for (unsigned j = 0; j < _table[i].size(); ++j) {
            std::cout << _table[i][j].index << ' ';
        }

        std::cout << std::endl;
    }
}

void TilesTable::_initialise_tiles()
{
    for (unsigned int i = 0;i < _table.size(); ++i) {
        for (unsigned int j = 0; j < _table[i].size(); ++j) {
            _table[i][j].index = i * _table.size() + j;
        }
    }

    // last tile is empty
    _table.back().back().index = -1;
}

void TilesTable::_sort_tiles()
{
    for (unsigned i = 0; i < _table.size(); ++i) {
        for (unsigned j = 0; j < _table[i].size(); ++j) {
            if (_table[i][j].index == -1) {
                continue;
            }

            auto row = _table[i][j].index / _table.size();
            auto column = _table[i][j].index % _table.size();

            if (row != i || column != j) {
                std::swap(_table[i][j], _table[row][column]);
            }
        }
    }
}
