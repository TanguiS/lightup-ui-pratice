#ifndef ARESPONSABILITYCHAINREADER_H
#define ARESPONSABILITYCHAINREADER_H

#include <QString>
#include <QPair>
#include "include/cell/cellcomponent.h"
class StateWrapper;

class AResponsabilityChainReader {

public:
    AResponsabilityChainReader( AResponsabilityChainReader *nextResponsability = nullptr );
    virtual ~AResponsabilityChainReader();
    virtual QPair<StateWrapper *, backgroundType> convertMapToWrapper( const QString &mapValue )=0;

protected:
    QPair<StateWrapper *, backgroundType> handleStateWrapperFromNextChain( const QString &mapValue );
    bool hasNextResponsability();


private:
    AResponsabilityChainReader *_nextResponsability;
};



#endif // ARESPONSABILITYCHAINREADER_H
