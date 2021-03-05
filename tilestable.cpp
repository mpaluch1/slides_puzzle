#include "tilestable.h"

#include <array>
#include <iostream>
#include <random>
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

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    const std::array<std::pair<int, int>, 4> dir_vecs = {{
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0}
    }};

    auto empty_idx = _find_empty_slot();
    // for every move count
    while (moves--) {
        auto swapable = false;
        std::pair<int, int> swap_vec;
        auto new_row_idx = 0;
        auto new_col_idx = 0;

        while (!swapable) {
            // get random direction from generator
            auto rand_dir = dist(mt);
            swap_vec = dir_vecs[rand_dir];

            new_row_idx = empty_idx.first + swap_vec.first;
            new_col_idx = empty_idx.second + swap_vec.second;

            // if not applicable, get again
            if ((new_row_idx < static_cast<int>(_table.size()) && new_row_idx >= 0)
                && (new_col_idx < static_cast<int>(_table.size()) && new_col_idx >= 0)) {
                swapable = true;
            }
        }

        // swap empty slot and selected tile
        std::swap(
            _table[empty_idx.first][empty_idx.second],
            _table[new_row_idx][new_col_idx]
        );
        empty_idx = {new_row_idx, new_col_idx};
    }
    print_state();
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

std::pair<int, int> TilesTable::_find_empty_slot()
{
    for (unsigned i = 0; i < _table.size(); ++i) {
        for (unsigned j = 0; j < _table[i].size(); ++j) {
            if (_table[i][j].index == -1) {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}
