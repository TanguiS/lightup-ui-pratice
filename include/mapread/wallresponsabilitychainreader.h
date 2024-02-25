#ifndef WALLRESPONSABILITYCHAINREADER_H
#define WALLRESPONSABILITYCHAINREADER_H

#include "include/mapread/AResponsabilityChainReader.h"

class WallResponsabilityChainReader : public AResponsabilityChainReader
{
public:
    WallResponsabilityChainReader( AResponsabilityChainReader *nextResponsability = nullptr );
    QPair<StateWrapper *, backgroundType> convertMapToWrapper(const QString &mapValue);
};

#endif // WALLRESPONSABILITYCHAINREADER_H
