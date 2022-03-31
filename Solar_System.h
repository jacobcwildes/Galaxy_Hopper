//Header file for the Solar_System.cpp file, containing
//prototypes for each function
//Created by Jacob Wildes Alex Brown, and Matthew Adams
/**********************/
//LAST UPDATED 12/15/21//
/**********************/

#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H
#include "Planet.h"
#include <iostream>


namespace solarsystem{
class solarSystem{//determines the attribute for the solar system
private:
    planet::Planet *root;
public:
    solarSystem();
    void addPlanet(std::string planet, int distance,std::string description);
    int listPlanets(planet::Planet *p);
    void printPlanets();
    int calculateFuel(int thisLocation, int nextLocation);
    int searchPlanets(std::string planetHunt);
    planet::Planet* seekDesc(std::string description);


};
bool operator > (planet::Planet r, planet::Planet n);
}
#endif // SOLAR_SYSTEM_H
