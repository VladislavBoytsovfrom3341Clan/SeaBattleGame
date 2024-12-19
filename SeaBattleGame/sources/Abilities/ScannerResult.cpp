#include "ScannerResult.h"

ScannerResult::ScannerResult(int num):
mSegNum(num){}

ScannerResult::ScannerResult(const ScannerResult& copy)
{
    mSegNum = copy.mSegNum;
}

int ScannerResult::getResult() const
{
    return mSegNum;
}

AbilityType ScannerResult::getType() const
{
    return AbilityType::Scanner;
}