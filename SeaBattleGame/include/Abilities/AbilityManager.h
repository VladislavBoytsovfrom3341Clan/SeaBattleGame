#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H


#include "AbilityType.h"
#include "IAbility.h"
#include "AbilityFactory.h"
#include "AbilitySettingsVisitor.h"
#include "IAbilitySettings.h"

#include <deque>
#include <fstream>


/*
* Class storages abilities, builds new ones
* and executes (casts) last ability.
* Realises the only proper way for user
* to communicate with ability mechanics
*/
class AbilityManager
{
    //deque of available abilities
    std::deque<AbilityType> mAbilities;

    //Factory for biulding abilities
    AbilityFactory mFactory;

    //Is using to figure out ability type
    AbilitySettingsVisitor mVisitor;        

    //Storages all possible types, is using for random
    std::vector<AbilityType> mAbilitiesVector;  


    //Auxillary method, builds ability by settings type and returns one
    IAbility* buildAbility(IAbilitySettings* settings);
public:
    AbilityManager();

    AbilityManager(const AbilityManager& copy);

    AbilityManager(AbilityManager&& moved) noexcept;

    bool empty() const noexcept;

    //Returns type of first storaged ability
    AbilityType getFirstAbility() const;

    //Takes ability settings, checks available ability, builds ans executes one
    void castFirstAbility(IAbilitySettings& settings);

    //Adds new random ability into deque of storaged
    void addRandomAbility();

    //Adds new ability into deque of storaged
    void addAbility(AbilityType type);

    AbilityManager& operator=(const AbilityManager& manager);

    AbilityManager& operator=(AbilityManager&& manager) noexcept;

    friend std::istream& operator>>(std::istream& is, AbilityManager& manager);

    friend std::ostream& operator<<(std::ostream& os, AbilityManager& manager);

    ~AbilityManager() = default;
};

#endif