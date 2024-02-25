#include "include/cell/cellview.h"

#include <QPainter>
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CellView::CellView(
        QColor lineColor,
        QColor backgroundColor,
        QPixmap backgroundPixImage,
        ::backgroundType backgroundType,
        ::foregroundType backgroundPixType,
        QPoint anchor,
        QGraphicsItem *parent
        ) : QGraphicsRectItem(parent),
            _lineColor(lineColor),
            _backgroundColor(backgroundColor),
            _backgroundType(backgroundType),
            _backgroundPixType(backgroundPixType),
            _anchor(anchor),
            _backgroundPixImage(backgroundPixImage)

{
    setPen(QPen(_lineColor, 2));
}

QPoint CellView::anchor() const
{
    return _anchor;
}

void CellView::update(QColor backgroundColor, QPixmap backgroundPixImage, ::backgroundType backgroundType, ::foregroundType backgroundPixType)
{
    _backgroundColor = backgroundColor;
    _backgroundPixImage = backgroundPixImage;
    _backgroundType = backgroundType;
    _backgroundPixType = backgroundPixType;
}

void CellView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->fillRect(boundingRect(), _backgroundColor);
    if (_backgroundPixType != ::none) {
        const int margin = boundingRect().size().width()*0.1;
        const QRectF wMargin = boundingRect().adjusted(margin, margin, -margin, -margin);
        painter->drawPixmap(wMargin, _backgroundPixImage, _backgroundPixImage.rect());
    }
    painter->drawRect(boundingRect());
}

void CellView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if ( _backgroundType == ::wall ) {
        return;
    }
    if ( event->button() == Qt::RightButton ) {
        emit rightClicked(_anchor);
    } else {
        emit leftClicked(_anchor);
    }
    QGraphicsRectItem::mousePressEvent(event);
}
