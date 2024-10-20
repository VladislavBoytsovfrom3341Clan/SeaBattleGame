#include"CastableOnMap.h"

#include<stdexcept>

void CastableOnMap::set(Battlefield& field, Coords coords)
{
    if(coords.x<0 or coords.x>=field.size().x or coords.y<0 or coords.y>=field.size().y)
        throw std::invalid_argument("Invalid coords given");
    mField = &field;
    mCoords = coords;
}