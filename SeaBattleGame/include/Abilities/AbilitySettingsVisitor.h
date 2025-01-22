#ifndef ABILITY_SETTINGS_VISITOR_H
#define ABILITY_SETTINGS_VISITOR_H

#include "AbilityFactory.h"

#include "IVisitor.h"

/*
* Class gives factory proper types of abilities to build
*/
class AbilitySettingsVisitor: public IVisitor
{
    AbilityFactory& mFactory;
public:
    AbilitySettingsVisitor(AbilityFactory& factory);

    void visit(class DoubleDamageSettings* ddSettings) override;
    void visit(class ScannerSettings* scSettings) override;
    void visit(class ShellingSettings* shSettings) override;

    ~AbilitySettingsVisitor() = default;
};

#endif