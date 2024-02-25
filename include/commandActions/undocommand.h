#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H
#include "include/commandActions/command.h"

class QPoint;

class UndoCommand : public Command
{
public:
    UndoCommand( Command* lastCommand, GameBoardPresenter* presenter = nullptr );
    ~UndoCommand();
    void execute() override;

private:
    Command* _lastCommand;
};

#endif // UNDOCOMMAND_H
