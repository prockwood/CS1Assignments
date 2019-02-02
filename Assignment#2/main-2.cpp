//*********************************************************************
// Program Name: Voltage Calculator
// File Name:    a02.cpp
// Author:       Peter Rockwood
// Date:         01/20/2019
// Assignment:   2
// Description:  Prompts the user for the resistance and current
//               values of their circuit. Given the input the program 
//               calculates and outputs the voltage of the circuit.
// Sources:      None.
//*********************************************************************

#include <iostream>  //Use input-output library.

using namespace std; //To shorten 'cout' and 'cin' calls.

void main() {
    float resistance = 0; //Initialize the variables we're going to use.
    float current = 0;
    float voltage = 0;

    cout << "Please input the resistance: "; //Ask for Ohms.
    cin >> resistance; // Assign the input to 'resistance' var.

    cout << "Please input the current: "; //Ask for Amps.
    cin >> current; // Assign the input to 'current' var.

    voltage = resistance * current; //Calculate voltage, assign it to 'voltage' var.

    cout << "Your voltage is: " << voltage << endl; //Print voltage.

    //return 0; //Function requires a return value.
}
