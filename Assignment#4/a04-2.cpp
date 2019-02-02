//************************************************************************
// Program Name: TV dimensions
// File Name:    a04.cpp
// Author:       Peter Rockwood
// Date:         02/03/2019
// Assignment:   4
// Description:  Prompts the user for the diagonal length and aspect ratio 
//               of a tv screen and prints the width, height and area of the
//               screen.
// Sources:      None.
//************************************************************************


#include <iostream>
#include <iomanip> 

using namespace std;

//************************************************************************
// Function Name: findDimensions(int tvType, float diag)
// Arguments:     int tvType(1: Traditional 4:3 aspect, 2: LCD 16:9 aspect)
//                float diag (The diagonal length of the tv screen in inches)
// Returns:       Dummy zero.
// Side effects:  Prints to console the width and height of the tv screen.
//************************************************************************
int findDimensions (int tvType, float diag) {
    // 4:3 ratios
    const float STND_WIDTH_RATIO = 4.0;
    const float STND_HEIGHT_RATIO = 3.0;
    const float STND_DIAG_RATIO = 5.0;
    // 16:9 ratios
    const float LCD_WIDTH_RATIO = 16.0;
    const float LCD_HEIGHT_RATIO = 9.0;
    const float LCD_DIAG_RATIO = 18.35756;
    // values to be determined
    float scalar = 0.0;
    float width = 0.0;
    float height = 0.0;
    float area = 0.0;

    if (tvType == 1){ //3:4 calculations
        scalar = diag / STND_DIAG_RATIO;
        width = STND_WIDTH_RATIO * scalar;
        height = STND_HEIGHT_RATIO * scalar;
        area = height * width;
    } else { //16:9 calculations
        scalar = diag / LCD_DIAG_RATIO;
        width = LCD_WIDTH_RATIO * scalar;
        height = LCD_HEIGHT_RATIO * scalar;
        area = height * width;
    }

    cout << fixed << setprecision(2); // formating number printing

    if (tvType == 1){ //one line of printing dependent on tv type
        cout << "\nTV type: Traditional\n";
    } else {
        cout << "\nTV type: LCD\n";
    }

    cout << "TV size: " << diag << " inches\n";
    cout << "Screen width: " << width << " inches\n";
    cout << "Screen height: " << height << " inches\n";
    cout << "Screen area: " << area << " sq. inches\n\n";

    return 0;
}



int main() {
    //input variables
    float diag = 0.0; 
    int tvType = 0;
    //ask for tv screen diagonal in inches
    cout << "Enter the screen size (the diagonal length) in inches of the TV:\n" ;
    //assign input to 'diag'
    cin >> diag;
    //ask for ratio
    cout << "\nSelect the type of TV you'd like to view dimensions for:\n"
         << "    1. Traditional TV Area\n"
         << "    2. LCD TV Area\n"
         << "    3. Both types of TVs' Area\n"
         << "Enter the number that corresponds to the type of TV you wish to view:\n";
    //assign input to 'tvType'     
    cin >> tvType;
    //call findDimensions with input variables as arguments, or call twice for each aspect
    if (tvType < 3){
        findDimensions(tvType, diag);
    } else {
        findDimensions(1, diag);
        findDimensions(2, diag);
    }

    return 0;
}
