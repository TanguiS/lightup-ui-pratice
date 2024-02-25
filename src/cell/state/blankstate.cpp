#include "include/cell/state/blankstate.h"

#include "include/cell/state/invalidbulbstate.h"
#include "include/cell/state/bulbstate.h"
#include "include/cell/state/lightstate.h"
#include "include/cell/state/blankcrossstate.h"
#include "include/cell/decorator/blankcell.h"
#include "include/cell/state/statewrapper.h"

BlankState::BlankState() : StateCell(new BlankCell())
{}

void BlankState::leftClick()
{
    StateCell::context()->transition(new BulbState());
}

void BlankState::rightClick()
{
    StateCell::context()->transition(new BlankCrossCell());
}

void BlankState::update()
{
    StateCell::context()->transition(new LightState());
}


