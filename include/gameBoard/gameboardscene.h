#ifndef GAMEBOARDSCENE_H
#define GAMEBOARDSCENE_H

#include <QGraphicsScene>
#include "include/gameBoard/hashqpoint.h"

class QWidget;
class QRectF;
class GameBoardPresenter;
class StateWrapper;
class CellView;

class GameBoardScene : public QGraphicsScene {
public:
    GameBoardScene(GameBoardPresenter& gamePresenter, const QSize viewSize, QObject *parent = nullptr);
    ~GameBoardScene();

public:
    void updateSize( const QSize& );

private:
    int widthRect( const QSize& ) const;
    void updateComponent();

private:
    GameBoardPresenter& _presenter;
    const int _whmargin;
    const int _refSize;
    CellView *addCell(QHash<QPoint, StateWrapper *>::ConstIterator current);
};

#endif // GAMEBOARDSCENE_H
