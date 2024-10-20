#include"CastableOnMap.h"

void CastableOnMap::set(Battlefield& field, int x, int y)
{
    mField=&field;
    mX=x;
    mY=y;
}