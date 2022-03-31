//This is the cpp file. It deals with wrapper functions for accessing fuel and crew, as well as modifying their values in real time.
//Created by Alex Brown, Jacob Wildes, and Matt Adams
//**********************//
/*LAST UPDATED: 12/15/21*/
//********************** //

#include "Solar_System.h"
#include "Planet.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include "ship.h"

using namespace std;
using namespace solarsystem;

namespace ship{

    Scout::Scout(int fuel, int crew) //Scout constructor. This tells it where to look for it's maximum fuel and crew levels
{
    this->fuel = fuel;
    this->crew = crew;

}

    int Scout::getFuel() //Wrapper function to access the fuel
{

    return fuel;

}

    void Scout::scoutMaxC(int crew) //Sets the crew number back to 5 so as not to exceed the maximum allowed crew
{
    if (crew > 5)
    {
        crew = 5;
        cout << "Crew capacity reached" << endl << "Crew: " << crew << endl;

    }

    else cout << "Crew: " << crew << endl;


}

    void Scout::scoutMaxF(int fuel) //Sets the fuel number back to 10 so as not to exceed the maximum allowed fuel
{
    if (fuel > 10)
    {

       fuel = 10;
       cout << "Fuel capacity reached" << endl << "Fuel: " << fuel << endl;

    }

    else cout << "Fuel: " << fuel << endl;



}

    Freighter::Freighter(int fuel, int crew) //Constructor for the freighter class. It takes in the maximum fuel and crew
    {
        this->fuel = fuel;
        this->crew = crew;
    }
    int Freighter::getFuel() //Wrapper function to fetch the fuel amount for the freighter
    {
        return fuel;
    }
    void Freighter::freighterMaxF(int fuel) //Function to push the freighter fuel back down to 30 units should it get surpassed.
    {
        if(fuel > 30)
        {
            fuel = 30;
            cout << "Fuel capacity reached " << endl << "Fuel level: " << fuel << endl;
        }
        else cout << "Fuel: " << fuel << endl;
    }
    void Freighter::freighterMaxC(int crew) //Function to push the freighter crew level back to at capacity, should it exceed 15
    {
        if(crew > 15)
        {
            crew = 15;
            cout << "Crew capacity reached." << endl << "Crew level: " << crew << endl;
        }
        else cout << "Crew: " << crew << endl;
    }






}

