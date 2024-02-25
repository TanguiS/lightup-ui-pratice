#include "include/cell/state/lightcrossstate.h"

#include "include/cell/decorator/blankcell.h"
#include "include/cell/decorator/crosscell.h"
#include "include/cell/decorator/lightcell.h"
#include "include/cell/state/lightstate.h"
#include "include/cell/state/invalidbulbstate.h"
#include "include/cell/state/statewrapper.h"
#include "include/cell/state/blankcrossstate.h"

LightedCrossState::LightedCrossState() : StateCell(new CrossCell(new LightCell(new BlankCell())))
{}

void LightedCrossState::leftClick()
{
    StateCell::context()->transition(new LightState());
}

void LightedCrossState::rightClick()
{
    StateCell::context()->transition(new InvalidBulbState());
}

void LightedCrossState::update()
{
    StateCell::context()->transition(new BlankCrossCell());
}
