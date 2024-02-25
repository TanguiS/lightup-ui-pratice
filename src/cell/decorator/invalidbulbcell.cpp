#include "include/cell/decorator/invalidbulbcell.h"

#include <QPixmap>

InvalidBulbCell::InvalidBulbCell(Cell *cell, const QColor &lineColor) : CellDecorator(cell, lineColor)
{}

const QPixmap InvalidBulbCell::foreground() const
{
    return QPixmap(":images/icons/red_light.png");
}

foregroundType InvalidBulbCell::foregroundType() const
{
    return ::invalidLightBulb;
}

