#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include <queue>

#include "AbilityFactory.h"
#include "IAbility.h"
#include "AbilitySettingsVisitor.h"

class AbilityManager
{
    std::queue<AbilityType> mAbilities;
    AbilityFactory mFactory;
    AbilitySettingsVisitor mVisitor;

    IAbility* buildAbility(IAbilitySettings* settings);
public:
    AbilityManager();

    bool empty() const noexcept;

    AbilityType getFirstAbility() const;
    void castLastAbility(IAbilitySettings& settings);
    void addRandomAbility();

    ~AbilityManager();
};

#endif