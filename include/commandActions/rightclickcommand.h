#ifndef RIGHTCLICKCOMMAND_H
#define RIGHTCLICKCOMMAND_H
#include "include/commandActions/command.h"
#include <QPoint>

class RightClickCommand : public Command
{
public:
    RightClickCommand(GameBoardPresenter* presenter, const QPoint& point);
    void execute() override;

private:
    const QPoint _point;
};

#endif // RIGHTCLICKCOMMAND_H
