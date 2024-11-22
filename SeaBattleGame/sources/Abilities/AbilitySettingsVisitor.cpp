#include "AbilitySettingsVisitor.h"

#include "AbilityFactory.h"
#include "DoubleDamage.h"
#include "Shelling.h"
#include "Scanner.h"

AbilitySettingsVisitor::AbilitySettingsVisitor(AbilityFactory& factory):
mFactory(factory){}

void AbilitySettingsVisitor::visit(class DoubleDamageSettings* ddSettings)
{
    mFactory.build<DoubleDamageSettings, DoubleDamage>(ddSettings);
}

void AbilitySettingsVisitor::visit(class ScannerSettings* scSettings)
{
    mFactory.build<ScannerSettings, Scanner>(scSettings);
}

void AbilitySettingsVisitor::visit(class ShellingSettings* shSettings)
{
    mFactory.build<ShellingSettings, Shelling>(shSettings);
}