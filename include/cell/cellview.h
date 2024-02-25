#ifndef CELLVIEW_H
#define CELLVIEW_H

#include <QGraphicsRectItem>
#include <QPoint>

#include "include/cell/cellcomponent.h"

class CellView : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    CellView(QColor lineColor,
              QColor backgroundColor,
              QPixmap backgroundPixImage,
              ::backgroundType backgroundType,
              ::foregroundType backgroundPixType,
              QPoint anchor,
              QGraphicsItem *parent = nullptr);

public:
    QPoint anchor() const;
    void update(QColor, QPixmap, ::backgroundType, ::foregroundType);

    // QGraphicsItem interface
public:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

signals:
    void rightClicked(QPoint anchor);
    void leftClicked(QPoint anchor);

private:
    const QColor _lineColor;
    QColor _backgroundColor;
    ::backgroundType _backgroundType;
    ::foregroundType _backgroundPixType;
    const QPoint _anchor;
    QPixmap _backgroundPixImage;


    // QGraphicsItem interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* ) override;
};

#endif // CELLVIEW_H
