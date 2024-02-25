#include "include/mapread/blankresponsabilitychainreader.h"
#include "include/cell/state/blankstate.h"
#include "include/cell/state/statewrapper.h"

BlankResponsabilityChainReader::BlankResponsabilityChainReader( AResponsabilityChainReader *nextResponsability )
    : AResponsabilityChainReader( nextResponsability )
{

}

QPair<StateWrapper *, backgroundType> BlankResponsabilityChainReader::convertMapToWrapper(const QString &mapValue)
{
    if ( mapValue == "." ) {
        return QPair<StateWrapper *, backgroundType>(new StateWrapper( new BlankState() ), blank);
    } else if ( !this->hasNextResponsability() ) {
        return QPair<StateWrapper *, backgroundType>(nullptr, blank);
    }
    return this->handleStateWrapperFromNextChain( mapValue );
}
