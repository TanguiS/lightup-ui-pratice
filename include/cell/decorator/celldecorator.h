#ifndef CELLDECORATOR_H
#define CELLDECORATOR_H

#include "include/cell/decorator/cell.h"

class CellDecorator : public Cell {
public:
    CellDecorator( Cell* cell, const QColor &lineColor = QColor("#d8a7b1") );
    virtual ~CellDecorator();

    // cell interface
public:
    const QColor background() const override;
    const QPixmap foreground() const override;
    enum::backgroundType backgroundType() const override;
    enum::foregroundType foregroundType() const override;
    void removeAllDecoration();

private:
    Cell* _cell;
};

#endif // CELLDECORATOR_H
