#ifndef SCANNER_RESULT_H
#define SCANNER_RESULT_H

#include "AbilityType.h"
#include "AbilityResult.h"

/*
* Class that storages result of Scanner ability
* Holds the number of found ship segments
*/
class ScannerResult: public AbilityResult
{
    int mSegNum = 0;
public:
    ScannerResult(int num);

    ScannerResult(const ScannerResult& copy);

    //Returns number of found ships
    int getResult() const;
    
    AbilityType getType() const override;
};

#endif