#include "include/gameBoard/gameboardscene.h"
#include "include/cell/cellview.h"
#include "include/gameBoard/gameboardpresenter.h"
#include "include/cell/state/statewrapper.h"
#include <QDebug>
#include <QWidget>

GameBoardScene::GameBoardScene(GameBoardPresenter& gamePresenter, const QSize viewSize, QObject *parent)
    : QGraphicsScene(parent),
      _presenter(gamePresenter),
      _whmargin(50),
      _refSize(widthRect(viewSize))
{
    const QHash<QPoint, StateWrapper*>& cells = _presenter.cells();
    connect(&_presenter, &GameBoardPresenter::notify, this, &GameBoardScene::updateComponent);
    for ( QHash<QPoint, StateWrapper*>::ConstIterator current = cells.cbegin(); current != cells.cend(); current++ ) {
        CellView* item = addCell(current);
        connect(item, &CellView::rightClicked, &_presenter, &GameBoardPresenter::handleRightClick);
        connect(item, &CellView::leftClicked, &_presenter, &GameBoardPresenter::handleLeftClick);
    }
    const QHash<QPoint, StateWrapper*>& walls = _presenter.walls();
    for ( QHash<QPoint, StateWrapper*>::ConstIterator current = walls.cbegin(); current != walls.cend(); current++ ) {
        addCell(current);
    }
}

GameBoardScene::~GameBoardScene()
{}

CellView* GameBoardScene::addCell(QHash<QPoint, StateWrapper*>::ConstIterator current)
{
    CellView* item = new CellView(current.value()->lineColor(),
                                    current.value()->background(),
                                    current.value()->foreground(),
                                    current.value()->backgroundType(),
                                    current.value()->foregroundType(),
                                    current.key());
    item->setRect(current.key().x() * _refSize + 1, current.key().y() * _refSize + 1, _refSize - 2, _refSize - 2);
    addItem(item);
    return item;
}

int GameBoardScene::widthRect(const QSize &newSize) const
{
    return ((newSize.width() > newSize.height() ? newSize.height() : newSize.width()) - _whmargin) / _presenter.numberWCell();
}

void GameBoardScene::updateComponent()
{
    QList<CellView*> fieldViews;
    foreach (QGraphicsItem* item, QGraphicsScene::items()) {
        CellView* fieldView = dynamic_cast<CellView*>(item);
        const Cell* newField = _presenter.cells().value(fieldView->anchor());
        if (newField == nullptr) {
            newField = _presenter.walls().value(fieldView->anchor());
        }
        fieldView->update(newField->background(), newField->foreground(), newField->backgroundType(), newField->foregroundType());
    }
    QGraphicsScene::update();
}

void GameBoardScene::updateSize(const QSize& newSize)
{
    QList<CellView*> fieldViews;
    static QPoint anchor(0, 0);
    const int size = widthRect(newSize);
    foreach (QGraphicsItem* item, QGraphicsScene::items()) {
        item->setScale((double)size / (double)_refSize);
    }
    QSize sceneSize(size * _presenter.numberWCell(), size * _presenter.numberWCell());
    setSceneRect(QRectF(anchor, sceneSize));
    QGraphicsScene::update();
}
