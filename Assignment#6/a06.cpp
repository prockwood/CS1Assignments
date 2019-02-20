//************************************************************************
// Program Name:
// File Name:    a06.cpp
// Author:       Peter Rockwood
// Date:         02/xx/2019
// Assignment:   5
// Description:
//
//
//
//
// Sources:
//
//************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//declare functions
void information();
void getInfo(bool &senior, int &months, int &personal);
double calcCost(bool senior, int months, int personal);

int main() {
    cout << "\nHello, this program will calculate the cost of gym membership.\n\n";
    while (true) { //loop the whole program.
        bool senior = 0; //declare variables.(senior, month and personal get reassigned from within getInfo())
        int months = 0;
        int personal = -1;
        char menu = ' ';
        double price = 0.0;


        cout << "Please enter 'a' to calculate the cost of membership,\n"
             << "or enter 'b' to quit the program: ";

        cin >> menu; //run or quit
        cout << endl;

        if (menu == 'a') { //run
            information(); //print cost breakdown
            getInfo(senior, months, personal); //input
            price = calcCost(senior, months, personal); //calculations
            cout << fixed << showpoint << setprecision(2); //formating for $
            cout << "Your total membership fee is $" << price << endl; //program output
            cout << "-----------------------------------------------------------------\n\n";
        } else if (menu == 'b') { //quit
            cout << "Thank you for using my gym calculation program. Goodbye.\n\n";//quit message
            return 0;
        }
    }
    return 0; //this will never get executed but i'm scared to delete it.
}

////////////////////////////////////////////////////////////////////////////////
//Function Name: information
//Arguments:     None
//Description:   Prints the gym pricing structure.
////////////////////////////////////////////////////////////////////////////////


void information() {
    cout << "-----------------------------------------------------------------"
         << "\nThank you for your interest in ABC's fitness center.\n"
         << "Below is some information about our fitness center \n"
         << "and the costs of membership:\n\n"
         << "   -General Membership Fee: $50.00 per month.\n\n"
         << "   -Senior Citizen Discount: 30\% for any member over the age of 60.\n\n"
         << "   -(If membership is bought and paid for 12 or more months,\n"
         << "    the discount is 15\% each month.)\n\n"
         << "   -Personal Training Session: $30.00 per session.\n\n"
         << "   -(If 5 or more sessions are bought and paid-for there will\n"
         << "    be a 20\% discount on each session).\n\n";

}

////////////////////////////////////////////////////////////////////////////////
//Function Name: getInfo
//Arguments:     bool &senior, int &months, int &personal.
//Description:   Prompts the user for over 60 years of age, number of
//               membership months prepay and number of personal training
//               sessions prepay. assigns values to variables declared
//               outside the function via reference.
////////////////////////////////////////////////////////////////////////////////

void getInfo(bool &senior, int &months, int &personal) { //referential arguments
    char sbool = ' ';//variable to capture senior status

    while (sbool != 'y' && sbool != 'n') { //only proceed once 'y' or 'n'  input
        cout << "Are you over the age of 60? (y or n): ";
        cin >> sbool;
        cout << endl;

        if (sbool == 'y') { //map sbool to senior
            senior = true;
        } else if (sbool == 'n') {
            senior = false;
        }
    }

    while (months < 1) { //only proceed if input > 0
        cout << "Please enter the number of months you would like\n"
             << "to prepay for the membership: ";
        cin >> months;
        cout << endl;
        // validate input is of type int.
        // if there's a type mismatch between cin and months, cin.fail()
        // evaluates to 1 and assigns months=0.
        if (cin.fail()) {
            cin.clear(); //refresh the input stream
            cin.ignore(1000,'\n');
        }

    }

    while (personal < 0) { //only proceed if input > -1. 0 is valid
        cout << "Please enter the number of personal training sessions\n"
             << "you would like to purchase: ";
        cin >> personal;
        cout << endl;
        // validate input is of type int. (see comment for above while loop)
        if(cin.fail()){
            cin.clear(); //refresh input stream
            cin.ignore(1000,'\n');
            personal = -1; // since cin.fail(), when true, assigns personal=0
                           // but 0 is a valid input for the program.
        }
    }
    return; //no return value
}

////////////////////////////////////////////////////////////////////////////////
//Function Name: calcCost
//Arguments: bool senior, int months, int personal
//Description: Given senior status (>60yo), membership months prepaid, and
//             personal training sessions prepaid, calculates and returns
//             the hypothetical gym dues as a double.
////////////////////////////////////////////////////////////////////////////////

double calcCost(bool senior, int months, int personal) {
    double  price = 0.0; // membership price
    double  sessPrice = 0.0; // session price

    price = months * double(50); // # months * $50
    sessPrice = personal * double(30);// # sessions * $30

    if (senior == true) { //senior discount(price * (%100-%30))
        price *= double(0.7);
    }
    if (months >= 12) { //membership bulk discount(price* (%100-%15))
        price *= double(0.85);
    }
    if (personal >= 5) { //personal training bulk discount(sessPrice*(%100-%20))
        sessPrice *= double(0.8);
    }

    price += sessPrice; //combine membership and personal training prices

    return price; //return price of type double
}
