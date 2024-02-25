#include "include/mapread/wallresponsabilitychainreader.h"
#include "include/cell/state/statewrapper.h"
#include "include/cell/state/wallstate.h"

WallResponsabilityChainReader::WallResponsabilityChainReader( AResponsabilityChainReader *nextResponsability )
    :AResponsabilityChainReader(nextResponsability)
{
}

QPair<StateWrapper *, backgroundType> WallResponsabilityChainReader::convertMapToWrapper(const QString &mapValue)
{
    if ( mapValue == "X" ) {
        return QPair<StateWrapper *, backgroundType>(new StateWrapper( new WallState() ), wall);
    } else if ( !this->hasNextResponsability() ) {
        return QPair<StateWrapper *, backgroundType>(nullptr, wall);
    }
    return this->handleStateWrapperFromNextChain( mapValue );
}
