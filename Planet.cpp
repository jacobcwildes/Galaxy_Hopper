//This file is the equivalent of the "Node" class from previous homeworks
//It stores all relevant data that each planet will always have
//Created by Jacob Wildes
/**********************/
//LAST UPDATED 12/15/21//
/**********************/
#include "Planet.h"
#include "Solar_System.h"
#include <iostream>
extern const double solarSystemCenter;

using namespace std;
namespace planet{
    //This constructor will be called to make each new planet
    Planet::Planet(string planetName, int inLocation, string planetDescription)
    {
        planet = planetName;
        location = inLocation;
        description = planetDescription;
        right = NULL;
        left = NULL;
        parent = NULL;
    }
    //Wrapper function to fetch the planet name
    string Planet::getPlanet()
    {
        return planet;
    }
    //Wrapper function to fetch the planet location in the system
    int Planet::getLocation()
    {
        return location;
    }
    string Planet::getDesc()
    {
        return description;
    }

}




