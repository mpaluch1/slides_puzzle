#include "tilestable.h"

#include <algorithm>
#include <array>
#include <cstdlib>
#include <random>
#include <sstream>
#include <utility>

#include <spdlog/spdlog.h>

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
    spdlog::debug("Shuffling tiles in table");
    _sort_tiles();

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 3);

    auto empty_idx = _get_tile_with_index(-1);
    // for every move count
    while (moves--) {
        auto swapable = false;
        std::pair<int, int> swap_vec;
        auto new_row_idx = 0;
        auto new_col_idx = 0;

        while (!swapable) {
            // get random direction from generator
            auto rand_dir = dist(mt);
            swap_vec = _legal_dir_vecs[rand_dir];

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

tile_matrix TilesTable::get_tiles()
{
    return _table;
}

bool TilesTable::move_tile(int row, int col)
{
    const auto coords = _get_tile_with_index(-1);

    if (row < 0 || col < 0) {
        spdlog::debug("Invalid tile position {},{}", row, col);
        return false;
    }

    // if moved tile isn't next to empty then slot don't move
    const std::pair<int, int> vec =
            std::make_pair(std::abs(coords.first - row), std::abs(coords.second - col));

    auto result = std::find(std::begin(_legal_dir_vecs), std::end(_legal_dir_vecs), vec);
    if (result == std::end(_legal_dir_vecs)) {
        spdlog::warn("Can't move tile from {},{} to {},{}",
                     row, col, coords.first, coords.second);
        return false;
    }

    std::swap(_table[coords.first][coords.second], _table[row][col]);
    spdlog::debug("Moved tile from {},{} to {},{}",
                  row, col, coords.first, coords.second);
    return true;
}

bool TilesTable::is_solved()
{
    for (unsigned int i = 0;i < _table.size(); ++i) {
        for (unsigned int j = 0; j < _table[i].size(); ++j) {
            if (_table[i][j].index == -1) {
                continue;
            }

            int calc_idx = i * _table.size() + j;
            if (_table[i][j].index != calc_idx) {
                return false;
            }
        }
    }

    return true;
}

void TilesTable::print_state()
{
    spdlog::debug("State of tiles table:");
    for (unsigned i = 0; i < _table.size(); ++i) {  
        std::stringstream ss;
        for (unsigned j = 0; j < _table[i].size(); ++j) {
            ss << _table[i][j].index << ' ';
        }

        spdlog::debug(ss.str());
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

std::pair<int, int> TilesTable::_get_tile_with_index(int idx)
{
    for (unsigned i = 0; i < _table.size(); ++i) {
        for (unsigned j = 0; j < _table[i].size(); ++j) {
            if (_table[i][j].index == idx) {
                return std::make_pair(i, j);
            }
        }
    }

    return std::make_pair(-1, -1);
}
