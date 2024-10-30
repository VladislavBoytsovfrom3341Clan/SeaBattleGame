#include "AbilitySettingsVisitor.h"

AbilitySettingsVisitor::AbilitySettingsVisitor(AbilityFactory& factory):
mFactory(factory){}

void AbilitySettingsVisitor::visit(class DoubleDamageSettings* ddSettings)
{
    mFactory.buildDoubleDamage(ddSettings);
}

void AbilitySettingsVisitor::visit(class ScannerSettings* scSettings)
{
    mFactory.buildScanner(scSettings);
}

void AbilitySettingsVisitor::visit(class ShellingSettings* shSettings)
{
    mFactory.buildShelling(shSettings);
}