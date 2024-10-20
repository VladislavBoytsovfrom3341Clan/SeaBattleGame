#ifndef CASTABLE_ON_MAP
#define CASTABLE_ON_MAP

#include "Battlefield.h"

class CastableOnMap
{
protected:
    Battlefield* mField;
    Coords mCoords;
public:
    CastableOnMap() = default;
    void set(Battlefield& field, Coords coords);
};

#endif