#ifndef CASTABLE_ON_MAP
#define CASTABLE_ON_MAP

#include "Battlefield.h"

class CastableOnMap
{
protected:
    Battlefield* mField;
    int mX, mY;
public:
    CastableOnMap() = default;
    void set(Battlefield& field, int x, int y);
};

#endif