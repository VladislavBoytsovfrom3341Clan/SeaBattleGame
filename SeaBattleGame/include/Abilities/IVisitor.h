#ifndef I_VISITOR_H
#define I_VISITOR_H

/*
* Interface describing behavior of visitor class for abilities
* Is used to deduct ability types by their settings
*/
class IVisitor
{
public:
    virtual void visit(class DoubleDamageSettings* ddSettings) = 0;
    virtual void visit(class ScannerSettings* scSettings) = 0;
    virtual void visit(class ShellingSettings* shSettings) = 0;
};

#endif