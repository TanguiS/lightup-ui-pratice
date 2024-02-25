#include "include/mapread/wallnumberresponsabilitychainreader.h"
#include "include/cell/state/statewrapper.h"
#include "include/cell/state/wallnumberstate.h"


WallNumberResponsabilityChainReader::WallNumberResponsabilityChainReader( AResponsabilityChainReader *nextResponsability )
    :AResponsabilityChainReader(nextResponsability)
{
}


QPair<StateWrapper *, backgroundType> WallNumberResponsabilityChainReader::convertMapToWrapper(const QString &mapValue)
{
    bool isNumber;
    int number = mapValue.toInt( &isNumber );
    if ( isNumber ) {
        return QPair<StateWrapper *, backgroundType>(new StateWrapper( new WallNumberState( number ) ), wall);
    } else if ( !this->hasNextResponsability() ) {
        return QPair<StateWrapper *, backgroundType>(nullptr, wall);
    }
    return this->handleStateWrapperFromNextChain( mapValue );
}
