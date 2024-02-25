#include "include/commandActions/command.h"
#include <QPoint>
#include "include/gameBoard/gameboardpresenter.h"

Command::Command( GameBoardPresenter* presenter)
    : _presenter(presenter)
{
}

Command::~Command()
{

}

GameBoardPresenter* Command::getPresenter() const
{
    return _presenter;
}
