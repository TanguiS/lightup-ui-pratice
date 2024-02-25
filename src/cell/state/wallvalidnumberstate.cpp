#include "include/cell/state/wallvalidnumberstate.h"

#include "include/cell/state/statecell.h"
#include "include/cell/decorator/wallcell.h"
#include "include/cell/decorator/numbercell.h"
#include "include/cell/decorator/blankcell.h"
#include "include/cell/state/wallnumberstate.h"
#include "include/cell/state/statewrapper.h"

WallValidNumberState::WallValidNumberState(int number) : WallState(new NumberCell(new WallCell(new BlankCell()), number, true)), _number(number)
{}

void WallValidNumberState::leftClick()
{}

void WallValidNumberState::rightClick()
{}

void WallValidNumberState::update()
{
    StateCell::context()->transition(new WallNumberState(_number));
}

int WallValidNumberState::number() const
{
    return _number;
}
