#ifndef STATECELL_H
#define STATECELL_H

#include "include/cell/decorator/cell.h"

class StateWrapper;

class StateCell {
public:
    StateCell(Cell* cell);
    virtual ~StateCell();

public:
    virtual void leftClick() = 0;
    virtual void rightClick() = 0;
    virtual void update() = 0;
    Cell* stateProperties() const;
    void setContext(StateWrapper* );

protected:
    StateWrapper* context();

private:
    Cell* _cell;
    StateCell* _state;
    StateWrapper* _context;


};

#endif // STATECELL_H
