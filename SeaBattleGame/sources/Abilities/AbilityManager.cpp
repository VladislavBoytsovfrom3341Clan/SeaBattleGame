#include "AbilityManager.h"

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <random>

constexpr int abilitiesNum = 3;

AbilityManager::AbilityManager():
mVisitor(mFactory)
{
    std::vector<AbilityType> tempAbilitiesVector = 
        {AbilityType::DoubleDamage, AbilityType::Scanner, AbilityType::Shelling};

    auto rng = std::default_random_engine {};
    std::shuffle(tempAbilitiesVector.begin(), tempAbilitiesVector.end(), rng);
    
    for(auto i: tempAbilitiesVector)
        mAbilities.push(i);
}

void AbilityManager::addRandomAbility()
{
    std::random_device rd;   
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(1, abilitiesNum);

    switch (dist(gen))
    {
    case 1:
    {
        mAbilities.push(AbilityType::DoubleDamage);
        break;
    }
    {
        mAbilities.push(AbilityType::Scanner);
        break;
    }
    {
        mAbilities.push(AbilityType::Shelling);
        break;
    }    
    default:
        break;
    }
}

IAbility* AbilityManager::buildAbility(IAbilitySettings* settings)
{
    settings->acceptVisitor(mVisitor);
    return mFactory.getAbility();
}

void AbilityManager::castLastAbility(IAbilitySettings& settings)
{
    if(settings.getType() != mAbilities.front())
        throw std::logic_error("Invalid ability settings type");
    
    IAbility* currentAbility = this->buildAbility(&settings);

    currentAbility->cast();

    delete currentAbility;

    mAbilities.pop();
}

bool AbilityManager::empty() const noexcept
{
    return mAbilities.empty();
}


AbilityType AbilityManager::getFirstAbility() const
{
    if (this->empty())
        throw std::logic_error("No free abilities");
    return mAbilities.front();
}

AbilityManager::~AbilityManager()
{
    
}