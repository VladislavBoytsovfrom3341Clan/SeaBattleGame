#include"DoubleDamage.h"

void DoubleDamage::cast()
{
    mField->attackCell(mCoords, 2);
}