#include "include/cell/state/statecell.h"
#include "include/cell/decorator/blankcell.h"

StateCell::StateCell(Cell *cell) : _cell(cell)
{}

StateCell::~StateCell()
{
    delete _cell;
}

void StateCell::leftClick()
{
    _state->leftClick();
}

void StateCell::rightClick()
{
    _state->rightClick();
}

Cell *StateCell::stateProperties() const
{
    return _cell;
}

void StateCell::setContext(StateWrapper *context)
{
    _context = context;
}

StateWrapper *StateCell::context()
{
    return _context;
}

