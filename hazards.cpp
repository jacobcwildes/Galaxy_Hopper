//This file contains all of the functions for the hazards header file. On each turn, each hazard has a chance of occurring.
//Created by Alex Brown & Jacob Wildes
/**********************/
//LAST UPDATED 12/15/21//
/**********************/
#include "hazards.h"
#include "Planet.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ship.h"


using namespace std;


namespace hazards{

    Hazards::Hazards(string name, int roll)         //Constructor for Hazards, taking name and roll values.

    {

        this->name=name;
        this->roll=roll;

    }

    int Hazards::roll_probablity(int roll)          //Virtual roll_probability function (called virtual in header). This allows it to be overwritten.

    {

        cout << "This is not the correct rollprob"<<endl;       //Test statement, this should never occur
        return roll;

    }

    Fire::Fire(string name,int crew) : Hazards(name,roll),crew(crew){};     //Constructor for 'fire' hazard, taking name and a standard roll value from Hazards. Taking crew from crew.


    int Fire::roll_probablity(int roll)                                     //Fire roll_probability, overwriting the Hazards virtual roll probability, taking the fixed roll value from Hazards.

    {

        while (true){

            string ok;
            if (roll >=1 && roll <=20){                                     //Roll from 1-20 20%chance

            cout << endl;
            cout << "A fire has started aboard the ship during travel, one of your crew members heroically rushes to extinguish the flame, but instead perishes."
            <<endl<<"Enter: 'ok' to continue" << endl;
            ok1:cin >> ok;                                                  //Input from user to acknowledge the fire has been started and resolved.
                if(ok == "ok") return roll;

                else {
                    cout << "Please enter 'ok' to continue" << endl;
                    goto ok1;
                    }


            }

            else return roll;                                                        //Return roll to be used in Main

            }




    }


    navFailure::navFailure(string name, int fuel): Hazards(name,roll),fuel(fuel) {}; //navFailure constructor taking name and fixed roll value from Hazards, taking fuel from fuel.
    int navFailure::roll_probablity(int roll)                                        //navFailure roll probability overwriting the Hazards virtual roll

    {

        while (true)

        {
            string ok;
            if (roll >=21 && roll <=35){                                            //Roll from 21-35 15%chance
            cout << endl;
            cout << "A navigation failure has happened aboard the ship, you wander around for a while wasting fuel before you are able to fix it."
            <<endl<<"Enter: 'ok' to continue" << endl;
            ok:cin >> ok;
                if(ok == "ok") return roll;                                         //Input from user to acknowledge navFailure and resolve.

                else {

                    cout << "Please enter 'ok' to continue" << endl;
                    goto ok;

                }



            }

            else return roll;                                                                                       //Returns roll to be used in Main

        }


    }

     asteroidStrike::asteroidStrike(string name,int fuel,int crew) : Hazards(name,roll),crew(crew),fuel(fuel){};    //Constructor for asteroid strike taking name from Hazards and a fixed roll value, crew from crew, and fuel from fuel.

     int asteroidStrike::roll_probablity(int roll)                                                                  //asteroidStrike roll_probability overwriting virtual roll_probability from Hazards.

    {

        while (true)

        {
            string ok;
            if (roll >=36 && roll <= 40){                                                                           //Roll from 36-40 5%chance
            cout << endl;
            cout << "An asteroid has impacted your ship. You have lost 2 fuel and 2 crew."
            <<endl<<"Enter: 'ok' to continue" << endl;
            ok2:cin >> ok;
                if(ok == "ok") return roll;                                                                         //Input from user to acknowledge asteroidStrike and resolve

                else {
                    cout << "Please enter 'ok' to continue" << endl;
                    goto ok2;
                }
            }

            else return roll;                                                                                       //Returns roll to be used in Main








        }


    }


};
