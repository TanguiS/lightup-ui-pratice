#ifndef BLANKSTATE_H
#define BLANKSTATE_H

#include "statecell.h"

class BlankState : public StateCell {
public:
    BlankState();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // BLANKSTATE_H
