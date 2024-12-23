#ifndef SCANNER_RESULT_H
#define SCANNER_RESULT_H

#include "AbilityType.h"
#include "AbilityResult.h"

class ScannerResult: public AbilityResult
{
    int mSegNum = 0;
public:
    ScannerResult(int num);

    ScannerResult(const ScannerResult& copy);

    int getResult();
    
    AbilityType getType() override;
};

#endif