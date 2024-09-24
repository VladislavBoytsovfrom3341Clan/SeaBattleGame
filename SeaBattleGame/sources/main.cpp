#include"Battlefield.h"
#include<iostream>

int main()
{
    Battlefield b(10, 10);
    b.display();
    Battleship s4(1);
    b.setShip(&s4, 1, 1, Orientation::vertical);
    Battleship s3(3);
    b.setShip(&s3, 3, 0, Orientation::vertical);
    b.attackCell(0, 0);
    b.attackCell(0, 1);
    b.attackCell(1, 1);
    b.attackCell(1, 2);
    b.attackCell(2, 1);
    b.attackCell(1, 1);
    b.display();
    

}