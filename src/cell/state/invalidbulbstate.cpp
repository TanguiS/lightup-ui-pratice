#include "include/cell/state/invalidbulbstate.h"

#include "include/cell/decorator/blankcell.h"
#include "include/cell/decorator/invalidbulbcell.h"
#include "include/cell/decorator/lightcell.h"
#include "include/cell/state/lightcrossstate.h"
#include "include/cell/state/lightstate.h"
#include "include/cell/state/bulbstate.h"
#include "include/cell/state//statewrapper.h"

InvalidBulbState::InvalidBulbState() : StateCell(new InvalidBulbCell(new LightCell(new BlankCell())))
{}

void InvalidBulbState::leftClick()
{
    StateCell::context()->transition(new LightedCrossState());
}

void InvalidBulbState::rightClick()
{
    StateCell::context()->transition(new LightState());
}

void InvalidBulbState::update()
{
    StateCell::context()->transition(new BulbState());
}
