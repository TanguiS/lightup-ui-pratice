#ifndef LEFTCLICKCOMMAND_H
#define LEFTCLICKCOMMAND_H
#include "include/commandActions/command.h"
#include <QPoint>

class LeftClickCommand : public Command
{
public:
    LeftClickCommand(GameBoardPresenter* presenter, const QPoint& point);
    void execute() override;

private:
    const QPoint _point;
};

#endif // LEFTCLICKCOMMAND_H
