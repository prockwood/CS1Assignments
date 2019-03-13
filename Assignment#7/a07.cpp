///////////////////////////////////////////////////////////////////////////////////////////
// Program Name: High and Low Temps
// File Name:    a07.cpp
// Author:       Peter Rockwood
// Date:         03/08/2019
// Assignment:   7
// Description:  Reads high and low temperatures for each of 12 months from input
//               text file. Finds and prints the highest/lowest temp and month of
//               hight/lowest temp.
// Sources:      None
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//declare functions
void printStrArr(string months[]); //print array utility functions
void print2dArr(int hilo[][2]); //print array utility functions

void loadData(ifstream &infile, string months[], int temp[][2], int &rows);
void tempHigh(string months[], int temp[][2], int rows, string &month, int &hightemp);
void tempLow(string months[], int temp[][2], int rows, string &month, int &lowtemp);


int main() {
    //declare, initialize variables
    ifstream inFile; //file input object
    string months [12]; //month names array
    int temps[12][2]; //2d array
    int rows = 0; //lines of data in input file
    int hightemp = 0;
    int lowtemp = 0;
    string month = "";//to hold month of high/low in tempHigh()/tempLow()

    loadData(inFile, months, temps, rows); //text file data to the arrays
    // printStrArr(months);
    // print2dArr(temps);
    tempHigh(months, temps, rows, month, hightemp); //find max temp
    cout << "Maximum temp was " << hightemp << " degrees in " << month << ".\n";
    tempLow(months, temps, rows, month, lowtemp); //find min temp
    cout << "Minimum temp was " << lowtemp << " degrees in " << month << ".\n";
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: loadData
//Arguments:     ifstream &infile, string months[], int temp[][2], int &rows
//Description:   Opens text file containing 'month hightemp lowtemp' per row,
//               copies month names into months array, copies high and low temps
//               into temps 2d array. Updates rows variable with the number of
//               data rows in the file.
///////////////////////////////////////////////////////////////////////////////////////////
void loadData(ifstream &infile, string months[], int temp[][2], int &rows){
    infile.open("temps.txt"); //open temps.txt
    int mCount = 0; // row count var

    while (!infile.eof()) { //read till out of data
        // 'temp' array: 1 months (hightemp, lowtemp) per row. Parralel month str array.
        infile >> months[mCount] >> temp[mCount][0] >> temp[mCount][1];
        mCount++; // increment row count
    }
    rows = mCount; //save row count
    infile.close(); // close temps.txt
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: tempHigh
//Arguments:     string months[], int temp[][2], int rows, string &month, int &hightemp
//Description:   Finds the highest high temperature, assigns to 'hightemp' variable,
//               and the month it occured in is assigned to 'month' variable
///////////////////////////////////////////////////////////////////////////////////////////
void tempHigh(string months[], int temp[][2], int rows, string &month, int &hightemp){
    hightemp = temp[0][0]; // ** set hightemp to first high value in temp array
    for (int i = 0; i < rows; i++){ // iterate through 'temps' array high column
        if (temp[i][0] > hightemp){ // if entry [i][0] is highest yet
            hightemp = temp[i][0]; // assign entry to 'hightemp' variable
            month = months[i]; // assign month of highest to 'month' variable
        }
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////
//Function Name: lowtemp
//Arguments:     string months[], int temp[][2], int rows, string &month, int &lowtemp
//Description:   Finds the lowest low temperature, assigns to 'lowtemp' variable,
//               and the month it occured in is assigned to the 'month' variable.
///////////////////////////////////////////////////////////////////////////////////////////
void tempLow(string months[], int temp[][2], int rows, string &month, int &lowtemp){
    lowtemp = temp[0][1]; // ** set lowtemp to first low value in temp array
    for (int i = 0; i < rows; i++){ // iterate through 'temps' array low column
        if (temp[i][1] < lowtemp){ // if entry i is lowest yet
            lowtemp = temp[i][1]; // assign entry to 'lowtemp' variable
            month = months[i]; // assign month of lowest to 'month' variable
        }
    }
    return;
}

//functions to print month and temp arrays
void printStrArr(string months[]){
    for(int i = 0; i < 12; i++){
        cout << months[i] << endl;
    }
}
void print2dArr(int hilo[][2]){
    for(int i = 0; i < 12; i++){
        cout << hilo[i][0] << " " << hilo[i][1] << endl;
    }
}
