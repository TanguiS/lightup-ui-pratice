#ifndef BLANKRESPONSABILITYCHAINREADER_H
#define BLANKRESPONSABILITYCHAINREADER_H

#include "include/mapread/AResponsabilityChainReader.h"

class BlankResponsabilityChainReader : public AResponsabilityChainReader
{
public:
    BlankResponsabilityChainReader( AResponsabilityChainReader *nextResponsability = nullptr );
    QPair<StateWrapper *, backgroundType> convertMapToWrapper(const QString &mapValue);
};

#endif // BLANKRESPONSABILITYCHAINREADER_H
