#ifndef GAMEBOARDCELLMANAGER_H
#define GAMEBOARDCELLMANAGER_H

#include <QObject>
#include "include/gameBoard/hashqpoint.h"

class StateWrapper;

class GameBoardCellManager : public QObject {
    Q_OBJECT
public:
    GameBoardCellManager( QObject *parent = nullptr );
    ~GameBoardCellManager();

public:
    void leftClick( QPoint& );
    void rightClick( QPoint& );
    bool areCellsValids();
    int numberLightedCells() const;
    int numberCells() const;
    void updateLightsEffects( QPoint& );
    void updateInvalidLightBulb();
    QHash<QPoint,StateWrapper*>& items();
    void load( QHash<QPoint, StateWrapper*>& );

private:
    QHash<QPoint,StateWrapper*> _cells;
    QHash<QPoint, QVector<QPoint>> _lightedEffect;
    int _numberLightedCells;

private:
    void destroy();
    QVector<QPoint> lightEffect( QPoint );
    void unlightCell( QVector<QPoint> );
};

#endif // GAMEBOARDCELLMANAGER_H
