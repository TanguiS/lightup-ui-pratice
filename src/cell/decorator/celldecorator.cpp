#include "include/cell/decorator/celldecorator.h"
#include "include/cell/decorator/blankcell.h"
#include <QDebug>

CellDecorator::CellDecorator(Cell *cell,
                               const QColor &lineColor) : Cell(lineColor),
    _cell(cell)
{}

CellDecorator::~CellDecorator()
{
    delete  _cell;
}

const QColor CellDecorator::background() const
{
    return _cell->background();
}

const QPixmap CellDecorator::foreground() const
{
    return _cell->foreground();
}

backgroundType CellDecorator::backgroundType() const
{
    return _cell->backgroundType();
}

foregroundType CellDecorator::foregroundType() const
{
    return _cell->foregroundType();
}

void CellDecorator::removeAllDecoration()
{
    if ( dynamic_cast<CellDecorator*>(_cell) ) {
        dynamic_cast<CellDecorator*>(_cell)->removeAllDecoration();
    }
    delete _cell;
    _cell = new BlankCell();
}

