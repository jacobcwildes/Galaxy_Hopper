//Header file for hazards.cpp, containing all necessary functions
//Header file initializes everything, descriptions are contained in cpp file
//Created by Alex Brown
/**********************/
//LAST UPDATED 12/7/21//
/**********************/

#ifndef HAZARDS_H
#define HAZARDS_H
#include <iostream>
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <time.h>


namespace hazards{

class Hazards{


protected:

    std::string name;

    int roll;

public:

    Hazards(std::string name, int roll);
    virtual int roll_probablity (int roll);     //Virtual is used here to allow for overwriting in the cpp file.


};

class Fire : public Hazards {

protected:

    int crew;

public:

    Fire(std::string name, int crew);
    int roll_probablity (int roll);



};

class navFailure : public Hazards{
protected:
    int fuel;
public:

    navFailure(std::string name, int fuel); //name this one navFailure

    int roll_probablity(int roll);

};

class asteroidStrike : public Hazards {
protected:

int fuel;
int crew;

public:

    asteroidStrike(std::string name,int fuel, int crew); //name this one asteroidStrike

    int roll_probablity(int roll);
};

}


#endif // HAZARDS_H
