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
 //list of libraries
#include <string>
#include <iostream>
using namespace std;

class solarPanel
{
private:
    // list of variables
	int solarWatt;
	int areaSolar;
    float numSolar;
    int sol;

public:
    // contructors
	solarPanel();
	solarPanel(float,int,int);

	// public function
    int selectWatt (int);
    int calPanel (float,int,int);
    float calArea (int,int);
};
