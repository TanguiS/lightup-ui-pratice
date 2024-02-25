#include "include/cell/state/wallstate.h"

#include "include/cell/decorator/blankcell.h"
#include "include/cell/decorator/wallcell.h"

WallState::WallState() : StateCell(new WallCell(new BlankCell()))
{}

WallState::WallState(Cell *cell) : StateCell(cell)
{}

int WallState::number() const
{
    return -1;
}

void WallState::leftClick()
{}

void WallState::rightClick()
{}

void WallState::update()
{}
