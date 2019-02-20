#include <iostream>
#include <iomanip>


//boo boo yaka yaka sha

using namespace std;

int main(){
    int input = 0;
    int inputCount = 0;
    int hi = 0;
    int lo = 999999999;

    int sum = 0;
    float avg = 0;
    char stop = 'g';
    
    while(stop != 's'){
        cout << "Enter an integer or '0' to quit. \n";
        cin >> ws;
        if(isdigit(cin.peek()) { 
            cin >> input;
            inputCount++;
            sum += input;
            avg = float(sum) / float(inputCount);

            if(input > hi){
                hi = input;
            }
            if(input < lo){
                lo = input;
            }

            cout << left << setw(5) << "Stats\n";
            cout << "Highest:" << setw(5) << hi << endl;
            cout << "Lowest:" << setw(5) << left << lo << endl; 
            cout << "Sum:" << setw(5) << left << sum << endl;
            cout << "Average:" << setw(5) << left << avg << endl; 

        } else {
            cin >> stop;
        }
    

    }
    cout << "thank you";

    return 0;
}
