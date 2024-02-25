#ifndef GAMEBOARDWALLMANAGER_H
#define GAMEBOARDWALLMANAGER_H

#include <QObject>
#include <QSet>
#include "include/gameBoard/hashqpoint.h"

class StateWrapper;

class GameBoardWallManager : public QObject {
    Q_OBJECT
public:
    GameBoardWallManager(QObject* parent = nullptr);
    ~GameBoardWallManager();

public:
    bool areWallsValids();
    int numberValidWalls();
    int numberWallsToValidate() const;
    void updateWallsState( QHash<QPoint, StateWrapper *>& );
    QHash<QPoint,StateWrapper*>& items();
    void load( QHash<QPoint, StateWrapper *>& );

private:
    QHash<QPoint,StateWrapper*> _walls;
    QSet<StateWrapper*> _validWalls;

private:
    void destroy();
};

#endif // GAMEBOARDWALLMANAGER_H
