#include "include/commandActions/rightclickcommand.h"
#include "include/gameBoard/gameboardpresenter.h"

RightClickCommand::RightClickCommand(GameBoardPresenter* presenter, const QPoint& point)
    : Command( presenter ),
      _point( point )
{
}

void RightClickCommand::execute()
{
    getPresenter()->rightClick( _point );
}
