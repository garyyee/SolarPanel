/*
 ============================================================================
 Name        : ACS223-002 Assessment
 Author      : Gary Yee Siew Wah
 Copyright   : 2016
 Reg. No.    : 150144216
 Date        : 14th Nov 2016
 Description : The program allow client to pick appliance from the list and
               compare 3 solar panels sizes.
 ============================================================================
 */

 /*List of Libraries*/
#include <iostream>
#include <string>
#include <fstream>
#include "appliance.h"
#include "solarPanel.h"
#include <iomanip>
using namespace std;


//constructor 1
appliance::appliance()
{
    season =0 ;
    snumApp=0;
}


//public function findSeason
int appliance::findSeason(char season)
{
    // set variable
    int Season;


    if ( season == 's' || season == 'S')  // check the condition
    {
        cout<<"For SUMMER, there are 6 Hours of sunlight"<<endl;  // print to the screen
        Season=6;                         // set variable as 6
    }

    if ( season == 'w' || season == 'W')  // check the conditon
    {
        cout<<"For WINTER, there are 1 Hour of sunlight"<<endl;  // print to the screen
        Season=1;                         // set variable as 1
    }

    return Season ;         // return the variable
}

//public function select
int appliance::select()
{   // initialise variable
    int snumApp;
cout << " Please select how many appliance? \n =";                                  // display to the screen
while (true)                                                                        // assign it always true
  {
  cin >> snumApp;                                                                    // input the variable

  if ( (snumApp >= 1) && (snumApp <= 38)&&(cin) )                                     // check the condition
    break;                                                                          // break the condition

  cin.clear();                                                                      // clear the variable
  cin.ignore( 500, '\n' );                                                         // ignore the variable
  cout << " Please select how many appliance? \n =";                                // print to the screen
  }
  return snumApp;   // return the variable
}

