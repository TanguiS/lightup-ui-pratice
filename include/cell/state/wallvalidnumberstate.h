#ifndef WALLVALIDNUMBERSTATE_H
#define WALLVALIDNUMBERSTATE_H

#include "wallstate.h"

class WallValidNumberState : public WallState {
public:
    WallValidNumberState(int number);

    // StateCell interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;

    int number() const override;

private:
    const int _number;
};

#endif // WALLVALIDNUMBERSTATE_H
