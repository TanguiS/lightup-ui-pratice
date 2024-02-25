#include "include/gameBoard/gameboardcellmanager.h"

#include "include/cell/state/statewrapper.h"
#include "include/gameBoard/gameboardmodel.h"
#include <QDebug>
#include <QSet>

GameBoardCellManager::GameBoardCellManager(QObject *parent) : QObject(parent), _numberLightedCells(0)
{}

GameBoardCellManager::~GameBoardCellManager()
{
    destroy();
}

void GameBoardCellManager::leftClick(QPoint &clickedField)
{
    _cells[clickedField]->leftClick();
}

void GameBoardCellManager::rightClick(QPoint &clickedField)
{
    _cells[clickedField]->rightClick();
}

bool GameBoardCellManager::areCellsValids()
{
    for (QHash<QPoint, StateWrapper*>::Iterator it = _cells.begin(); it != _cells.end(); it++) {
        if (!isLightedField(*it.value()) || isInvalidBulb(*it.value())) {
            return false;
        }
    }
    return true;
}

int GameBoardCellManager::numberLightedCells() const
{
    return _numberLightedCells + _lightedEffect.size();
}

int GameBoardCellManager::numberCells() const
{
    return _cells.size();
}

QVector<QPoint> GameBoardCellManager::lightEffect(QPoint clikedField)
{
    QVector<QPoint> unlighted;
    if (!isBulb(*_cells[clikedField])) {
        unlighted = _lightedEffect[clikedField];
        _lightedEffect.remove(clikedField);
        return unlighted;
    }
    QVector<QPoint> effect;
    static QPoint directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const QPoint& dir : directions) {
        QPoint current = clikedField + dir;
        while (_cells.contains(current)) {
            effect.append(current);
            current += dir;
        }
    }
    _lightedEffect.insert(clikedField, effect);
    return unlighted;
}

void GameBoardCellManager::unlightCell(QVector<QPoint> unlighted)
{
    for (QVector<QPoint>::Iterator it = unlighted.begin(); it != unlighted.end(); it++) {
        if (!isLightedField(*_cells[*it]) || isBulb(*_cells[*it])) {
            continue;
        }
        _numberLightedCells--;
        _cells[*it]->update();
    }
}

void GameBoardCellManager::updateLightsEffects(QPoint &clikedField)
{
    QVector<QPoint> unlighted = lightEffect(clikedField);
    unlightCell(unlighted);
    for ( QHash<QPoint, QVector<QPoint>>::Iterator it = _lightedEffect.begin(); it != _lightedEffect.end(); it++ ) {
        for ( QVector<QPoint>::Iterator itv = it.value().begin(); itv != it.value().end(); itv++ ) {
            if (isLightedField(*_cells[*itv])) {
                continue;
            }
            _numberLightedCells++;
            _cells[*itv]->update();
        }
    }
}

void GameBoardCellManager::updateInvalidLightBulb()
{
    QSet<StateWrapper*> errs;
    for (auto it = _lightedEffect.begin(); it != _lightedEffect.end(); it++) {
        for (auto v_it = it.value().begin(); v_it != it.value().end(); v_it++ ) {
            if (*v_it != it.key() && _lightedEffect.contains(*v_it)) {
                errs.insert(_cells[it.key()]);
                errs.insert(_cells[*v_it]);
            }
        }
        if (!errs.contains(_cells[it.key()]) && isInvalidBulb(*_cells[it.key()])) {
            _cells[it.key()]->update();
        }
    }
    for (auto err : errs) {
        if (isInvalidBulb(*err)) {
            continue;
        }
        err->update();
    }
}

QHash<QPoint, StateWrapper *>& GameBoardCellManager::items()
{
    return _cells;
}

void GameBoardCellManager::load(QHash<QPoint, StateWrapper *>& cells)
{
    destroy();
    _cells.clear();
    _cells = cells;
    _lightedEffect.clear();
    _numberLightedCells = 0;
}

void GameBoardCellManager::destroy()
{
    if (_cells.size() == 0 ) {
        return;
    }
    for (QHash<QPoint, StateWrapper*>::Iterator current = _cells.begin(); current != _cells.end(); current++) {
        delete current.value();
    }

}
