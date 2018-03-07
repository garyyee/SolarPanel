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
 // list of libraries
#include <string>
#include <iostream>
using namespace std;

class appliance
{
private:
    // list of variables
	int snumApp;
	char season;

public:
    // constructors
	appliance();
	appliance(  char   );

	// Public functions
     int findSeason( char);
     int select();
};
