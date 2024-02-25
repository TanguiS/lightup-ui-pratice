#include "include/gameBoard/gameboardmodel.h"

#include <QDebug>
#include "include/cell/state/blankstate.h"
#include "include/cell/state/wallstate.h"
#include "include/cell/state/wallnumberstate.h"
#include "include/cell/state/statewrapper.h"
#include "include/gameBoard/gameboardview.h"
#include "include/gameBoard/gameboardcellmanager.h"
#include "include/gameBoard/gameboardwallmanager.h"
#include <math.h>

GameBoardModel::GameBoardModel(int numberWCell) : _numberWCell(numberWCell), _cellsModel(new GameBoardCellManager()), _wallsModel(new GameBoardWallManager())
{
    //initializeGrid();
}

GameBoardModel::~GameBoardModel()
{
    delete _cellsModel;
    delete  _wallsModel;
}

int GameBoardModel::numberWCell() const
{
    return _numberWCell;
}

void GameBoardModel::leftClicked(QPoint clickedField)
{
    _cellsModel->leftClick(clickedField);
    updateCellGame(clickedField);
}

void GameBoardModel::rightCliked(QPoint clickedField)
{
    _cellsModel->rightClick(clickedField);
    updateCellGame(clickedField);
}

int GameBoardModel::numberLightedCells()
{
    return _cellsModel->numberLightedCells();
}

int GameBoardModel::numberCells() const
{
    return _cellsModel->numberCells();
}

int GameBoardModel::numberValidWalls()
{
    return _wallsModel->numberValidWalls();
}

int GameBoardModel::numberWallsToValidate() const
{
    return _wallsModel->numberWallsToValidate();
}

const QHash<QPoint, StateWrapper *>& GameBoardModel::cells() const
{
    return _cellsModel->items();
}

const QHash<QPoint, StateWrapper *>& GameBoardModel::walls() const
{
    return _wallsModel->items();
}

void GameBoardModel::load(QHash<QPoint, StateWrapper *>& cells, QHash<QPoint, StateWrapper *>& walls)
{
    _cellsModel->load(cells);
    _wallsModel->load(walls);
    _numberWCell = (int)sqrt(cells.size() + walls.size());
    emit loaded();
}

void GameBoardModel::updateCellGame(QPoint clickedField)
{
    _cellsModel->updateLightsEffects(clickedField);
    _cellsModel->updateInvalidLightBulb();
    _wallsModel->updateWallsState(_cellsModel->items());
}

bool GameBoardModel::isGameWin()
{
    return _wallsModel->areWallsValids() && _cellsModel->areCellsValids();
}

void GameBoardModel::initializeGrid()
{
    QHash<QPoint, StateWrapper*> walls;
    QHash<QPoint, StateWrapper*> grid;
    for (int row = 0; row < _numberWCell; row++) {
        for (int col = 0; col < _numberWCell; col++) {
            if ( row == 1 && col == 1) {
                walls.insert(QPoint(row, col), new StateWrapper(new WallState()));
            } else if ( row == 3 && col == 3 ) {
                walls.insert(QPoint(row, col), new StateWrapper(new WallState()));
            } else if ( row == 2 && col == 1 ) {
                walls.insert(QPoint(row, col), new StateWrapper(new WallNumberState(0)));
            } else {
                grid.insert(QPoint(row, col), new StateWrapper(new BlankState()));
            }
        }
    }
}

bool isBlankField(StateWrapper &toEvaluate)
{
    return toEvaluate.backgroundType() == ::blank;
}

bool isLightedField(StateWrapper &toEvaluate)
{
    return toEvaluate.backgroundType() == ::lighted;
}

bool isBulb(StateWrapper &toEvaluate)
{
    return toEvaluate.foregroundType() == ::invalidLightBulb || toEvaluate.foregroundType() == ::validLightBulb;
}

bool isInvalidBulb(StateWrapper &toEvaluate)
{
    return toEvaluate.foregroundType() == ::invalidLightBulb;
}

bool isWallValid(StateWrapper &toEvaluate)
{
    return static_cast<int>(toEvaluate.foregroundType())%2 == 1;
}

bool isNumberWall(StateWrapper &toEvaluate)
{
    return toEvaluate.foregroundType() != ::none;
}
