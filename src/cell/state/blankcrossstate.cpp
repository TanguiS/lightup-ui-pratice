#include "include/cell/state/blankcrossstate.h"

#include "include/cell/decorator/blankcell.h"
#include "include/cell/decorator/crosscell.h"
#include "include/cell/state/blankstate.h"
#include "include/cell/state/bulbstate.h"
#include "include/cell/state/lightcrossstate.h"
#include "include/cell/state/statewrapper.h"

BlankCrossCell::BlankCrossCell() : StateCell(new CrossCell(new BlankCell()))
{}

void BlankCrossCell::leftClick()
{
    StateCell::context()->transition(new BlankState());
}

void BlankCrossCell::rightClick()
{
    StateCell::context()->transition(new BulbState());
}

void BlankCrossCell::update()
{
    StateCell::context()->transition(new LightedCrossState());
}
