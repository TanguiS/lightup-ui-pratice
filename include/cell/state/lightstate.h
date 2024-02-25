#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

#include "statecell.h"

class LightState : public StateCell {
public:
    LightState();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // LIGHTSTATE_H
