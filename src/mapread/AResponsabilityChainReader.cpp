#include "include/mapread/AResponsabilityChainReader.h"


AResponsabilityChainReader::AResponsabilityChainReader( AResponsabilityChainReader *nextResponsability )
    : _nextResponsability(nextResponsability)
{
}

AResponsabilityChainReader::~AResponsabilityChainReader()
{
    delete _nextResponsability;
}

QPair<StateWrapper *, backgroundType> AResponsabilityChainReader::handleStateWrapperFromNextChain(const QString &mapValue)
{
    return _nextResponsability->convertMapToWrapper( mapValue );
}

bool AResponsabilityChainReader::hasNextResponsability()
{
    return _nextResponsability != nullptr;
}
