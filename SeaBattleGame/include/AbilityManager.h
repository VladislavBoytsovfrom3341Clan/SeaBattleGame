#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include <queue>

#include "IAbility.h"
#include "DoubleDamage.h"
#include "Scanner.h"
#include "Shelling.h"

class AbilityManager
{
    std::queue<IAbility*> mAbilities;

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