#ifndef CROSSCELL_H
#define CROSSCELL_H

#include "include/cell/decorator/celldecorator.h"

class CrossCell : public CellDecorator {
public:
    CrossCell( Cell* cell, const QColor &lineColor = QColor("#d8a7b1") );

    // cell interface
public:
    const QPixmap foreground() const override;
    ::foregroundType foregroundType() const override;
};

#endif // CROSSCELL_H
