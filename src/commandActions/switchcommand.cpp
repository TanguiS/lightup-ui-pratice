#include "include/commandActions/switchcommand.h"
#include "include/commandActions/command.h"
#include "include/commandActions/undocommand.h"
SwitchCommand::SwitchCommand()
{
    _numberUndo = 0;
}

SwitchCommand::~SwitchCommand()
{
    for ( auto it : _history ) {
        delete it;
    }
    _history.clear();
}

void SwitchCommand::addCommand( Command* command )
{
    _history.append( command );
    if ( _history.size() > 20 ) {
        _history.removeFirst();
    }
}

void SwitchCommand::execute()
{
    _history.last()->execute();
}

void SwitchCommand::undo()
{
    if ( !_history.empty() ) {
        Command* command = _history.last();
        UndoCommand undo(command);
        undo.execute();
        _history.removeLast();
        _numberUndo++;
    }

}

int SwitchCommand::getNumberUndo() const
{
    return _numberUndo;
}

void SwitchCommand::clearCommands()
{
    for ( auto it : _history ) {
        delete it;
    }
    _history.clear();
    _numberUndo = 0;
}

