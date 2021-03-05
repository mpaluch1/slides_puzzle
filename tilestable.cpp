#include "tilestable.h"

TilesTable::TilesTable()
{

}

void TilesTable::set_table_size(int size)
{
    _table.resize(size);
    for (auto &column : _table) {
        column.resize(size);
    }
}
