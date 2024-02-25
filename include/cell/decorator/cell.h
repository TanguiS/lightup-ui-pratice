#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QPixmap>

#include "include/cell/cellcomponent.h"

class Cell {
public:
    Cell( const QColor &lineColor = QColor("#d8a7b1") );
    virtual ~Cell();

public:
    virtual const QColor background() const = 0;
    virtual const QPixmap foreground() const = 0;
    virtual enum::backgroundType backgroundType() const = 0;
    virtual enum::foregroundType foregroundType() const = 0;
    const QColor &lineColor() const;

private:
    const QColor _lineColor;
};

#endif // CELL_H
