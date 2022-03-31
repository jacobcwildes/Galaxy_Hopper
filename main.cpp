//This is the core file of the game "Galaxy Hopper"
//created by Matt Adams, Alex Brown, and Jacob Wildes
//This file will take user input, and call the other
//files which make this program run
/**********************/
//LAST UPDATED 12/15/21//
/**********************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include "Planet.h"
#include "Solar_System.h"
#include "ship.h"
#include "hazards.h"
#include "time.h"
#include <stdlib.h>

using namespace planet;
using namespace std;
using namespace solarsystem;
using namespace ship;
using namespace hazards;

int currentFuel = 0;
int currentCrew = 0;


bool freighter = false;
bool scout = false;

int roll = rand()%100+1;



//Runs the probability function
void checkHazard(Hazards*x)

{

      x->roll_probablity(roll);

};

int main(int argc, char **argv)
{
    srand (time(NULL));
    int nextFuel = 0;
    int thisFuel = 0;
    int secondFuel = 0;
                           //If ALL of the values in this block hit 1, the game is won!
//------------------------------------------------------------------------------------------------------------------
    int homePlanet = 0; //Even though it's a safe planet, have to visit here to win the game!
    int Pegasid = 0; //Count the amount of times this planet was visited
    int PSRCounter = 0; //So that the interaction here can't be abused and used to completely refuel in one stop
    int GliesedCounter = 0; //So that the player can't abuse themselves and keep losing crew
    int KeplerdCounter = 0; //So that the player can't revisit the hell planet
    int KeplerBCOunter = 0; //So that the player can't return to a pretty boring planet
    int KeplercCounter = 0; //Count the amount of times the player came to this planet
    int GliesebCounter = 0; //Count the amount of times this planet was visited
    int PSRACounter = 0; //Count the amount of times this planet was visited
    int oneRXS = 0; //To count the amount of times this planet was visited


//-------------------------------------------------------------------------------------------------------------------
    int eE2 = 0; //For EE
    string x;
    string currentPlanet = "4546B";
    string nextPlanet = "";
    //*INTRO, GREETING
    start:cout << "*-----------------------------------------------------------------------------*\n";
    cout << "*To begin, please enter a file named 'input.txt' to draw ship selections from.*\n";
    cout << "*For different ship classes and specifications, please enter 'ship'           *\n";
    cout << "*For general help or how to set up the input file, please enter 'help'        *\n";
    cout << "*There are a couple of easter eggs within this program. Enjoy hunting!        *\n";
    cout << "*-----------------------------------------------------------------------------*\n";

    Fire f = Fire("fire",currentCrew);
    navFailure n = navFailure("navFailure", currentFuel);
    asteroidStrike a = asteroidStrike("asteroidStrike",currentCrew,currentFuel);

//    if(freighter == true)
//    {
//        if(currentCrew >= 15) currentCrew = 15;
//        if(currentFuel >=30) currentFuel = 30;
//    }
//    if(scout == true)
//    {
//        if(currentCrew >= 5) currentCrew = 5;
//        if(currentFuel >=10) currentFuel = 10;
//    }
    Scout q = Scout(currentFuel,currentCrew);
    Freighter L = Freighter(currentFuel, currentCrew);






    solarSystem y = solarSystem();

    //Instantiates the planets so that the main can refer to each planet
    Planet p1 = Planet("4546B", 1 ,"your home planet: Visit here to resupply fuel and gather crew members.");
    Planet p2 = Planet("51-Pegasi", 2,"a barren wasteland that was once full of life. Who knows what could be down there?");
    Planet p3 = Planet("PSR", 3,"a forest planet home to small unintelligent creatures.");
    Planet p4 = Planet("Gliese-876d", 4,"an extremely hostile volcanic planet.");
    Planet p5 = Planet("Kepler-11f", 5,"an ocean planet. Don't forget your wetsuit.");
    Planet p6 = Planet("Kepler-452b", 6,"a mysterious planet at the edge of the solar system. Not much is know about it.");
    Planet p7 = Planet("1RXS", 7,"a radioactive planet. Be warned.");
    Planet p8 = Planet("Gliese-581", 8,"an island planet. Tropical paradise.");
    Planet p9 = Planet("PSR-A", 9,"a winter planet. A distress beacon has been activated here. I got a bad feeling about this one...");
    Planet p10 = Planet("Kepler-62f",10,"a planet home to extremely hostile lifeforms.");






            //Create ye olde planets in a text file to read in momentarily:

        ofstream planetOut("planetInfo.txt");
        planetOut<<"4546B, 1 ,your home planet: Visit here to resupply fuel and gather crew members." << endl;
        planetOut<<"51-Pegasi, 2,a barren wasteland that was once full of life. Who knows what could be down there?," << endl;
        planetOut<<"PSR, 3,a forest planet home to small unintelligent creatures." << endl;
        planetOut<<"Gliese-876d, 4,an extremely hostile volcanic planet." << endl;
        planetOut<<"Kepler-11f, 5,an ocean planet. Don't forget your wetsuit." << endl;
        planetOut<<"Kepler-452b, 6,a mysterious planet at the edge of the solar system. Not much is know about it." << endl;
        planetOut<<"1RXS, 7,a radioactive planet. Be warned." << endl;
        planetOut<<"Gliese-581, 8,an island planet. Tropical paradise." << endl;
        planetOut<<"PSR-A, 9,a winter planet. A distress beacon has been activated here. I got a bad feeling about this one..." << endl;
        planetOut<<"Kepler-62f, 10,a planet home to extremely hostile lifeforms." << endl;

        planetOut.close();

        //Now read in this information, all without user input!
        //Behind the scenes is a beautiful thing

        ifstream planetIn("planetInfo.txt");
        if(planetIn.is_open())
        {
            string line;
            stringstream s;
            while(getline(planetIn, line))
            {
                s.clear();
                s.str(line);
                string planet;
                while(getline(s, planet, ','))
                {
                    string location;
                    getline(s, location, ',');
                    string description;
                    getline(s,description);
                    y.addPlanet(planet, stoi(location), description);

                }
            }
        }
        planetIn.close();

    //Tells program to look at the first argument
    string data1; //as this program takes 1 input at a time
    string data2;
    string data3;
    string data4;
    string data5;
    while(true)
    {

        cin >> data1;

        //cout<<"Freighter status: " << freighter << endl;
        //cout<<"Scout status: " << scout << endl;

        //HELP BLURBS
        if(data1 == "help")
        {
            cout<<"*---------------------------------------------------------*\n";
            cout<<"*This game will present an option each 'day' for          *\n";
            cout<<"*the player to choose from.                               *\n";
            cout<<"*The input file will be as follows: SHIP                  *\n";
            cout<<"*If you would like an example file, please enter 'example'*\n";
            cout<<"*To see the Alpha Centauri IV System, enter 'system'      *\n";
            cout<<"*To travel from your current planet to another, enter     *\n";
            cout<<"*'travel'                                                 *\n";
            cout<<"*---------------------------------------------------------*\n";


        }
        if(data1 == "ship")
        {
            cout<<"*-------------------------------------------------------------------------*\n";
            cout<<"*Freighter Characteristics: More room for supplies and crew,              *\n";
            cout<<"*Less prone to failures, and more impervious to disasters.                *\n";
            cout<<"*However, it moves much slower, is much more resource hungry,             *\n";
            cout<<"*and when disasters do occur, they take more time and resources to remedy.*\n";
            cout<<"***************************************************************************\n";
            cout<<"*Scout Characteristics: Moves quickly, resource efficient, and            *\n";
            cout<<"*failures take much less time and resources to remedy. However,           *\n";
            cout<<"*the Scout is prone to failure, is susceptible to disasters,              *\n";
            cout<<"*and there is little room for crew and resources.                         *\n";
            cout<<"*-------------------------------------------------------------------------*\n";

        }
        if(data1 == "example")

        {
            ofstream example("exampleFile.txt");
            example<<"Freighter"<<endl;

        }

        if(data1 == "input.txt")
        {

            cout <<"*************************************************************************\n";
            cout <<"Thank you. Your adventure in the Alpha Centauri IV System will now begin\n";
            cout <<"*************************************************************************\n";
            //cout<<"Success"<<endl;

            ifstream input("input.txt");
            if(input.is_open())
            {
                string line;
                stringstream s;

                while(getline(input, line))
                {
                    s.clear();
                    s.str(line);
                    string first;
                    while(getline(s, first, ':'))
                    {
                        if(first == "freighter")
                        {
                            freighter = true;
                            //cout << "New Freighter status: " << freighter << endl;
                            y.printPlanets();
                            currentCrew = currentCrew + 15;
                            currentFuel = currentFuel + 30;
                            cout << "Enter 'travel' and select one of the planets below. You are currently at:" << currentPlanet << endl << endl;
                            break;
                            //return freighter;

                        }
                        if(first == "scout")
                        {
                            scout = true;
                           // cout << "New Scout status: " << scout << endl;
                            y.printPlanets();
                            currentCrew = 5;
                            currentFuel = 10;
                            cout << "Enter 'travel' and select one of the planets below. You are currently at:" << currentPlanet << endl << endl;
                            break;

                            //return scout;

                        }

                    }
                }

            }

            else
            {
                cout << "Please make sure there is a file with the requested parameters.\n";
                goto start;
            }
        }



        else

        {

            cout << "Please enter either, 'help' , 'ship' , 'example' , or to start the game: 'input.txt' " << endl;


        }




        while (data1 == "input.txt"){
        cin >> data2;


        if(data2 == "system") //Prints out the solar system for the user
        {
            cout << endl;
            y.printPlanets();


            //break;
        }
        if(data2 == "travel") //user enters this if they are ready to travel from one planet to another
        {
            roll = rand()%100 + 1;

            checkHazard(&f);
            checkHazard(&n);
            checkHazard(&a);

        if (roll >=1 && roll <=20)

        {
            currentCrew = currentCrew-1;
            cout << endl << "Crew: " << currentCrew << endl;

        }

        else if (roll >=21 && roll <= 35)

        {
            currentFuel = currentFuel-1;
            cout << endl << "Fuel: " << currentFuel << endl;

        }

        else if (roll >= 36 && roll <= 40)

        {
            currentFuel = currentFuel-2;
            currentCrew = currentCrew-2;
            cout << endl << "Crew: " << currentCrew << endl << "Fuel: " << currentFuel << endl;


        }


            moron:cout << "*******************************************************\n";
            cout << "Please enter a planet that you would like to travel to:\n";
            cout << "*******************************************************\n";
            cin >> nextPlanet;

//---------------------------------------------------------
//----------This chunk allows the program to continue if the data taken in
//----------is EXACTLY one of the planets.
//---------------------------------------------------------
            if(nextPlanet == p1.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p2.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p3.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p4.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p5.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p6.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p7.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p8.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p9.getPlanet())
            {
                goto cont;
            }
            else if(nextPlanet == p10.getPlanet())
            {
                goto cont;
            }
            else
            {
                cout << "Please enter a valid planet.\n";
                goto moron;
            }




            //cout << nextPlanet << endl; //FOR TESTING
           // cout << "First planet location: " << y.searchPlanets(currentPlanet)<< endl; cout<< "Next planet location: " << y.searchPlanets(nextPlanet) << endl; //FOR TESTING
            cont:thisFuel = y.calculateFuel(y.searchPlanets(currentPlanet), y.searchPlanets(nextPlanet));
            //cout<< thisFuel <<endl;
            secondFuel =  currentFuel - thisFuel;
            cout<< "It cost you: " << thisFuel << " fuel" << endl;

            cout<< "You have: " << secondFuel << " fuel remaining" <<endl;

            nextFuel = currentFuel - (y.calculateFuel(y.searchPlanets(currentPlanet), y.searchPlanets(nextPlanet)));

            //cout << "intermediary variable for fuel value: " << nextFuel << endl; //FOR TESTING

            currentFuel = nextFuel;

           // cout << "new current fuel value: " << currentFuel << endl; //FOR TESTING

            if (currentFuel < 0)
            {

            cout <<endl;
            cout << "****************************************************************************************************************\n";
            cout << "*Your fuel tank has run empty. You and your crew drift endlessly, aimlessly, into space, never to be seen again*\n";
            cout << "*                                                GAME OVER                                                     *"<< endl;
            cout << "**********************************r******************************************************************************\n";
                return 0;
            }

            else cout<< "You have arrived at your destination: " << nextPlanet << endl << endl;

            currentPlanet = nextPlanet;

            if (currentPlanet == p1.getPlanet()) cout << currentPlanet << " is " << p1.getDesc() << endl;
            if (currentPlanet == p2.getPlanet()) cout << currentPlanet << " is " << p2.getDesc() << endl;
            if (currentPlanet == p3.getPlanet()) cout << currentPlanet << " is " << p3.getDesc() << endl;
            if (currentPlanet == p4.getPlanet()) cout << currentPlanet << " is " << p4.getDesc() << endl;
            if (currentPlanet == p5.getPlanet()) cout << currentPlanet << " is " << p5.getDesc() << endl;
            if (currentPlanet == p6.getPlanet()) cout << currentPlanet << " is " << p6.getDesc() << endl;
            if (currentPlanet == p7.getPlanet()) cout << currentPlanet << " is " << p7.getDesc() << endl;
            if (currentPlanet == p8.getPlanet()) cout << currentPlanet << " is " << p8.getDesc() << endl;
            if (currentPlanet == p9.getPlanet()) cout << currentPlanet << " is " << p9.getDesc() << endl;
            if (currentPlanet == p10.getPlanet()) cout << currentPlanet << " is " << p10.getDesc() << endl;


            cout << endl;
            cout << "Enter 'visit' to land on: " << currentPlanet << endl << "Or enter 'leave' to move on" << endl;

            //break;
        }
//--------------------------------------------------------------------------------------
//----------This block allows for interaction with the planets AS LONG AS TRAVEL IS TRUE
//---------------------------------------------------------------------------------------
        while (data2 == "travel"){

        cin >>data3;

            if (data3 == "visit"){

            cout << endl;
            cout << "You have landed on: " << currentPlanet << endl;
            int new_crew = 10;
            int new_fuel = 10;
            if (currentPlanet == p1.getPlanet()) //Planet 4546B
            {
                //cout << "homePlanet value " << homePlanet << endl;
                homePlanet ++;
                //cout << "homePlanet value " << homePlanet << endl;
                if(eE2 == 1)
                {
                    sleep(5);
                    cout << "You know what? You're a coward. You forced your crew onto a deadly planet against their will and left them to die\n"; sleep(2);
                    cout << "I behaved myself on Kepler-452b, but it's time for your story to end too, and for your crew's sake, I hope you don't join them\n"; sleep(2);
                    cout <<"********************************\n";
                    cout <<"*GAME OVER, YOU ABSOLUTE COWARD*\n";
                    cout <<"********************************\n";
                    return 0;
                }
            cout << "Returning to your home planet you have recruited crew members " << "and have been refueled." << endl;
            if(scout == true)
            {
                q.scoutMaxC(currentCrew+new_crew-5); //Called more or less just to print out that crew capacity was reached
                currentCrew = 5;
                q.scoutMaxF(currentFuel+100); //Called more or less just to print out that fuel capacity was reached
                currentFuel = 10;
            }
            if(freighter == true)
            {
                L.freighterMaxC(currentCrew+new_crew-5); //Called more or less just to print out that crew capacity was reached
                currentCrew = 15;
                L.freighterMaxF(currentFuel+100); //Called more or less just to print out that fuel capacity was reached
                currentFuel = 30;
            }

            }
            if (currentPlanet == p2.getPlanet()) //Planet 51-Pegasi
            {

                //The sleep function is used expressly to make the text pretty in the planets. It will only show up in this massive while loop
                if(Pegasid >=1)
                {
                    cout << "Why in the world would you want to come here? Literally? There's NOTHING HERE!\n"; sleep(2);
                    cout << "Enter 'stay' to stay in this useless planet, or enter 'leave' to go somewhere more productive\n"; sleep(2);
                    string data22;
                    cin >> data22;
                    if(data22 == "stay")
                    {
                        cout << "Got a thick skull, don't you?\n"; sleep(2);
                        cout << "UGH. FINE. GO BACK TO THE DUSTY PLANET\n"; sleep(2);
                        goto dumb; //Kicks the program down to where the user would explore the planet
                    }
                    if(data22 == "leave")
                    {
                        cout << "Smart play. 10's all around. \n"; sleep(2);
                        cout << "Please enter 'system' or 'travel' to continue...\n";
                        break;
                    }
                }
                //cout << "Pegasid value " <<Pegasid << endl;
                Pegasid ++;
                //cout << "Pegasid value " <<Pegasid << endl;
               dumb:cout << "You walk around the Barren planet for a while and find nothing of interest."<<endl<< "Whatever used to be here has become nothing more than dust."<<endl; //"dumb: is the receiving end of the goto when prompted to return or not
                cout << "Enter 'leave' to continue\n";
            }
            if (currentPlanet == p3.getPlanet()) //Planet PSR
            {
                if(PSRCounter >= 1)
                {
                    cout << "After hiking around the planet again, you find the same wreckage. Although gaining nothing, at least it was a calming trip." << endl;
                    cout << "Please enter 'travel' or 'system' to continue..." << endl;
                    break;
                }


                cout << "The forest planet is calming, and after some mild hiking you come across the wreckage of an ancient looking starship."<<endl<< "You are able to salvage: " << new_fuel - 9 << " fuel from the debris" << endl;

                if(scout == true)
                {
                    q.scoutMaxF(currentFuel+new_fuel-9);
                    currentFuel = currentFuel+new_fuel-9;
                }
                if(freighter == true)
                {
                    L.freighterMaxF(currentFuel+new_fuel-9);
                    currentFuel = currentFuel+new_fuel-9;
                }
                //cout << "PSRCounter value " <<PSRCounter << endl;
                PSRCounter ++;
                //cout << "PSRCounter value " <<PSRCounter << endl;
                cout << "Please enter 'travel' or 'system' to continue..." << endl;
                break;
            }
            if (currentPlanet == p4.getPlanet()) //Planet Gliese-876d
            {
                if(GliesedCounter == 1)
                {
                    cout<<"You and your crew have been here and done that. None of you have any desire to even land here again, so you settle to\n";
                    cout<<"orbit the planet.\n";
                    cout<<"Please enter 'travel' or 'system' to continue..."<<endl;
                    break;
                }
              cout<< "As you disembark from your starship you can instantly feel a wave of heat roll over you."
            <<endl<< "Your protective bodysuits wont last long."
            <<endl<< "Eventually after exploring you come to a research facility."
            <<endl<< "Just before reaching the entrance of the facility, out of nowhere the ground rumbles and splits open beneath you."
            <<endl<< "Two of your crew mates are engulfed by the trench, and meet a fiery demise"
            <<endl<< "However, the researchers at the facility take pity on you, and offer you: " << new_fuel-7 <<" fuel for your loss." <<endl<<endl;
            if(scout == true)
            {
                q.scoutMaxC(currentCrew-2); //Called more or less just to print out that crew capacity was reached
                currentCrew = currentCrew-2;
                q.scoutMaxF(currentFuel+new_fuel-7); //Called more or less just to print out that fuel capacity was reached
                currentFuel = currentFuel+new_fuel-7;
            }
            if(freighter == true)
            {
                L.freighterMaxC(currentCrew-2); //Called more or less just to print out that crew capacity was reached
                currentCrew = currentCrew-2;
                L.freighterMaxF(currentFuel+new_fuel-7); //Called more or less just to print out that fuel capacity was reached
                currentFuel = currentFuel+new_fuel-7;
            }

            cout << "Please enter 'travel' or 'system' to continue...\n";
           // cout << "GliesedCounter value " <<GliesedCounter << endl;
            GliesedCounter ++;
           // cout << "GliesedCounter value " <<GliesedCounter << endl;
            break;

            }
            if (currentPlanet == p5.getPlanet()) //Kepler-11f
            {
                if(KeplercCounter >= 1)
                {
                    cout << "You've been here already. It's an ocean. What could you possibly stand to gain from coming back here?\n"; sleep(2);
                    cout << "If for some crazy reason you want to come back, enter 'stay' to stay, or 'leave' to do the smart thing and leave.\n";
                    string data21;
                    cin >> data21;
                    if(data21 == "stay")
                    {
                        cout << "Glutton for punishment, aren't you?\n"; sleep(2);
                        cout << "Suit yourself.\n";
                        goto nutcase; //Sends user down to the exploration part of the planet
                    }
                    if(data21 == "leave")
                    {
                        cout << "FINALLY! AN INTELLIGENT MOVE!\n"; sleep(2);
                        cout << "Please enter 'system' or travel' to continue...\n";
                        break;
                    }
                }
               // cout << "KeplercCounter value " <<KeplercCounter << endl;
                KeplercCounter++;
             //   cout << "KeplercCounter value " <<KeplercCounter << endl;
                nutcase:cout<< "Before leaving your starship you and your crew equip diving gear and oxygen tanks." //receiving end of coming back to the planet
                <<endl<< "As you plunge into the watery depths of this large ocean planet, you can see the ocean's surface begin to fade away behind you."
                <<endl<<  "The light begins to fade, slowly."
                <<endl<< "You have plunged into darkness, beneath you nothing but black for miles."
                <<endl<< "Will you keep going?"<<endl<<endl<<"Enter: 'yes' to continue your decent, or 'no' to return to the surface."<<endl;

                    while (data3=="visit")
                    {
                       cin >> data4;

                       if(data4=="yes")
                       {
                          cout<<endl<<"You decide to continue your plunge into the icy darkness below."<<endl;
                          cout<<"With nothing but the lights from your diving gear to guide you, you fall ever so faster into the depths."
                          <<endl<<"The darkness and the quiet last for a while, but soon you feel a strange stirring beneath you."
                          <<endl<<"You feel a ripple of water knock you aside, as if a torpedo had whistled by you."
                          <<endl<<"You look around and see blood in the water."
                          <<endl<<"One of your crew members is gone." <<endl;
                          //q.scoutMaxC(currentCrew-1);
                          currentCrew=currentCrew-1;
                            if(currentCrew<=0)
                                {

                                cout <<endl;
                                cout << "****************************************************************************************************************\n";
                                cout << "* Your mission to travel the solar system failed. Due to your negligence as a captain your whole crew is dead. *\n";
                                cout << "*                                                GAME OVER                                                     *"<< endl;
                                cout << "**********************************r******************************************************************************\n";
                                    return 0;

                                }
                          cout<< "Would you like to continue?" << endl;
                            while (data4=="yes")
                            {
                                cin >>data5;
                                if(data5=="yes")
                                {
                                    cout << "You decide to continue your descent against the will of you crew."
                                    <<endl<<"After a short while longer of falling you feel the water start to stir and rumble."
                                    <<endl<<"It seems that something has been awoken."
                                    <<endl<<"Left and right you feel water being displaced around you."
                                    <<endl<<"Now you see what had taken your last crew member."
                                    <<endl<<"A swarm of shark-like creatures are upon you, moving so fast their motion is blurred."
                                    <<endl<<"The frenzy around you, and in a matter of minutes, you and your crew have become fish food." <<endl;
                                    currentCrew = currentCrew - 100;
                                    if(currentCrew<=0)
                                        {

                                        cout <<endl;
                                        cout << "****************************************************************************************************************\n";
                                        cout << "* Your mission to travel the solar system failed. Due to your negligence as a captain your whole crew is dead. *\n";
                                        cout << "*                                                GAME OVER                                                     *"<< endl;
                                        cout << "**********************************r******************************************************************************\n";
                                            return 0;

                                        }

                                }
                                if(data5=="no")
                                {
                                    cout<<"You decide it's best to head up now, no telling what happened to your crew member."
                                    <<endl<<"Best not to take chances."<<endl;
                                    cout << "Please enter 'leave' to continue...\n";
                                    goto leave;



                                }

                            }


                       }

                       if(data4=="no")
                       {

                           cout<<endl<<"You and your crew decide to return to the safety of the surface."<<endl;
                           cout << "Please enter 'leave' to continue...\n";
                           goto leave;

                       }


                    }




            }
            if (currentPlanet == p6.getPlanet()) //Planet Kepler-452b
            {
                if(KeplerdCounter >= 1)
                {
                    cout << "You and your crew have been there and done that. Even if you wanted to, you're pretty certain your crew\n";
                    cout << "would kill you before you could even plot a course to land again, so you opt to stay in orbit\n";
                    cout << "Please enter 'travel' or 'system' to continue...\n";
                    break;
                }
                //cout << "KeplerdCounter value " <<KeplerdCounter << endl;
                KeplerdCounter ++;
              //  cout << "KeplerdCounter value " <<KeplerdCounter << endl;
                string data6;
                cout <<"Your ship touches down on Kepler-452b. It's dark, and there's something in the atmosphere\n corrupting the readings on the sensors.\n";
                cout <<"Do you want to press on? Enter yes/no.\n";
                cin >> data6;
                if(data6 == "yes")
                {
                    cout << "Against yours (and your crew's) better judgment, you don your suits and exit the ship. The ground is a horrifying\n";
                    cout << "dull purple. It almost seems to pulse with each footfall. Your senses are screaming at you to LEAVE. Will you?\n";
                    string data7;
                    cin >> data7;
                    if(data7 == "no")
                    {
                        cout << "Although your entire crew is now telling you to return to the ship, you stubbornly keep going. \n"; sleep(2);
                        cout << "The ground feels softer and softer beneath your feet. You begin to notice that the dull roar of your crew's complaints getting quieter\n"; sleep(2);
                        cout << "Maybe they returned to the ship, maybe they didn't.\n"; sleep(5);
                        cout << "You finally reach an outcropping that looks a little too geometrical to be natural. Inside you find a couple units of fuel. Was it worth it?\n"; sleep(2);
                        currentFuel = currentFuel+2;
                        cout << "You then return to your ship. It's quiet as a church. Clearly, they never made it back\n"; sleep(2);
                        cout << "Will you go back to  find them?" << endl;
                        string data8;
                        cin >> data8;
                        if(data8 == "yes")
                        {
                            cout << "You decide to go back for them, for better or worse.\n"; sleep(2);
                            cout << "Back on the absolutely repulsive planet, you retrace your steps.\n"; sleep(2);
                            cout << "You call out, and then over your comms you can hear the panicked chatter of your crew. You call out to them, and after a time you reunite,\n";
                            cout << "returning to your ship to get off of this godforsaken planet\n"; sleep(2);
                            cout << "Please enter 'travel' or 'system' to continue...\n";
                            cout <<"New fuel level: " << currentFuel << endl;
                            break;
                        }
                        if(data8 == "no")
                        {
                            cout << "Really? What kind of captain are you? In any event, you leave your crew to their inevitable doom on that hellhole of a planet\n";
                            cout << "and rocket yourself back into orbit. I cannot believe YOU'RE exploring this system.\n";
                            currentCrew = 0;
                            cout <<"New fuel level: " << currentFuel << endl;
                            cout <<"Your crew is now: "<< currentCrew << ". Coward.\n";
                            cout << "Please enter 'system' or 'travel' to continue...\n";
                            eE2 = 1;
                            break;
                        }


                    }
                    if(data7 == "yes")
                    {
                        cout << "With resounding approval, you and your crew scamper back to the ship, fleeing the planet as fast as possible\n";
                        cout << "Please enter 'system' or 'travel' to continue...\n";
                        break;
                    }

                }
                if(data6 == "no")
                {
                    cout << "With resounding approval, you launch back into orbit, deciding it better to leave that planet a mystery\n";
                    cout << "Please enter 'system' or 'travel' to continue...\n";
                    break;
                }

            }

            if (currentPlanet == p7.getPlanet()) //Planet 1RXS
            {
                if(oneRXS >= 1)
                {
                    cout << "You've been here once before. Are you sure you want to return?\n";
                    cout << "Enter yes/no...\n";
                    string data13;
                    cin >> data13;
                    if(data13 == "yes")
                    {
                        sleep(5);
                        cout << "Well. That was foolish. They warned you not to return, and you still tried to.\n"; sleep(5);
                        cout << "Before you could even break atmosphere your sensors lit up.\n"; sleep(5);
                        cout << "'WARNING: MISSILE LOCK DETECTED'\n"; sleep(2);
                        cout << "Before you could even blink your ship was blown to smithereens.\n"; sleep(3);

                        cout << "***************************\n";
                        cout << "GAME OVER, LEARN TO LISTEN\n";
                        cout << "***************************\n";
                        return 0;

                    }
                    if(data13 == "no")
                    {
                        cout << "Smart move. You steer clear of the planet and continue to orbit in search of another\n"; sleep(2);
                        cout << "Please enter 'travel' or 'system' to continue...\n";
                        break;
                    }

                }
               // cout << "oneRXS value " << oneRXS << endl;
                oneRXS ++;
               // cout << "oneRXS value " << oneRXS << endl;
                cout << "Your ship touches down on the craggy surface of this glowing green planet. 'Radioactive' is an understatement of the century.\n"; sleep(2);
                cout << "the Geiger counter is chattering madly at the outside radioactivity.\n";
                cout << "Will you disembark? enter yes/no\n";
                string data10;
                cin >> data10;
                if(data10 == "yes")
                {
                    cout << "Your crew gives you a sideways glance as they get into their suits. You step into the pressurized chamber\n"; sleep(2);
                    cout << "And are instantly greeted with your suit's Geiger counter. Clearly, this is not a hospitable planet.\n"; sleep(2);
                    cout << "What are you hoping to find? Most importantly, will you continue?\n";
                    string data11;
                    cin >> data11;
                    if(data11 == "yes")
                    {
                        cout << "Alright, crazy one. You and your crew leave. There is an eerie beauty to the place.\n";
                        cout << "You continue on for a while, following the cracked ground and seemingly burnt shrubbery\n";
                        cout << "Much to yours and your crew's surprise, there is a settlement in the distance.\n";
                        cout << "Will you investigate?\n";
                        string data12;
                        cin >> data12;
                        if(data12 == "yes")
                        {
                            cout << "The team arrives at the village. There are rather human-esque figures moving around.\n"; sleep(2);
                            cout << "They're in suits similar to yours. You make contact.\n"; sleep(2);
                            cout << "They seem strangely friendly. they offer you either 3 units of fuel or a couple of crew members.\n"; sleep(2);
                            cout << "Choose wisely! enter '1' for fuel, enter '2' for crew...\n";
                            int choice = 0;
                            cin >> choice;
                            if(choice == 1)
                            {
                                cout << "They give you the fuel and bid you farewell. They also recommend that you not return.\n"; sleep(5);
                                currentFuel = currentFuel +3;
                                if(currentFuel > 10)
                                {
                                    currentFuel = 10;
                                }
                                cout << "Bewildered, you and your crew return to the ship and head back to orbit\n";
                                cout << "New fuel level: " << currentFuel << endl;
                                cout << "Please enter 'travel' or 'system' to continue...\n";
                                break;
                            }
                            if(choice == 2)
                            {
                                cout << "They give assign you some people and bid you farewell. They also recommend that you not return.\n"; sleep(5);
                                currentCrew = currentCrew +2;
                                if(currentCrew > 5)
                                {
                                    currentCrew = 5;
                                }
                                cout << "Bewildered, you and your crew return to the ship and head back to orbit\n";
                                cout << "New crew level: " << currentCrew << endl;
                                cout << "Please enter 'travel' or 'system' to continue...\n";
                                break;
                            }
                        }
                        if(data12 == "no")
                        {
                            cout << "You and your crew decide to let sleeping dogs lie and leave. You return to your ship and return to orbit\n";
                            cout << "Please enter 'travel' or 'system' to continue...\n";
                            break;
                        }
                    }
                    if(data11 == "no")
                    {
                        cout << "You and your crew decide to let sleeping dogs lie and leave. You return to your ship and return to orbit\n";
                        cout << "Please enter 'travel' or 'system' to continue...\n";
                        break;
                    }
                }
                if(data10 == "no")
                {
                    cout << "You and your crew decide to let sleeping dogs lie and leave. You return to orbit\n";
                    cout << "Please enter 'travel' or 'system' to continue...\n";
                    break;
                }

            }
            if(currentPlanet == p8.getPlanet()) //Planet Gliese-581
            {
                if(GliesebCounter >= 1)
                {
                    cout << "You've already been here before. Is there anything else of value here?\n";
                    cout << "enter 'yes' to land, enter 'no' to travel elsewhere\n";
                    string data17;
                    cin >> data17;
                    if(data17 == "yes")
                    {
                        goto next;
                    }
                    if(data17 == "no")
                    {
                        cout << "Probably for the better. No sense in wasting time!\n"; sleep(2);
                        cout << "Please enter 'travel' or 'system' to continue...\n";
                        break;
                    }
                }
               // cout << "GliesebCounter value " << GliesebCounter << endl;
                GliesebCounter ++;
               // cout << "GliesebCounter value " << GliesebCounter << endl;
                next:cout << "Ah, Gliese-581. A tropical paradise. Your ship sets down gently on an island. \n"; sleep(2);
                cout << "Trees very much reminiscent of palm trees of 4546B sway in the breeze. \n"; sleep(2);
                cout << "A feeling of serenity washes over you and your crew as you look out a porthole. \n"; sleep(2);
                cout << "Will you disembark? enter yes/no \n";
                string data14;
                cin >> data14;

                if(data14 == "yes")
                {
                    cout << "You and your crew excitedly exit the ship. Alpha Centauri gleams brightly in the blue sky\n"; sleep(2);
                    cout << "The waves are a shiny teal. Do you wish to take a break for a while?\n";
                    string data15;
                    cin >> data15;
                    if(data15 == "yes")
                    {
                        cout << "You decide to take a rest. You stretch out in the sand next to your ship and nod off \n"; sleep(2);
                        for(int i = 0; i < 3; i++)
                        {
                            cout <<"..."<<endl; sleep(2);
                        }
                        cout << "You finally come to after an unknown amount of time. You look around, slightly dazed. \n"; sleep(2);
                        cout << "Suddenly it strikes you. Your crew is gone. Instantly the serenity wears off. \n"; sleep(2);
                        cout << "You look around the island trying to find a trace of where your crew went... \n"; sleep(4);
                        cout << "To your horror, you find a bright red trail leading to the trees, where you see\n"; sleep(2);
                        cout << "pearly white bones, protruding out of the ground.\n"; sleep(2);
                        cout << "You instantly board your ship and leave. You have lost everyone except for yourself.\n"; sleep(5);
                        cout << "Unable to deal with the guilt, you chart an unknown course, never to be heard from again.\n";
                        cout << "********************************\n";
                        cout << "GAME OVER, SLEEP IS FOR THE WEAK\n";
                        cout << "********************************\n";
                        return 0;
                    }
                    if(data15 == "no")
                    {
                        cout << "Despite the invariably beautiful terrain, you are here for a reason.\n"; sleep(2);
                        cout << "That reason? Knowledge! Resources! This ship can't run without them!\n"; sleep(2);
                        cout << "You set off with your crew toward a jagged peak.\n"; sleep(2);
                        cout << "Your material scanner indicates that you are atop of a fuel vein\n"; sleep(2);
                        cout << "Do you wish to dredge for fuel? You'll get 5 units.\n";
                        string data16;
                        cin >> data16;
                        if(data16 == "yes")
                        {
                            cout << "Splendid! You got 5 units of fuel!\n"; sleep(2);
                            currentFuel = currentFuel+5;
                            if(currentFuel >= 10)
                            {
                                currentFuel = 10;
                            }
                            cout << "Your new fuel level is: " << currentFuel << endl;
                            cout << "You and your crew then return to the ship, so as to continue your adventure.\n";
                            cout << "Please enter 'travel' or 'system' to continue...\n";
                            break;
                        }
                        if(data16 == "no")
                        {
                            cout << "Deciding you have enough fuel, you and your crew decide to head back to the ship.\n"; sleep(2);
                            cout << "Please enter 'travel' or 'system' to continue...\n";
                            break;

                        }
                    }
                }
                if(data14 == "no")
                {
                    cout << "For whatever reason, and to the dismay of your crew, you decide not to disembark at all\n"; sleep(2);
                    cout << "You launch your ship back into orbit, and plot a course for another planet.\n"; sleep(2);
                    cout << "Please enter 'travel' or 'system' to continue...\n";
                    break;
                }
            }
            if(currentPlanet == p9.getPlanet()) //Planet PSR-A
            {
                if(PSRACounter >= 1)
                {
                    cout << "You've been here already. It's frickin' cold. Are you sure you want to go back here?\n"; sleep(2);
                    cout << "Enter yes/no\n";
                    string data18;
                    cin >> data18;
                    if(data18 == "yes")
                    {
                        cout << "Suit yourself.\n"; sleep(2);
                        goto brr;
                    }
                    if(data18 == "no")
                    {
                        cout << "Probably for the best. Your crew agrees and you stay in orbit.\n"; sleep(2);
                        cout << "Please enter 'system' or 'travel' to continue...\n"; sleep(2);
                        break;
                    }
                }
               // cout << "PSRACounter value " << PSRACounter << endl;
                PSRACounter ++;
               // cout << "PSRACounter value " << PSRACounter << endl;
                brr:cout << "You're just touching down on this planet and you're already cold.\n"; sleep(2);
                cout << "The thermometer is reading a whopping -32* Celsius. It's cold.\n"; sleep(2);
                cout << "However, you are here for a reason. There's a distress beacon here. \n"; sleep(2);
                cout << "There is a large question before you. Do you risk life and limb to investigate?\n"; sleep(2);
                cout << "Enter yes/no\n";
                string data16;
                cin >> data16;
                if(data16 == "yes")
                {
                    cout << "Braving the cold, you decide to go out and investigate.\n"; sleep(2);
                    cout << "With practically sideways sleet and snow well up over your knees, you and your crew trudge forward.\n"; sleep(2);
                    for(int i = 0; i < 4; i++)
                    {
                        cout << "..." << endl; sleep(2);
                    }
                    cout << "It seems that you have been trudging forever. You look down at your navigator, and it still claims you are headed toward the beacon.\n"; sleep(2);
                    cout << "Do you continue? enter yes/no.\n";
                    string data17;
                    cin >> data17;
                    if(data17 == "yes")
                    {
                        cout << "You continue to trudge forward. Your crew grimly agrees.\n"; sleep(8);
                        cout << "After hours of braving the frigid cold, you see a glowing red light.\n"; sleep(2);
                        cout << "It's the aft end of a downed ship! With newfound vigor, you and your crew descend upon the wreckage.\n"; sleep(2);
                        cout << "You can see that the ship cracked hard on its descent to the planet.\n"; sleep(2);
                        cout << "There are bits of debris strewn about everywhere. The morale of your crew begins to plummet as the truth of the situation sets in.\n"; sleep(2);
                        for(int i = 0; i < 3; i++)
                        {
                            cout << "..." << endl; sleep(2);
                        }
                        cout << "Finally you can see the glow of a fire within.\n"; sleep(2);
                        cout << "You announce you and your team, and there is a great commotion.\n"; sleep(2);
                        cout << "Quickly, you see 6 delighted faces peering out through the icy windows.\n"; sleep(2);
                        cout << "They invite you inside, to which you agree. They feed you and your crew\n"; sleep(2);
                        cout << "You stay the night there. In the morning you depart. You take as many of them with you as you can.\n"; sleep(2);
                        cout << "You arrange a rescue ship for those you cannot fit, and you take the rest aboard as your crew.\n"; sleep(2);
                        cout << "As a token of gratitude, the survivors give you 8 units of fuel.\n";
                        currentCrew = currentCrew + 6;
                        if(currentCrew > 5)
                        {
                            currentCrew = 5;
                        }
                        currentFuel = currentFuel+8;
                        if(currentFuel > 10)
                        {
                            currentFuel = 10;
                        }
                        cout << "Your new fuel level is: " << currentFuel << endl;
                        cout << "Your new crew level is: " << currentCrew << endl;
                        cout << "Morally pleased, you return to your ship. Job well done with this planet.\n"; sleep(2);
                        cout << "Please enter 'system' or 'travel' to continue...\n";
                        break;
                    }
                    if(data17 == "no")
                    {
                        cout << "That expended energy for naught, you and your crew turn back.\n"; sleep(2);
                        cout << "Hopefully that distress beacon was nothing.\n"; sleep(2);
                        cout << "Once back aboard, you and your crew launch back into orbit.\n";
                        cout << "Please enter 'system' or 'travel' to continue...\n";
                        break;
                    }

                }
                if(data16 == "no")
                {
                    cout << "You decide the cold is too much. Your crew half heartedly agrees.\n"; sleep(2);
                    cout << "Hopefully that distress beacon was nothing.\n"; sleep(2);
                    cout << "Please enter 'system' or 'travel' to continue...\n";
                    break;
                }
            }
                if (currentPlanet == p10.getPlanet()) //Planet Kepler-62f
                {
                    if(KeplerBCOunter >= 1)
                    {
                        cout << "You and your crew have already been here and have absolutely no desire to have your ankles attacked again\n"; sleep(2);
                        cout << "so you certainly have zero intent of landing here again. Enter 'travel' or 'system' to continue...\n";
                        break;
                    }
                   // cout << "KeplerBCOunter value " << KeplerBCOunter << endl;
                    KeplerBCOunter++;
                   // cout << "KeplerBCOunter value " << KeplerBCOunter << endl;
                    cout << "Ah, Kepler-62f. It's as if Zeus and the deadliest creature alive had a deadly planet baby.\n"; sleep(2);
                    cout << "Lightning cracks and there are massive thunderheads scudding across the sky. \n"; sleep(2);
                    cout << "Fair warning: If you think anything has been bad before, this place dwarfs it.\n"; sleep(2);
                    cout << "I'm pretty sure your ship even quaked with fear at the idea of landing here.\n"; sleep(2);
                    cout << "Do you wish to set down and disembark? Enter yes/no \n"; sleep(2);
                    string data19;
                    cin >> data19;
                    if(data19 == "yes")
                    {
                        cout << "Going into the belly of the beast, eh? Your call.\n"; sleep(3);
                        cout << "... It's not like the lives of your crew are in your hands.\n"; sleep(2);
                        cout << "In any case, you put on your protective suits and decide to do a little exploring.\n"; sleep(2);
                        for(int i = 0; i < 5; i++)
                        {
                            cout << "..." << endl; sleep(2);
                        }
                        cout << "Quick as a flash you hear a yelp. The lifeforms on this planet don't take kindly to aliens, and you are an alien.\n"; sleep(2);
                        cout << "Soon the entire crew is shouting for their lives, as they each get attacked ferociously by the local wildlife.\n"; sleep(2);
                        cout << "Quickly! You must decide. Do you try to fight these ankle biters off or do you high tail it for the ship?\n";
                        cout << "enter run/fight to continue... \n";
                        string data20;
                        cin >> data20;
                        if(data20 == "fight")
                        {
                            cout << "Against EVERYONE'S BETTER JUDGEMENT you stand your ground.\n"; sleep(1);
                            cout << "Your crew, already irritated at being chewed on, begins to fight back.\n"; sleep(4);
                            cout << "...\n"; sleep(2);
                            cout << "Well I'll be. These lifeforms are supposed to be dangerous, but a good swing to the snout sends them running!\n"; sleep(2);
                            cout << "Well done, captain. I thought sure it would be the end of all of you.\n"; sleep(2);
                            cout << "So you and your battered crew continue. There are bones lying everywhere, as well as debris of long since destroyed ships.\n"; sleep(2);
                            cout << "There really isn't anything else to note here. It's just a planet full of - come to find out - ankle biting creatures.\n"; sleep(2);
                            cout << "With the ghost of a smile, you and your crew board your ship again, and head back into orbit.\n";
                            cout << "Please enter 'travel' or 'system' to continue... \n";
                            break;
                        }
                        if(data20 == "run")
                        {
                            cout << "In tandem, you all turn tail and run. You can hear the screams of your crew as they get picked off one by one.\n"; sleep(2);
                            for(int i = 0; i < 5; i++)
                            {
                                cout << "..." << endl; sleep(2);
                            }
                            cout << "The screaming stops. You can see the door to your ship. You are just about to get in the airlock when...\n"; sleep(8);
                            cout << "You never made it. Your hand was on the button, but the lifeform got the finishing blow as your back was turned.\n"; sleep(3);
                            cout << "***********************************************************\n";
                            cout << "GAME OVER, STAND YOUR GROUND, EVEN IF IT DOESN'T MAKE SENSE\n";
                            cout << "***********************************************************\n";
                            return 0;

                        }
                    }
                    if(data19 == "no")
                    {
                        cout << "I'd say that's a solid plan, captain. Your ship hardly even touches the ground before you flee back to the safety of orbit\n"; sleep(2);
                        cout << "Please enter 'travel' or 'system' to continue... \n";
                        break;

                    }
                }

            if(currentCrew<0)
            {

            cout <<endl;
            cout << "****************************************************************************************************************\n";
            cout << "* Your mission to travel the solar system failed. Due to your negligence as a captain your whole crew is dead. *\n";
            cout << "*                                                GAME OVER                                                     *"<< endl;
            cout << "**********************************r******************************************************************************\n";
                return 0;

            }





        }

        leave:if (data3 == "leave"){

            cout << endl;
            cout << "You have left: " << currentPlanet<<endl << "Enter 'travel' to travel to a new planet, or enter 'system' to view the solar system map again" << endl;

            break;


        }
    if(homePlanet && PSRCounter && GliesedCounter && KeplerBCOunter && KeplerdCounter && GliesebCounter && PSRACounter && oneRXS && KeplercCounter && Pegasid >= 1) //If this win condition is met;
        //These counters go up each time you go to a planet. If ALL of them are 1, YAY! The game is won
        {
            cout <<"*************************************************************\n";
            cout <<"                    CONGRATULATIONS!\n";
            cout <<"                    YOU WON THE GAME!\n";
            cout <<"*************************************************************\n";
            cout <<"Well done captain. A file detailing how many times you landed at each planet, as well as your fuel and crew counts will\n";
            cout <<"be output to a file called 'cgrtsuwon.txt'! Thank you for playing!";
            ofstream uwon("cgrtsuwon.txt");
            uwon << "You landed on 4546B " << homePlanet << " times!\n";
            uwon << "You landed on 51-Pegasi " << Pegasid <<" times!\n";
            uwon << "You landed on PSR " << PSRCounter << " times!\n";
            uwon << "You landed on Gliese-876d " << GliesedCounter << " times!\n";
            uwon << "You landed on Kepler-11f " << KeplercCounter << " times!\n";
            uwon << "You landed on Kepler-452b " << KeplerdCounter << " times! \n";
            uwon << "You landed on 1RXS " << oneRXS << " times!\n";
            uwon << "You landed on Gliese-581 " << GliesebCounter << " times! \n";
            uwon << "You landed on PSR-A " << PSRACounter << " times!\n";
            uwon << "You landed on Kepler-62f " << KeplerBCOunter << " times!\n";
            uwon << "Your ending fuel level: " << currentFuel << endl;
            uwon << "Your ending crew level: " << currentCrew << endl;
            uwon << "Congratulations, captain!\n";
            return 0;
        }










        }



        }

    }
}
