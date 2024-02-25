#include "include/cell/decorator/lightcell.h"

LightCell::LightCell(Cell* cell, const QColor &lineColor) : CellDecorator(cell, lineColor)
{}

const QColor LightCell::background() const
{
    return QColor("#feedc3");
}

backgroundType LightCell::backgroundType() const
{
    return ::lighted;
}
