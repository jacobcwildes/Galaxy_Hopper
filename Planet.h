//This file is the header for the Planet.cpp file
//Created by Jacob Wildes, Alex Brown, and Matthew Adams
/**********************/
//LAST UPDATED 12/15/21//
/**********************/
#ifndef PLANET_H
#define PLANET_H
#include <iostream>
namespace planet{
    class Planet{
        protected:
            std::string planet;
            int location = 0; //Location in solar system of each planet
            std::string description;
        public:
            Planet *right, *left, *parent; //This is so the program can add planets in properly, and so that it can be in any direction, up or down
            Planet (std::string planetName, int location, std::string description); //Stores all of the relevant data each planet absolutely will have
            std::string getPlanet(); //Fetches planet name
            int getLocation(); //Fetches planet location in solar system
            std::string getDesc();
    };

}


#endif // PLANET_H
