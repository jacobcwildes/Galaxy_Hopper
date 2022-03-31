//This is the header file for the ship.cpp. It defines the maximum amounts of fuel and crew each ship has
//Created by Alex Brown, Jacob Wildes, and Matthew Adams
//**********************//
/*LAST UPDATED: 12/15/21*/
//********************** //

#ifndef SHIP_H
#define SHIP_H
#include <iostream>

namespace ship{

class Scout{//determines the attributes for the scout ship

private:

    int fuel = 10;
    int crew = 5;



public:

    Scout (int fuel, int crew);

    int getFuel ();

    void scoutMaxC (int crew);

    void scoutMaxF(int fuel);









};
class Freighter{//determines the attributes for the freighter ship

private:

    int fuel = 30;
    int crew = 15;



public:

    Freighter(int fuel, int crew);

    int getFuel ();

    void freighterMaxC (int crew);

    void freighterMaxF(int fuel);









};

}








#endif // SHIP_H
