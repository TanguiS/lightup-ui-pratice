#ifndef WALLSTATE_H
#define WALLSTATE_H

#include "include/cell/state/statecell.h"

class WallState : public StateCell {
public:
    WallState();

protected:
    WallState(Cell *cell);

public:
    virtual int number() const;

    // StateCell interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // WALLSTATE_H
