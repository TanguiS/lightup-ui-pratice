#ifndef SWITCHCOMMAND_H
#define SWITCHCOMMAND_H
#include <QHash>
#include <QVector>
#include <QPoint>
#include <QPair>
class Command;

class SwitchCommand
{
public:
    SwitchCommand();
    ~SwitchCommand();
    void addCommand( Command* command );
    void execute();
    void undo();
    int getNumberUndo() const;
    void clearCommands();

private :
    QVector<Command*> _history;
    int _numberUndo;
};

#endif // SWITCHCOMMAND_H
