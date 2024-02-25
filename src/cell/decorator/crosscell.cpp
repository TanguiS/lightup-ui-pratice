#include "include/cell/decorator/crosscell.h"

#include <QPixmap>

CrossCell::CrossCell(Cell* cell, const QColor &lineColor) : CellDecorator(cell, lineColor)
{}

const QPixmap CrossCell::foreground() const
{
    return QPixmap(":images/icons/cross.png");
}

foregroundType CrossCell::foregroundType() const
{
    return ::cross;
}


