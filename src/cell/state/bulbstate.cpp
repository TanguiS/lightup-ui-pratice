#include "include/cell/state/bulbstate.h"

#include "include/cell/decorator/bulbcell.h"
#include "include/cell/decorator/lightcell.h"
#include "include/cell/decorator/blankcell.h"
#include "include/cell/state/invalidbulbstate.h"
#include "include/cell/state/blankcrossstate.h"
#include "include/cell/state/blankstate.h"
#include "include/cell/state/statewrapper.h"

BulbState::BulbState() : StateCell(new BulbCell(new LightCell(new BlankCell())))
{}

void BulbState::leftClick()
{
    StateCell::context()->transition(new BlankCrossCell());
}

void BulbState::rightClick()
{
    StateCell::context()->transition(new BlankState());
}

void BulbState::update()
{
    StateCell::context()->transition(new InvalidBulbState());
}
