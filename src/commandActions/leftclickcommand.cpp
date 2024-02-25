#include "include/commandActions/leftclickcommand.h"
#include "include/gameBoard/gameboardpresenter.h"

LeftClickCommand::LeftClickCommand(GameBoardPresenter* presenter, const QPoint& point)
    : Command( presenter ),
      _point( point )
{
}
void LeftClickCommand::execute()
{
    getPresenter()->leftClick( _point );
}

