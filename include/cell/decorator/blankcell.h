#ifndef BLANKCELL_H
#define BLANKCELL_H

#include "include/cell/decorator/cell.h"

class BlankCell : public Cell {
public:
    BlankCell( const QColor &lineColor = QColor("#d8a7b1") );

    // cell interface
public:
    const QColor background() const override;
    const QPixmap foreground() const override;
    ::backgroundType backgroundType() const override;
    ::foregroundType foregroundType() const override;
};

#endif // BLANKCELL_H
