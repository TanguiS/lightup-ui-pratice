#ifndef WALLNUMBERSTATE_H
#define WALLNUMBERSTATE_H

#include "wallstate.h"

class WallNumberState : public WallState {
public:
    WallNumberState(int number);

    // StateCell interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;

    int number() const override;

private:
    const int _number;
};

#endif // WALLNUMBERSTATE_H
