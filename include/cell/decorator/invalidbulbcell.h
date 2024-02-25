#ifndef INVALIDBULBCELL_H
#define INVALIDBULBCELL_H

#include "include/cell/decorator/celldecorator.h"

class InvalidBulbCell : public CellDecorator {
public:
    InvalidBulbCell( Cell *cell, const QColor &lineColor = QColor("#d8a7b1") );

    // cell interface
public:
    const QPixmap foreground() const override;
    ::foregroundType foregroundType() const override;
};

#endif // INVALIDBULBCELL_H
