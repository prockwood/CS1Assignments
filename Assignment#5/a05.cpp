//************************************************************************
// Program Name: Total Cost Calculator
// File Name:    a05.cpp
// Author:       Peter Rockwood
// Date:         02/10/2019
// Assignment:   5
// Description:  For a recursive process with an initial cost 'a' and
//               marginal cost 'a+b': calculates the number of product cycles
//               possible before exceeding a predifined maximum cost.
//               Input via 'times.txt' containing one or more rows with
//               initial-cost, marginal-cost, and max-cost integer values
//               per row. Output via 'output.txt' containing input data plus
//               the calculated number of possible product cycles per row.
//
// Sources:      Stephanie Allen's file-input/output example program:
//                   - "https://repl.it/@sallenpcc/03FileInputTestScores"
//************************************************************************


#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile; //input file stream variable
    ofstream outFile; //output file stream variable

    inFile.open("times.txt"); //open an existing file in the local directory
                              //to read from
    outFile.open("output.txt"); //create a new output file

    //input variables
    int start_dish = 0;
    int current_dish = 0;
    int marginal_dish = 0;
    int max_time = 0;
    int time = 0;
    int dishes_count = 0;

    while(!inFile.eof()) { //outer-loop until run out of input lines
        inFile >> start_dish // load variables with new line's data
               >> marginal_dish
               >> max_time;
        time = 0; //reset internal variables
        dishes_count = 0;
        current_dish = start_dish;

        while(time+current_dish <= max_time){ //inner-loop until time + next_dish > max_time
            time = time + current_dish; //update cooking time
            current_dish = current_dish + marginal_dish; //update time to cook next_dish
            dishes_count++; // increment # of dishes cooked
            }
        // output a row of the input data plus dishes_count
        outFile << setw(6) << left << start_dish
                << setw(6) << left << marginal_dish
                << setw(6) << left << max_time
                << setw(6) << left << dishes_count
                << endl;
    }
    //close the stream files
    inFile.close();
    outFile.close();
    return 0;
}
