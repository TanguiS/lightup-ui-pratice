#include "include/cell/state/wallnumberstate.h"

#include "include/cell/decorator/wallcell.h"
#include "include/cell/decorator/numbercell.h"
#include "include/cell/decorator/blankcell.h"
#include "include/cell/state/wallvalidnumberstate.h"
#include "include/cell/state/statewrapper.h"

WallNumberState::WallNumberState(int number) : WallState(new NumberCell(new WallCell(new BlankCell()), number)), _number(number)
{}

void WallNumberState::leftClick()
{}

void WallNumberState::rightClick()
{}

void WallNumberState::update()
{
    StateCell::context()->transition(new WallValidNumberState(_number));
}

int WallNumberState::number() const
{
    return _number;
}
