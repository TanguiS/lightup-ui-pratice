#include "include/cell/state/statewrapper.h"

#include "include/cell/state/statecell.h"

StateWrapper::StateWrapper(StateCell *state) : _state(nullptr)
{
    transition(state);
}

StateWrapper::~StateWrapper()
{
    delete _state;
}

void StateWrapper::transition(StateCell *state)
{
    delete _state;
    _state = state;
    _state->setContext(this);
}

void StateWrapper::leftClick()
{
    _state->leftClick();
}

void StateWrapper::rightClick()
{
    _state->rightClick();
}

void StateWrapper::update()
{
    _state->update();
}

const QColor StateWrapper::background() const
{
    return _state->stateProperties()->background();
}

const QPixmap StateWrapper::foreground() const
{
    return _state->stateProperties()->foreground();
}

backgroundType StateWrapper::backgroundType() const
{
    return _state->stateProperties()->backgroundType();
}

foregroundType StateWrapper::foregroundType() const
{
    return _state->stateProperties()->foregroundType();
}
