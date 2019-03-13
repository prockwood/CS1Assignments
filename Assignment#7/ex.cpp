
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;

int main()
{
        //Declare variables;                          Step 1
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    double test1, test2, test3, test4, test5;
    double average;

    string firstName;   
    string lastName;    

    inFile.open("test.txt");                         //Step 2
    outFile.open("testavg.out");                     //Step 3

    outFile << fixed << showpoint;                  //Step 4
    outFile << setprecision(2);                     //Step 4

    cout << "Processing data" << endl;
    outFile << "Student Averaging Program" << endl;
    outFile << "-------------------------\n" << endl;

    while (!inFile.eof()) { 
        inFile >> firstName >> lastName;                //Step 5
        outFile << left << setw(20) << "Student name: " << firstName
                << " " << lastName << endl;             //Step 6
        cout << "Student name: " << firstName
                << " " << lastName << endl;             //Step 6

        inFile >> test1 >> test2 >> test3 
              >> test4 >> test5;                       //Step 7
        outFile << left << setw(20) << "Test scores: " << setw(6) << test1
                << setw(6) << test2 << setw(6) << test3
                << setw(6) << test4 << setw(6) << test5 
                << endl;                                //Step 8

        average = (test1 + test2 + test3 + test4 
                  + test5) / 5.0;                       //Step 9

        outFile << left << setw(20) << "Average test score: " << setw(6) 
                << average << endl;                     //Step 10
    }
    inFile.close();                                 //Step 11
    outFile.close();                                //Step 11

    return 0;
}
