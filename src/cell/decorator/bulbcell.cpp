#include "include/cell/decorator/bulbcell.h"

#include <QPixmap>

BulbCell::BulbCell(Cell *cell, const QColor &lineColor) : CellDecorator(cell, lineColor)
{}

const QPixmap BulbCell::foreground() const
{
    return QPixmap(":images/icons/light.png");
}

foregroundType BulbCell::foregroundType() const
{
    return ::validLightBulb;
}

