#ifndef I_ABILITY_H
#define I_ABILITY_H

/*
* Interface describing behavior of ability
*/
class IAbility
{
public:

    //Virtual method describing "behavior" of any ability
    virtual void cast()=0;
};

#endif