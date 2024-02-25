#ifndef LIGHTCELL_H
#define LIGHTCELL_H

#include "include/cell/decorator/celldecorator.h"

class LightCell : public CellDecorator {
public:
    LightCell( Cell* cell, const QColor &lineColor = QColor("#d8a7b1") );

    // cell interface
public:
    const QColor background() const override;
    ::backgroundType backgroundType() const override;
};

#endif // LIGHTCELL_H
