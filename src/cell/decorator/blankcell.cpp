#include "include/cell/decorator/blankcell.h"

#include <QPainter>
#include <QImage>

BlankCell::BlankCell(const QColor &lineColor) : Cell(lineColor)
{}

const QColor BlankCell::background() const
{
    return QColor("#fffdf8");
}

const QPixmap BlankCell::foreground() const
{
    return QPixmap();
}

backgroundType BlankCell::backgroundType() const
{
    return ::blank;
}

foregroundType BlankCell::foregroundType() const
{
    return ::none;
}
