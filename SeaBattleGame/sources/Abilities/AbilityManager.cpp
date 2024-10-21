#include "AbilityManager.h"

#include <vector>
#include <cstdlib>
#include <stdexcept>

constexpr int abilitiesNum = 3;

AbilityManager::AbilityManager()
{
    std::vector<IAbility*> tempAbilitiesVector;
    tempAbilitiesVector.push_back(new DoubleDamage);
    tempAbilitiesVector.push_back(new Shelling);
    tempAbilitiesVector.push_back(new Scanner);

    while(tempAbilitiesVector.size() > 0)
    {
        int index = std::rand() % tempAbilitiesVector.size();
        mAbilities.push(tempAbilitiesVector.at(index));
        tempAbilitiesVector.erase(tempAbilitiesVector.begin() + index);
    }
}

IAbility* AbilityManager::makeRandomAbility() const noexcept
{
    IAbility* newAbility;
    int index = rand() % abilitiesNum;
    switch (index)
    {
    case 0:
        newAbility = new DoubleDamage;
        break;
    
    case 1:
        newAbility = new Scanner;
        break;

    case 2:
        newAbility = new Shelling;
        break;

    default:
        newAbility = new DoubleDamage;
        break;
    };
    return newAbility;
}

void AbilityManager::addAbility() noexcept
{
    mAbilities.push(makeRandomAbility());
}

bool AbilityManager::empty() const noexcept
{
    return mAbilities.empty();
}

int AbilityManager::getAbilityNumber() const noexcept
{
    return mAbilities.size();
}

IAbility& AbilityManager::getAbility() const
{
    if (this->empty())
        throw std::logic_error("No free abilities");
    return *mAbilities.front();
}

void AbilityManager::popAbility() noexcept
{
    if(this->empty())
        return;
    IAbility* temp = mAbilities.front();
    mAbilities.pop();
    delete temp;
}

AbilityManager::~AbilityManager()
{
    while(!mAbilities.empty())
    {
        IAbility* temp = mAbilities.front();
        delete temp;
        mAbilities.pop();
    }
}