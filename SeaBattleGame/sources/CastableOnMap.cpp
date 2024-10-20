#include"CastableOnMap.h"

void CastableOnMap::set(Battlefield& field, Coords coords)
{
    mField = &field;
    mCoords = coords;
}