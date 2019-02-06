/************************************************
** Program:     Weekly Pay
** Authors:     Adrik Gurganus and 
**              Peter Rockwood
** Date:        23 January 2019
** Decription:  Calculates weekly pay from info
**              in data.txt
************************************************/

#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main() {
    ifstream inFile; 

    double hours, rate;

    string firstName;   
    string lastName;    

    inFile.open("data.txt");

    cout << "Processing data" << endl;
    cout << "******Weekly Pay Calculator******" << endl;
    cout << "---------------------------------" << endl;

    while (!inFile.eof()) { 
        inFile >> firstName >> lastName;
        cout << left << setw(20) << "Employee name: " << firstName
             << " " << lastName << endl;

        inFile >> hours >> rate;
        cout << fixed;
        cout << showpoint;
        cout << setprecision(2);

        cout << left << setw(20) << "Hours: " << hours << endl;

        cout << left << setw(20) << "Hourly Pay: " << "$" << rate 
             << endl;

        cout << left << setw(20) << "Weekly pay: " << "$" 
             << hours * rate << endl << endl;
      
    
    }
    inFile.close();
    
    return 0;
}