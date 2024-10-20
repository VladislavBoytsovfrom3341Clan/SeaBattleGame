#include"DoubleDamage.h"

void DoubleDamage::cast()
{
    mField->attackCell(mX, mY, 2);
}