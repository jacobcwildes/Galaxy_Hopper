//This cpp file contains the parameters for each planet//
//Created by Jacob Wildes & Alex Brown
/**********************/
//LAST UPDATED 12/15/21//
/**********************/
#include "Solar_System.h"
#include "Planet.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>


using namespace std;
using namespace planet;
/*The solar system is going to be set up in a binary search tree,
/with a function deciding which way a planet should be set in the
/tree based off of planet distance from 4546B */
namespace solarsystem{
    solarSystem::solarSystem()
    {
        root = NULL; //even though it's a solar system, the binary tree still needs a root of NULL
    }
    //Takes in the name of the planet, the location, and the description of the planet in the solar system.
    //The description is not used at all in the process of allocating planets left and right. It is just included
    //for ease of programming, and outputting the description to the user as the game runs
    void solarSystem::addPlanet(string inPlanet, int location, string description)
    {
        planet::Planet *n = new Planet(inPlanet, location, description);
       // transform(inPlanet.begin(), inPlanet.end(), inPlanet.begin(), ::tolower);
        if(root == NULL){ root = n; /*cout<<"adding to root " << inPlanet << endl;*/}
        else
        {
            planet::Planet *r = root;
            while(true)
            {
                if(*r > *n) //If the new planet is closer than the planet in question, go to the right
                {

                    if(r->right == NULL)
                    {
                       // cout<<"adding to right " << inPlanet<<endl;
                        r->right = n;
                        n->parent = r;
                        break;
                    }
                    else
                    {
                        r = r->right;
                    }
                }
                else //otherwise, go left
                {
                    if(r->left == NULL)
                    {
                        //cout<<"adding to left " << inPlanet<<endl;
                        r->left = n;
                        n->parent = r;
                        break;
                    }
                    else
                    {
                        r = r->left;
                    }
                }
            }


        }
    }

    //This lists out the planets to the user if they enter 'system.'
    int solarSystem::listPlanets(planet::Planet *r) //It takes in the planet so that it can find the location as well as the name to output
    {
        if(r == NULL) return -1;
        solarSystem::listPlanets(r->left);
        cout << r->getPlanet();
        for(int i = 0; i<17-(r->getPlanet().length()); i++) cout<<" "; //The i<17 is just for pretty purposes. This aligns everything nicely on the output display.
        cout << to_string(r->getLocation()) << endl;
        solarSystem::listPlanets(r->right);
        return 0;
    }


    //This physically prints out the planets to the screen.
    //It's sort of a pseudo wrapper so that listPlanets can access the root of
    //the binary search tree.
    void solarSystem::printPlanets()
    {

        cout<<"*****************************\n";
        cout<<"  Planet:    Location:\n",
        solarSystem::listPlanets(root);
        cout<<"*****************************\n";
    }
    //tells how much fuel a trip from one planet to another will cost by taking
    //in the location of the current planet and the location of the planet being traveled to
    int solarSystem::calculateFuel(int thisLocation, int nextLocation)
    {
        if(abs(thisLocation - nextLocation) >=  0) //If this somehow manages to become less than 0, it needs to return that -10 to show an error
        {
            return abs(nextLocation-thisLocation); /*((thisLocation - nextLocation) +(2*(thisLocation - nextLocation)));*/
        }
        else return -10;
    }

    //Takes in the string of the planet under scrutiny, as that is how
    //the program compares to ensure it's looking at the proper node
    int solarSystem::searchPlanets(string nextPlanet)
    {
        Planet *hunt = root;
        string position = nextPlanet;
        if(root == NULL) return -1;
        while(hunt != NULL)
        {
            if(position.compare(hunt->getPlanet()) == 0)
            {
                //cout<<"Found Planet " << hunt->getPlanet() << "at " << hunt->getLocation() << endl;
                return hunt->getLocation();

            }
            else if(position.compare(hunt->getPlanet()) != 0)
                {
                    hunt = hunt->left;
                }
            else
                {
                    hunt = hunt->right;
                }

        }
        return 0;
    }

    //Kind of simple, but it does the job. It takes the locations of the
    //two planets in question and returns whether or not the planet, r
    //is greater than planet b's distance.
    bool operator > (planet::Planet r, planet::Planet n)
    {
        if(r.getLocation() > n.getLocation())
        {
            return true;
        }
        return false;
    }


}
