#ifndef INVALIDBULBSTATE_H
#define INVALIDBULBSTATE_H

#include "statecell.h"

class InvalidBulbState : public StateCell {
public:
    InvalidBulbState();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // INVALIDBULBSTATE_H
