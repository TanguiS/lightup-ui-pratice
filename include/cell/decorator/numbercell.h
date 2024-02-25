#ifndef NUMBERCELL_H
#define NUMBERCELL_H

#include "include/cell/decorator/celldecorator.h"
#include <QImage>

class NumberCell : public CellDecorator {
public:
    NumberCell(
            Cell *cell,
            const int number = 0,
            const bool isValid = false,
            const QColor &lineColor = QColor("#d8a7b1")
            );

    // cell interface
public:
    const QPixmap foreground() const override;
    ::foregroundType foregroundType() const override;

private:
    const int _number;
    const bool _isValid;
    QImage _image;
};

#endif // NUMBERCELL_H
