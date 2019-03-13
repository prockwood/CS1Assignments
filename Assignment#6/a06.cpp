////////////////////////////////////////////////////////////////////////////////
// Program Name: Gym Dues Calculator
// File Name:    a06.cpp
// Author:       Peter Rockwood
// Date:         02/20/2019
// Assignment:   6
// Description:  Prints gym pricing structure. Prompts the user for
//               their senior status(>60yo), the number of membership months
//               they want to prepay, and the number of personal training
//               sessions they want to prepay. Then, calculates and prints
//               the total dues based on the gym pricing structure.
//
// Sources:      https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
//               http://www.cplusplus.com/forum/beginner/2957/
////////////////////////////////////////////////////////////////////////////////

#include <iostream> //cin, cin.fail(), cout
#include <iomanip> //fixed, showpoint, setprecision()
using namespace std;

//declare functions
void information();
void getInfo(bool &senior, int &months, int &personal);
double calcCost(bool senior, int months, int personal);

int main() {
    cout << "\nHello, this program will calculate the cost of gym membership.\n\n";
    while (true) { //loop the whole program until user quits
        bool senior = 0; //declare variables.(senior, month and personal get reassigned from within getInfo())
        int months = 0;
        int personal = -1;
        char menu = ' ';
        double price = 0.0;

        cout << "Please enter 'a' to calculate the cost of membership,\n"
             << "or enter 'b' to quit the program: ";

        cin >> menu; //a:run or b:quit
        cout << endl;

        if (menu == 'a') { //run
            information(); //print price structure
            getInfo(senior, months, personal); //get inputs from user
            price = calcCost(senior, months, personal); //calculations
            cout << fixed << showpoint << setprecision(2); //formating for $
            cout << "Your total membership fee is $" << price << endl; //program output
            cout << "-----------------------------------------------------------------\n\n";
        } else if (menu == 'b') { //quit
            cout << "Thank you for using my gym calculation program. Goodbye.\n\n";//quit message
            return 0; //the only way out of the program
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//Function Name: information
//Arguments:     None
//Description:   Prints the gym pricing structure. No return value.
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
//Description:   Prompts the user for senior status (over 60 years of age),
//               number of membership months prepay and number of personal
//               training sessions prepay. Assigns values to variables declared
//               outside the function via reference. No return value.
////////////////////////////////////////////////////////////////////////////////

void getInfo(bool &senior, int &months, int &personal) { //referential arguments, match variables in main()
    char sbool = ' ';//variable to capture senior status as 'y' or 'n'

    while (sbool != 'y' && sbool != 'n') { //loop until senior is 'y' or 'n'
        cout << "Are you over the age of 60? (y or n): ";
        cin >> sbool;
        cout << endl;

        if (sbool == 'y') { //map: (char sbool) to (bool senior)
            senior = true;
        } else if (sbool == 'n') {
            senior = false;
        }
    }

    while (months < 1) { //loop until months > 0
        cout << "Please enter the number of months you would like\n"
             << "to prepay for the membership: ";
        cin >> months;
        cout << endl;
        // validate input is of type int.
        // if there's a type mismatch between cin and months, cin.fail()
        // evaluates to 1 and assigns months=0.
        if (cin.fail()) {
            cin.clear(); //clear error flag
            cin.ignore(1000,'\n'); // clear input stream
        }
    }

    while (personal < 0) { //loop until personal > -1. (0 is valid input)
        cout << "Please enter the number of personal training sessions\n"
             << "you would like to purchase: ";
        cin >> personal;
        cout << endl;
        // validate input is of type int. (see comment for above while loop)
        if(cin.fail()){
            cin.clear(); //clear error flag
            cin.ignore(1000,'\n'); //clear input stream
            personal = -1; // cin.fail(), when true, assigns personal=0
                           // but 0 is a valid value for persornal var.
        }
    }
    return; //no return value
}

////////////////////////////////////////////////////////////////////////////////
//Function Name: calcCost
//Arguments:     bool senior, int months, int personal
//Description:   Given senior status (>60yo), membership months prepaid, and
//               personal training sessions prepaid, calculates and returns
//               the hypothetical gym dues as a double.
////////////////////////////////////////////////////////////////////////////////

double calcCost(bool senior, int months, int personal) {
    double  price = 0.0; // membership price
    double  sessPrice = 0.0; // session price

    price = months * 50.0; // # months * $50
    sessPrice = personal * 30.0;// # sessions * $30

    if (senior == true) { //senior discount(price * (100%-30%))
        price *= 0.7;
    }
    if (months >= 12) { //membership bulk discount(price* (100%-15%))
        price *= 0.85;
    }
    if (personal >= 5) { //personal training bulk discount(sessPrice*(100%-20%))
        sessPrice *= 0.8;
    }

    price += sessPrice; //total membership and personal training prices

    return price; //return total price of type double
}
