#ifndef BULBSTATE_H
#define BULBSTATE_H

#include "statecell.h"

class BulbState : public StateCell {
public:
    BulbState();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // BULBSTATE_H
