#ifndef WALLNUMBERRESPONSABILITYCHAINREADER_H
#define WALLNUMBERRESPONSABILITYCHAINREADER_H
#include "include/mapread/AResponsabilityChainReader.h"

class WallNumberResponsabilityChainReader : public AResponsabilityChainReader
{
public:
    WallNumberResponsabilityChainReader( AResponsabilityChainReader *nextResponsability = nullptr );
    QPair<StateWrapper *, backgroundType> convertMapToWrapper(const QString &mapValue);
};

#endif // WALLNUMBERRESPONSABILITYCHAINREADER_H
