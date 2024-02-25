#include "include/cell/state/lightstate.h"

#include "include/cell/decorator/lightcell.h"
#include "include/cell/decorator/blankcell.h"
#include "include/cell/state/invalidbulbstate.h"
#include "include/cell/state/bulbstate.h"
#include "include/cell/state/lightcrossstate.h"
#include "include/cell/state/blankstate.h"
#include "include/cell/state/statewrapper.h"

LightState::LightState() : StateCell(new LightCell(new BlankCell()))
{}

void LightState::leftClick()
{
    StateCell::context()->transition(new InvalidBulbState());
}

void LightState::rightClick()
{
    StateCell::context()->transition(new LightedCrossState());
}

void LightState::update()
{
    StateCell::context()->transition(new BlankState());
}
