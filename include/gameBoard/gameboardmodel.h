#ifndef GAMEBOARDMODEL_H
#define GAMEBOARDMODEL_H

#include <QObject>
#include "include/gameBoard/hashqpoint.h"

class GameBoardCellManager;
class GameBoardWallManager;
class StateWrapper;

class GameBoardModel : public QObject {
    Q_OBJECT
public:
    GameBoardModel(int numberWCell);
    ~GameBoardModel();

public:
    int numberWCell() const;
    void leftClicked( QPoint );
    void rightCliked( QPoint );
    int numberLightedCells();
    int numberCells() const;
    int numberValidWalls();
    int numberWallsToValidate() const;
    bool isGameWin();
    const QHash<QPoint, StateWrapper*>& cells() const;
    const QHash<QPoint, StateWrapper*>& walls() const;

public slots:
    void load( QHash<QPoint, StateWrapper*>& , QHash<QPoint, StateWrapper*>& );

signals:
    void loaded() const;

private:
    int _numberWCell;
    GameBoardCellManager* _cellsModel;
    GameBoardWallManager* _wallsModel;

private:
    void initializeGrid();
    void updateCellGame( QPoint );
};

bool isNumberWall( StateWrapper& );

bool isBlankField( StateWrapper& );

bool isLightedField( StateWrapper& );

bool isBulb( StateWrapper& );

bool isInvalidBulb( StateWrapper& );

bool isWallValid( StateWrapper& );

#endif // GAMEBOARDMODEL_H
