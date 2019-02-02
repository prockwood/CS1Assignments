//*********************************************************************
// Program Name: Two Car's Distance
// File Name:    a03.cpp
// Author:       Peter Rockwood
// Date:         01/27/2019
// Assignment:   3
// Description:  Prompts the user for the velocity of two cars traveling
//               perpindicular to one another, and the time elapsed since
//               they began traveling from the same point. Calculates and
//               prints to the console the normal distance between the
//               cars at the elapsed time.
// Sources:      None.
//*********************************************************************

#include <iostream>  //Use input-output library.
#include <math.h>    //sqrt, pow functions.
#include <iomanip>   //fixed, setprecision function.
using namespace std; //To shorten 'cout' and 'cin' calls.

int main() {
    //initialize the variables we're going to use.
    float speedA = 0.0; // miles per hr
    float speedB = 0.0; // miles per hr
    float elapsedHours = 0.0;
    float elapsedMinutes = 0.0;
    float distanceA = 0.0;
    float distanceB = 0.0;
    float hypotenous = 0.0;

    //gather data
    cout << "Enter the speed for Car A: "; //Ask for speedA
    cin >> speedA; // Assign the input to 'speedA' var.

    cout << "Enter the speed for Car B: "; //Ask for speedB
    cin >> speedB; // Assign the input to 'speedB' var.

    cout << "Enter elapsed time as hours and minutes: "; // Ask for elapsed time.
    cin >> elapsedHours >> elapsedMinutes; // Assign inputs to variables.
    cout << endl;

    //calculations
    elapsedHours = elapsedHours + (elapsedMinutes/60.0); //convert minutes to hours and add.
    distanceA = speedA * elapsedHours; //Multiply out distance from speed and hours.
    distanceB = speedB * elapsedHours;
    hypotenous = sqrt((pow(distanceA,2)) + (pow(distanceB,2))); //Calculate Norm via Pythagorean Thm.

    //Print norm.
    cout << fixed; //Confine decimal to hundereds place.
    cout << setprecision(2); //Confine decimal to hundereds place.
    cout << "The shortest distance between the cars is: " << hypotenous
	 << " miles." << endl;
    return 0; //Function requires a return value.
}
