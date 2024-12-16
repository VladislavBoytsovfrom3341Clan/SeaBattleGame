#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include <deque>
#include <fstream>

#include "AbilityType.h"
#include "IAbility.h"
#include "AbilityFactory.h"
#include "AbilitySettingsVisitor.h"


class AbilityManager
{
    std::deque<AbilityType> mAbilities;
    AbilityFactory mFactory;
    AbilitySettingsVisitor mVisitor;
    std::vector<AbilityType> mAbilitiesVector;

    IAbility* buildAbility(IAbilitySettings* settings);
public:
    AbilityManager();

    AbilityManager(const AbilityManager& copy);

    AbilityManager(AbilityManager&& moved);

    bool empty() const noexcept;

    AbilityType getFirstAbility() const;

    void castLastAbility(IAbilitySettings& settings);

    void addRandomAbility();

    void addAbility(AbilityType type);

    AbilityManager& operator=(const AbilityManager& manager);

    AbilityManager& operator=(AbilityManager&& manager);

    friend std::istream& operator>>(std::istream& is, AbilityManager& manager);

    friend std::ostream& operator<<(std::ostream& os, AbilityManager& manager);

    ~AbilityManager();
};

#endif