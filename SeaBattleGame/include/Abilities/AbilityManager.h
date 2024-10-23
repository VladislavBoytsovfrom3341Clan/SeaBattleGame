#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include <queue>

#include "AbilityFactory.h"
#include "IAbility.h"

class AbilityManager
{
    std::queue<AbilityType> mAbilities;
    AbilityFactory mFactory;

    IAbility* makeRandomAbility() const noexcept;
public:
    AbilityManager();

    void addAbility() noexcept;
    bool empty() const noexcept;
    int getAbilityNumber() const noexcept;
    IAbility& getAbility() const;
    void popAbility() noexcept;

    ~AbilityManager();
};

#endif