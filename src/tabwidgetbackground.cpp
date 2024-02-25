#include "include/tabwidgetbackground.h"

#include <QtMath>
#include <QPainter>
#include <QDebug>

TabWidgetBackground::TabWidgetBackground(QWidget *parent) : QTabWidget(parent)
{}

void TabWidgetBackground::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPixmap patternPixmap = QPixmap(":/images/pattern-px.png").scaledToHeight(100, Qt::SmoothTransformation);

    QSize tabSize = size();

    int horizontalTiles = qCeil(static_cast<qreal>(tabSize.width()) / patternPixmap.width());
    int verticalTiles = qCeil(static_cast<qreal>(tabSize.height()) / patternPixmap.height());
    QPixmap tiledPixmap(horizontalTiles * patternPixmap.width(), verticalTiles * patternPixmap.height());
    QPainter painter(&tiledPixmap);
    for (int x = 0; x < horizontalTiles; ++x) {
        for (int y = 0; y < verticalTiles; ++y) {
            painter.drawPixmap(x * patternPixmap.width(), y * patternPixmap.height(), patternPixmap);
        }
    }

    QPainter widgetPainter(this);
    widgetPainter.drawPixmap(rect(), tiledPixmap);
}
