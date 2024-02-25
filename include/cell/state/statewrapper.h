#ifndef STATEWRAPPER_H
#define STATEWRAPPER_H

#include "include/cell/decorator/cell.h"

class StateCell;

class StateWrapper : public Cell {
public:
    StateWrapper(StateCell* state);
    ~StateWrapper();

public:
    void transition(StateCell* );
    void leftClick();
    void rightClick();
    void update();

    // cell interface
public:
    const QColor background() const override;
    const QPixmap foreground() const override;
    ::backgroundType backgroundType() const override;
    ::foregroundType foregroundType() const override;

private:
    StateCell* _state;
};

#endif // STATEWRAPPER_H
