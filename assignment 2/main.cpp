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

/*Void function for pass by reference*/
void solarTotal(float&,float);

/*The main function*/
int main()
{

  /*List of variables*/
    char season;
    float hourForApp[38];
    int solarWatt;
   int num[38];
    float rate[38];
    string name[38];
    int numApp;
    int choose;

    /*Class Function*/
    solarPanel panel[3];
    appliance app;


    cout <<"please select season (w  for winter or s  for summer)\n=";             // the print to the screen
    cin>>season;                                                                   //  input into variable

     while ( season != 's' && season != 'w' && season != 'S' && season != 'W')     // reject the unwanted input
    {
    cout <<"please select seasons (w = winter or s = summer) \n = ";               // the print to the screen
    cin>>season;                                                                   // input into the variable
    }

    app.findSeason(season);                                                        // find the season from the class appliance

    int n=0;                                                                        // assign variable
    ifstream myFile;                                                                // assign the file
    myFile.open("AppliancePower.txt");                                              // open the file
    if (myFile.is_open())
      while(!myFile.eof() && n < 38)                                                // input the file into the array
    {
       {  // file into the array
           myFile >> num[n];
           myFile >> name[n];
           myFile >> rate[n];
           cout<< setw(2) <<num[n] << setw(20) << name[n] << setw(15)<< rate[n]<<"W" << endl;   // display to the screen
           n++;                                                                      // increment the variable
       }
    }else
    {
        cout<< " File not open!";                                                   // Display to the screen
    }
    myFile.close();                                                                 // close the file

    cout<<"\n\n";                                                                   // create space

    numApp=app.select();                                                            // from the class the select number of appliance

    // assign the variable
    float newRate[38];
    string newName[38];

    for (int i =0 ; i<numApp ; i++)                                                  // assign the for loop
    {
        cout << " Please choose the appliance? \n =";                                // print to the screen
        do{                                                                          // do while loop

        cin>> choose;                                                                // input the variable
        if ((choose >= 1) && (choose <= 38)&& (cin)  )                                // check the condition
        break;                                                                       // break the loop

        cin.clear();                                                                 // clear the variable
        cin.ignore( 500, '\n' );                                                    // ignore the variable
       cout << " Please choose the appliance? \n =";                                 // print to the screen
        }while(choose<1 || choose>38);                                               // check the range

        newRate[i]=rate[choose-1];                                                   // arrange new variable
        newName[i]=name[choose-1];                                                   // arrange new variable
        cout<<" You select " << "<< "<<  newName[i] << setw(10)<< newRate[i] <<"W"<< " >>"<< endl;    // print to the screen
    }

   cout<<"\n\n You choose "<< season << " which is ";                                // print to the screen

   app.findSeason(season);                                                           // use appliance class

    for (int i =0 ; i<numApp ; i++)                                                  // use for loop
    {
        do{                                                                          // use do while loop
        cout <<"For each appliance there are 24 hours, please enter number of hour for "<<newName[i] <<"\n=";              // print to the screen
        cin >> hourForApp[i];                                                        // input the variable

        if ( ( hourForApp[i]>= 0) && (hourForApp[i] <= 24) && (cin) )                                // check the condition
        break;                                                                       // break the loop

        cin.clear();                                                                 // clear the variable
        cin.ignore( 500, '\n' );

      }while(hourForApp[i] < 0 || hourForApp[i] > 24);                               // check the condition
    }


    float sum=0;                                                                     // assign new variable
    for (int i =0 ; i<numApp ; i++)                                                  // use for loop
    {
       sum+=newRate[i]*hourForApp[i];                                                // calculate the total sum of power
    }

    cout<<"The total sum is"<<sum<<endl;                                             // display to the screen

    if (season == 's' || season == 'S')                                              // check the condition
    {
        sum=sum/6;                                                                   // divide by 6
    }else
    {
        sum=sum/1;                                                                   // divide by 1
    }

    cout << "========================================="<<endl;                       // display to the screen
    cout <<"No."<<setw(15)<<"Name"<<setw(20)<<"Watt/W"<<setw(20)<<"Hour of sunlight"<<endl;           // display to the screen

    for ( int i =0 ; i<numApp ; i++)                                                 // use for loop
    {
        cout<<i+1<<":"<<setw(15)<<newName[i]<<setw(20)<<newRate[i]<<setw(20)<<hourForApp[i]<<endl;    // display to the screen
    }

    cout <<"The total sum of power after divide by season is :"<< sum<< "W\n";      // display to the screen
    cout << "========================================="<<endl<<endl;               // display to the screen

//List of variables
float numSolar;
int sol;
int solar,solar1;
int firstRow[3];
int secondRow[3];
float thirdRow[3];
float area;

for (int i=0;i<3;i++)                                                                // use for loop
{
    cout<<"For Scenario "<<i+1<<endl;                                                // print to the screen
    solarTotal(numSolar,sum);                                                        // use pass by reference
    solar=panel[i].selectWatt(solarWatt);                                            // select watt and send it to another variable
    firstRow[i]=solar;                                                               // swap the solar into the array

    solar1=panel[i].calPanel(numSolar, solar,sol);                                    // calculate the number of panel and send it another variable

    secondRow[i]=solar1;                                                              // swap the solar1 to another varialble
    area=panel[i].calArea(solar1,solar);                                              // calculate the roof area

    thirdRow[i]=area;                                                                 // swap the area to another variable
    cout<<endl<<endl;                                                                 // create space
}

     cout << "========================================================================"<<endl;       // print to the screen
    for (int i=0;i<3;i++)                                                                            // use for loop
    {
        cout<<setw(50)<<"The size of the solar panel"<<setw(25)<<"no. of solar panels"<<setw(25)<<"The roof Area"<<endl;    // print to the screen
        cout<<fixed;                                                                                                         // fixed the input variable for setpercision
        cout<<"For the Scenario "<<i+1<<setw(25)<<firstRow[i]<<" W"<<setw(25)<<secondRow[i]<<setw(25)<<setprecision(4)<<thirdRow[i]<<" m^2"<<endl;         // print to the screen
    }
     cout << "========================================================================"<<endl;          // print to the screen
   return 0;     // return 0
}

// function use for pass by reference
void solarTotal(float &numSolar,float sum)
{
    // swap the variable
   numSolar=sum;
   cout<<"The total sum of power is"<<numSolar<<endl;    // print to the screen
   return;// return to the main function
}
