#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H


#include "AbilityType.h"
#include "IAbility.h"
#include "AbilityFactory.h"
#include "AbilitySettingsVisitor.h"
#include "IAbilitySettings.h"

#include <deque>
#include <fstream>

class AbilityManager
{
    std::deque<AbilityType> mAbilities;     //queue of available abilities
    AbilityFactory mFactory;
    AbilitySettingsVisitor mVisitor;        //used to figure out ability type
    std::vector<AbilityType> mAbilitiesVector;  //storages all possible types, used for random

    IAbility* buildAbility(IAbilitySettings* settings);
public:
    AbilityManager();

    AbilityManager(const AbilityManager& copy);

    AbilityManager(AbilityManager&& moved) noexcept;

    bool empty() const noexcept;

    AbilityType getFirstAbility() const;

    void castLastAbility(IAbilitySettings& settings);

    void addRandomAbility();

    void addAbility(AbilityType type);

    AbilityManager& operator=(const AbilityManager& manager);

    AbilityManager& operator=(AbilityManager&& manager) noexcept;

    friend std::istream& operator>>(std::istream& is, AbilityManager& manager);

    friend std::ostream& operator<<(std::ostream& os, AbilityManager& manager);

    ~AbilityManager() = default;
};

#endif