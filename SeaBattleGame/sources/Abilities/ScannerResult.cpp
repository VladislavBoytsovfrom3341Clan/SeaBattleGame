#include "ScannerResult.h"

ScannerResult::ScannerResult(int num):
mSegNum(num){}

int ScannerResult::getResult()
{
    return mSegNum;
}

AbilityType ScannerResult::getType()
{
    return AbilityType::Scanner;
}