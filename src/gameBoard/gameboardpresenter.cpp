#include "include/gameBoard/gameboardpresenter.h"

#include <QPoint>
#include <QDebug>
#include "include/gameBoard/gameboardmodel.h"
#include "include/mapread/mapreader.h"
#include "include/commandActions/switchcommand.h"
#include "include/commandActions/leftclickcommand.h"
#include "include/commandActions/rightclickcommand.h"

GameBoardPresenter::GameBoardPresenter(GameBoardModel &model, MapReader& map, SwitchCommand& handlercommand,QObject *parent)
    : QObject(parent),
      _model(model),
      _map(map),
      _handlerCommand( handlercommand )
{
    connect(&_model, &GameBoardModel::loaded, this, [=](){
        emit loaded();
        double percentage = ((double)_model.numberLightedCells() /(double)_model.numberCells())*100.0;
        emit lightedPercentage(QString::number(percentage, 'f', 1) + " %");
        percentage = ((double)_model.numberValidWalls() /(double)_model.numberWallsToValidate())*100.0;
        emit validatedWallPercentage(QString::number(percentage, 'f', 1) + " %");
        _handlerCommand.clearCommands();
        emit numberBackTracks( QString::number(_handlerCommand.getNumberUndo() ) );
    });
    connect( &_map, &MapReader::sendHashs, &_model, &GameBoardModel::load );
}

void GameBoardPresenter::leftClick(const QPoint &clicked)
{
    _model.leftClicked(clicked);
    emit notify();
    double percentage = ((double)_model.numberLightedCells() /(double)_model.numberCells())*100.0;
    emit lightedPercentage(QString::number(percentage, 'f', 1) + " %");
    percentage = ((double)_model.numberValidWalls() /(double)_model.numberWallsToValidate())*100.0;
    emit validatedWallPercentage(QString::number(percentage, 'f', 1) + " %");
}

void GameBoardPresenter::rightClick(const QPoint &clicked)
{
    _model.rightCliked(clicked);
    qInfo() << "lighted number : " << _model.numberLightedCells() << " Wall : " << _model.numberValidWalls();
    qInfo() << "number cells : " << _model.numberCells() << " number wall to validate : " << _model.numberWallsToValidate();
    emit notify();
    double percentage = ((double)_model.numberLightedCells() /(double)_model.numberCells())*100.0;
    emit lightedPercentage(QString::number(percentage, 'f', 1) + " %");
    percentage = ((double)_model.numberValidWalls() /(double)_model.numberWallsToValidate())*100.0;
    emit validatedWallPercentage(QString::number(percentage, 'f', 1) + " %");
}

QHash<QPoint, StateWrapper *> GameBoardPresenter::cells()
{
    return _model.cells();
}

QHash<QPoint, StateWrapper *> GameBoardPresenter::walls()
{
    return _model.walls();
}

int GameBoardPresenter::numberWCell() const
{
    return _model.numberWCell();
}

void GameBoardPresenter::submit() const
{

}

void GameBoardPresenter::loadNewMap() const
{
    _map.shuffleMap();
    emit sendLockingPage();
}

void GameBoardPresenter::changeSize(const QString &size)
{
    _map.setSize( size );
}

void GameBoardPresenter::changeDifficulty(const int &difficulty)
{
    _map.setDifficulty( difficulty );
}

void GameBoardPresenter::communication() const
{
    if (_model.isGameWin()) {
    emit wonGame();
    } else {
        emit notWonGame();
    }
}

void GameBoardPresenter::emitResetSignal()const
{
    _map.emitHashSignal();
}

void GameBoardPresenter::handleLeftClick(QPoint point)
{
    _handlerCommand.addCommand( new LeftClickCommand(this, point) );
    _handlerCommand.execute();
}

void GameBoardPresenter::handleRightClick(QPoint point)
{
    _handlerCommand.addCommand( new RightClickCommand(this, point) );
    _handlerCommand.execute();
}

void GameBoardPresenter::handleUndo()
{
    _handlerCommand.undo();
    emit numberBackTracks( QString::number(_handlerCommand.getNumberUndo() ) );
}
