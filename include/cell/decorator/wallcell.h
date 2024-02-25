#ifndef WALLCELL_H
#define WALLCELL_H

#include "include/cell/decorator/celldecorator.h"

class WallCell : public CellDecorator {
public:
    WallCell( Cell *cell, const QColor &lineColor = QColor("#d8a7b1") );

    // cell interface
public:
    const QColor background() const override;
    ::backgroundType backgroundType() const override;
};

#endif // WALLCELL_H
