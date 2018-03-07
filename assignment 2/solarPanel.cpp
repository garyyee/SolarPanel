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


//constructor
solarPanel::solarPanel()
{
  solarWatt =0;
  numSolar =0;
}

//public function selectWatt
int solarPanel::selectWatt (int solarWatt)
{
    cout<< " Please select the ONE solar panel size : 10 , 40 , 80 , 100 , 150 , 250 "<<endl << " =";  // print to the screen
    cin>> solarWatt;                          // input the variable

    while ( solarWatt != 10 && solarWatt != 40 && solarWatt != 80 && solarWatt != 100 && solarWatt != 150 && solarWatt != 250)  // check the condition
    {
    cout<< " Please select the ONE solar panel size : 10 , 40 , 80 , 100 , 150 , 250 "<<endl << " =";   // print to the screen
    cin >> solarWatt;                        // input the variable
    }

    return solarWatt;                        // return the variable
}

//public function calPanel
int solarPanel::calPanel(float numSolar,int solar,int sol)
{   // list of variable
    int x;
    x=numSolar+0.5;

   sol=x/solar;                       // calculate the number of solar panel
   cout<<"Total number of solar panel is "<<sol;     // print the screen
   return sol;                                // return the variable
}

//public function calArea
float solarPanel::calArea(int solar1, int solar)
{
    // set variable
    float ans;

  //  cout<<"Since you choose :"<<solar<<endl;                     // print to the screen
    if (solar == 10)                                             // if the solar is 10
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;              // print to the screen
        ans=solar1*0.0938;                                         // calculate the answer
        cout<<"The Total roof area is"<<ans;                       // print to the screen
    }
   else if (solar == 40)                                            // if the solar is 40
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;               // print to the screen
        ans=solar1*0.3120;                                           // calculate the answer
        cout<<"The Total roof area is"<<ans;                          // print to the screen
    }
   else if (solar == 80)                                             // if the solar is 80
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;                // print to the screen
        ans=solar1*0.5978;                                            // calculate the answer
        cout<<"The Total roof area is"<<ans;                          // print to the screen
    }
else if (solar == 100)                                                // if the solar is 100
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;                 // print to the screen
        ans=solar1*0.6968;                                              // calculate the answer
        cout<<"The Total roof area is"<<ans;                           // print to the screen
    }
  else if (solar == 150)                                              // if the solar is 150
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;                 // print to the screen
        ans=solar1*0.9983;                                             // calculate the answer
        cout<<"The Total roof area is"<<ans;                          // print to the screen
    }
    else if(solar == 250)                                              // if the solar is 250
    {
        cout<<endl<<"For solarWatt is "<<solar<<endl;                  // print to the screen
        ans=solar1*1.65;                                                // calculate the answer
        cout<<"The Total roof area is"<<ans;                            // print to the screen
    }
    return ans;                                                        // return the variable
}
