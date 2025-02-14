#include "AbilityManager.h"
#include "NoAbilityException.h"
#include "AbilityType.h"

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <random>

//Initialises deque of abilities randomly 
AbilityManager::AbilityManager():
mVisitor(mFactory)
{
    mAbilitiesVector =
        {AbilityType::DoubleDamage, AbilityType::Scanner, AbilityType::Shelling};
    auto rng = std::default_random_engine {};
    std::shuffle(mAbilitiesVector.begin(), mAbilitiesVector.end(), rng);
    
    for(auto& i: mAbilitiesVector)
        mAbilities.push_back(i);
}

AbilityManager::AbilityManager(const AbilityManager& copy):
    AbilityManager()
{
    this->mAbilities = copy.mAbilities;
}

AbilityManager::AbilityManager(AbilityManager&& moved) noexcept:
    AbilityManager()
{
    this->mAbilities = std::move(moved.mAbilities);
}

void AbilityManager::addAbility(AbilityType type)
{
    mAbilities.push_back(type);
}

void AbilityManager::addRandomAbility()
{
    auto rng = std::default_random_engine{};
    std::shuffle(mAbilitiesVector.begin(), mAbilitiesVector.end(), rng);

    this->addAbility(mAbilitiesVector.front());
}

//Calls visitor on settings, who calls factory to build ability
IAbility* AbilityManager::buildAbility(IAbilitySettings* settings)
{
    settings->acceptVisitor(mVisitor);
    return mFactory.getAbility();
}

//Calls build ability on proper settings type or throws an exception
//Then casts ability and delete one
void AbilityManager::castFirstAbility(IAbilitySettings& settings)
{
    if (this->empty())
        throw NoAbilityException();
    if(settings.getType() != mAbilities.front())
        throw std::logic_error("Invalid ability settings type");
    
    IAbility* currentAbility = this->buildAbility(&settings);

    currentAbility->cast();

    delete currentAbility;

    mAbilities.pop_front();
}

bool AbilityManager::empty() const noexcept
{
    return mAbilities.empty();
}

AbilityType AbilityManager::getFirstAbility() const
{
    if (this->empty())
        throw NoAbilityException();
    return mAbilities.front();
}

AbilityManager& AbilityManager::operator=(const AbilityManager& manager)
{
    this->mAbilities = manager.mAbilities;
    return *this;
}

AbilityManager& AbilityManager::operator=(AbilityManager&& manager) noexcept
{
    this->mAbilities = std::move(manager.mAbilities);
    return *this;
}

//Reads types of abilities by according chars
std::istream& operator>>(std::istream& is, AbilityManager& manager)
{
    int n = 0;
    is >> n;
    if (n == 0)
    {
        manager.mAbilities.clear();
        return is;
    }
    std::string buf;
    is >> buf;
    if (buf.size() != n)
        throw std::runtime_error("Unequal abilities lists size!\n");
    manager.mAbilities.clear();
    for (auto& c : buf)
    {
        switch (c)
        {
        case 'q':
        {
            manager.addAbility(AbilityType::DoubleDamage);
            break;
        }
        case 'w':
        {
            manager.addAbility(AbilityType::Shelling);
            break;
        }
        case 'e':
        {
            manager.addAbility(AbilityType::Scanner);
            break;
        }
        default:
            throw std::runtime_error("Invalid ability type!\n");
        };
    }
    return is;
}

//Writes abilities with according chars
std::ostream& operator<<(std::ostream& os, AbilityManager& manager)
{
    os << manager.mAbilities.size() << '\n';
    for (auto& ability : manager.mAbilities)
    {
        switch (ability)
        {
        case AbilityType::DoubleDamage:
        {
            os << 'q';
            break;
        }
        case AbilityType::Shelling:
        {
            os << 'w';
            break;
        }
        case AbilityType::Scanner:
        {
            os << 'e';
            break;
        }
        };
    }
    os << '\n';
    return os;
}