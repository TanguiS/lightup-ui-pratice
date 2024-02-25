#include "include/cell/decorator/numbercell.h"

#include <QPainter>
#include <QImage>

NumberCell::NumberCell(
        Cell *cell,
        const int number,
        const bool isValid,
        const QColor &lineColor) : CellDecorator(cell, lineColor), _number(number), _isValid(isValid), _image(QSize(500, 500), QImage::Format_ARGB32)
{
    QPainter painter;
    _image.fill(Qt::transparent);
    painter.begin(&_image);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(QFont("Arial", 500));
    if ( _isValid ) {
        painter.setPen(Qt::green);
    } else {
        painter.setPen(Qt::white);
    }
    painter.drawText(_image.rect(), Qt::AlignCenter, QString::number(_number));
    painter.end();
}

const QPixmap NumberCell::foreground() const
{
    return QPixmap::fromImage(_image);
}

foregroundType NumberCell::foregroundType() const
{
    return static_cast<::foregroundType>(2*_number+4+_isValid);
}

