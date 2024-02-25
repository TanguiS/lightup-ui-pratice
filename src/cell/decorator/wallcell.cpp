#include "include/cell/decorator/wallcell.h"

WallCell::WallCell(Cell *cell, const QColor &lineColor) : CellDecorator(cell, lineColor)
{}

const QColor WallCell::background() const
{
    return Qt::black;
}

backgroundType WallCell::backgroundType() const
{
    return ::wall;
}

