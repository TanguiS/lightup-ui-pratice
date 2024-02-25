#ifndef LIGHTCROSSSTATE_H
#define LIGHTCROSSSTATE_H

#include "statecell.h"

class LightedCrossState : public StateCell {
public:
    LightedCrossState();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // LIGHTCROSSSTATE_H
