#ifndef GAMEBOARDPRESENTER_H
#define GAMEBOARDPRESENTER_H

#include <QObject>
#include "include/gameBoard/hashqpoint.h"

class SwitchCommand;
class MapReader;
class StateWrapper;
class GameBoardModel;

class GameBoardPresenter : public QObject {
    Q_OBJECT
public:
    GameBoardPresenter(
            GameBoardModel& model,
            MapReader& map,
            SwitchCommand& handlercommand,
            QObject *parent = nullptr
            );

public:
    void leftClick( const QPoint& );
    void rightClick( const QPoint& );
    QHash<QPoint, StateWrapper*> cells();
    QHash<QPoint, StateWrapper*> walls();
    int numberWCell() const;

public slots:
    void changeSize( const QString & );
    void changeDifficulty( const int & );
    void submit() const;
    void loadNewMap()const;
    void emitResetSignal()const;
    void handleLeftClick( QPoint );
    void handleRightClick( QPoint );
    void handleUndo();
    void communication() const;

signals:
    void notify() const;
    void wonGame() const;
    void notWonGame() const;
    void loaded() const;
    void lightedPercentage( const QString& ) const;
    void validatedWallPercentage( const QString& ) const;
    void numberBackTracks( const QString& ) const;
    void sendLockingPage() const;

private:
    GameBoardModel& _model;
    MapReader& _map;
    SwitchCommand& _handlerCommand;
};

#endif // GAMEBOARDPRESENTER_H
