///////////////////////////////////////////////////////////////////////////////////////////
// Program Name: High and Low Temps
// File Name:    a08.cpp
// Author:       Peter Rockwood
// Date:         03/08/2019
// Assignment:   8
// Description:  Reads high and low temperatures for each of 12 months from input
//               text file. Finds and prints the highest/lowest temp and month of
//               hight/lowest temp.
// Sources:      http://www.cplusplus.com/doc/tutorial/structures/
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> //cin, cout
#include <fstream> //input file stream
#include <string>
#include <iomanip> // setw()
using namespace std;

struct Temperature { //struct template
    int hightemp;
    int lowtemp;
    string month;
}   tempList [12]; //put 12 of them in an array

//declare functions
void printStructArr(Temperature temp[], int size = 12); //print array utility function

void loadData(ifstream &infile, Temperature [], int &size); //from file to struct array
Temperature averageHigh(Temperature [], int &size); //returns highest month's struct
Temperature averageLow(Temperature [], int &size); //returns lowest month's struct

int main() {
    //declare, initialize variables
    ifstream inFile; //file input object
    int size = 0; //lines of data in input file
    Temperature highest; //to be determined via averageHigh()
    Temperature lowest; //to be determined via averageLow()

    loadData(inFile, tempList, size); //text file data to the Temperature struct array
    printStructArr(tempList);
    highest = averageHigh(tempList, size); //find high and low and print them out.
    lowest = averageLow(tempList, size);
    cout << "Maximum temp was " << highest.hightemp << " degrees in " << highest.month << ".\n";
    cout << "Minimum temp was " << lowest.lowtemp << " degrees in " << lowest.month << ".\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: loadData
//Arguments:     ifstream &infile, Temperature temp[], int &rows
//Description:   Opens text file containing '<month> <hightemp> <lowtemp>' per row,
//               copies each value into the corresponding values of a Temperature
//               struct instance of the passed-in Temperature struct array. Also counts
//               the number of data rows from the input file and assigns to the size
//               variable by reference.
///////////////////////////////////////////////////////////////////////////////////////////
void loadData(ifstream &infile, Temperature temp[] , int &size){
    infile.open("temps.txt"); //open temps.txt
    while (!infile.eof()) { //read till out of data
        // txt data to corresponding fields in Temperature struct
        infile >> temp[size].month >> temp[size].hightemp >> temp[size].lowtemp;
        size++; // increment row count, this sets the size var in main() via reference
    }
    infile.close(); // close temps.txt
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: averageHigh
//Arguments:     Temperature temp[], int &size
//Description:   From the Temperature array, finds and returns the Temperature instance
//               containing the highest hightemp value in the array.
///////////////////////////////////////////////////////////////////////////////////////////
Temperature averageHigh(Temperature temp[], int &size){
    int highestTemp = temp[0].hightemp;
    int highIndex = 0;
    for (int i = 0; i < size; i++){ // iterate through 'temp'
        if (temp[i].hightemp > highestTemp){ // if hightemp is highest yet
            highestTemp = temp[i].hightemp; // save the value and the array index
            highIndex = i;
        }
    }
    return temp[highIndex];
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: averagelow
//Arguments:     Temperature temp[], int &size
//Description:   From the Temperature array, finds and returns the Temperature instance
//               containing the lowest lowtemp value in the array.
///////////////////////////////////////////////////////////////////////////////////////////
Temperature averageLow(Temperature temp[], int &size){
    int lowestTemp = temp[0].lowtemp;
    int lowIndex = 0;
    for (int i = 0; i < size; i++){ // iterate through 'temp'
        if (temp[i].lowtemp < lowestTemp){ // if lowtemp is lowest yet
            lowestTemp = temp[i].lowtemp; // save the value and the array index
            lowIndex = i;
        }
    }
    return temp[lowIndex];
}



//functions to print Temperature array
void printStructArr(Temperature temp[], int size){
    for(int i = 0; i < size; i++){
        cout << left
             << setw(10) << temp[i].month
             << setw(4) << temp[i].hightemp
             << setw(4) << temp[i].lowtemp
             << endl;
    }
}
