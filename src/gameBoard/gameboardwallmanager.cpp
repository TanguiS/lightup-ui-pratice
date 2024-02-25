#include "include/gameBoard/gameboardwallmanager.h"

#include "include/cell/cellcomponent.h"
#include "include/cell/state/statewrapper.h"
#include "include/gameBoard/gameboardmodel.h"

GameBoardWallManager::GameBoardWallManager(QObject *parent) : QObject(parent), _validWalls()
{}

GameBoardWallManager::~GameBoardWallManager()
{
    destroy();
}

bool GameBoardWallManager::areWallsValids()
{
    for (QHash<QPoint, StateWrapper*>::Iterator it = _walls.begin(); it != _walls.end(); it++) {
        if (it.value()->foregroundType() == ::none) {
            continue;
        }
        if (!isWallValid(*it.value())) {
            return false;
        }
    }
    return true;
}

int GameBoardWallManager::numberValidWalls()
{
    return _validWalls.size();
}

int GameBoardWallManager::numberWallsToValidate() const
{
    int count = 0;
    for (auto wall : _walls) {
        if ( isNumberWall(*wall) ) {
            count++;
        }
    }
    return count;
}

void GameBoardWallManager::updateWallsState(QHash<QPoint, StateWrapper*>& cells)
{
    static const QPoint directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for ( QHash<QPoint, StateWrapper*>::Iterator it = _walls.begin(); it != _walls.end(); it++ ) {
        const QPoint& wallPos = it.key();
        StateWrapper* wallState = it.value();
        int valid = 0;
        const foregroundType fgType = wallState->foregroundType();
        for (const QPoint& dir : directions) {
            const QPoint current = wallPos + dir;
            if (cells.contains(current) && isBulb(*cells[current])) {
                ++valid;
            }
        }
        const int expectedValid = (static_cast<int>(fgType) - 4) / 2;
        const bool isValid = valid == expectedValid;
        if (isValid) {
            _validWalls.insert(wallState);
        } else {
            _validWalls.remove(wallState);
        }
        if (isValid != isWallValid(*wallState)) {
            wallState->update();
        }
    }
}

QHash<QPoint, StateWrapper *>& GameBoardWallManager::items()
{
    return _walls;
}

void GameBoardWallManager::load(QHash<QPoint, StateWrapper *>& walls)
{
    destroy();
    _walls.clear();
    _walls = walls;
    _validWalls.clear();
}

void GameBoardWallManager::destroy()
{
    for (QHash<QPoint, StateWrapper*>::Iterator current = _walls.begin(); current != _walls.end(); current++) {
        delete current.value();
    }
}
