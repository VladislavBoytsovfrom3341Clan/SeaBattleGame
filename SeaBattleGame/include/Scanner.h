#ifndef SCANER_H
#define SCANER_H

#include"IAbility.h"
#include"CastableOnMap.h"

constexpr int scannerRange = 2;

class Scanner: public IAbility, public CastableOnMap
{
    class ResultScanner
    {
        int mSegNumber = 0;
    public:
        void setResult(int num);
        void add();
        int getSegNumber();
        bool containShips();
    };

    ResultScanner result;
public:
    Scanner() = default;
    void set(Battlefield& field, Coords coords);
    void cast() override;
    bool containShips();
    int getSegNum();
};

#endif