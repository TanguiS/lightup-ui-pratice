#include "include/commandActions/undocommand.h"
#include "include/gameBoard/gameboardpresenter.h"
#include "include/commandActions/leftclickcommand.h"
#include "include/commandActions/rightclickcommand.h"

UndoCommand::UndoCommand( Command* lastCommand,GameBoardPresenter* presenter )
    : Command( presenter ),
      _lastCommand( lastCommand )
{
}

UndoCommand::~UndoCommand()
{
    delete _lastCommand;
}

void UndoCommand::execute()
{
    _lastCommand->execute();
    _lastCommand->execute();
}
