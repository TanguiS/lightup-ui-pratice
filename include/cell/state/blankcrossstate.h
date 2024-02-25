#ifndef BLANKCROSSSTATE_H
#define BLANKCROSSSTATE_H

#include "statecell.h"

class BlankCrossCell : public StateCell {
public:
    BlankCrossCell();

    // StateField interface
public:
    void leftClick() override;
    void rightClick() override;
    void update() override;
};

#endif // BLANKCROSSSTATE_H
