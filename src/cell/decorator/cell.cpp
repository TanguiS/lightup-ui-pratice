#include "include/cell/decorator/cell.h"

#include <QPen>
#include <QPainter>

Cell::Cell(const QColor &lineColor) : _lineColor(lineColor)
{}

Cell::~Cell(){}

const QColor &Cell::lineColor() const {
    return _lineColor;
}
