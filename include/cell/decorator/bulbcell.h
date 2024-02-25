#ifndef BULBCELL_H
#define BULBCELL_H

#include "include/cell/decorator/celldecorator.h"

class BulbCell : public CellDecorator {
public:
    BulbCell( Cell *cell, const QColor &lineColor = QColor("#d8a7b1") );


    // cell interface
public:
    const QPixmap foreground() const override;
    ::foregroundType foregroundType() const override;
};

#endif // BULBCELL_H
