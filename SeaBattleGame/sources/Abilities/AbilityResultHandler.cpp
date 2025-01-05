#include"AbilityResultHandler.h"

AbilityResult* AbilityResultHandler::getResult() const noexcept
{
    return mResult;
}

void AbilityResultHandler::setResult(AbilityResult* result) noexcept
{
    mResult = result;
}