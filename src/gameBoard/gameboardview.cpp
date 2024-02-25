#include "include/gameBoard/gameboardview.h"

#include "include/gameBoard/gameboardscene.h"
#include <QResizeEvent>

GameBoardView::GameBoardView(QWidget *parent) : QGraphicsView(parent)
{}

void GameBoardView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    if (dynamic_cast<GameBoardScene*>(scene())) {
        dynamic_cast<GameBoardScene*>(scene())->updateSize(event->size());
    }
}

