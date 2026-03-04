#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

int hours, minutes;
char choice;
void input(){
    
    /*We are making the program with a do while if the reader chooses to do the program again. */
    do{
        cout << "Enter the number of hours: ";
        cin >> hours;
        //this line checks if the numbers of huors i valid, if it is less than 0 or greater than 23
        if (hours < 0 || hours > 23){
            cout << "Please enter a valid hour (0 to 23) and try again." << endl;
        }
    }while (hours < 0 || hours > 23);

    do{// this do while loop was included in case the reader includes a invalid time. 
        cout << "Enter the number of minutes: ";
        cin >> minutes;
        if (minutes < 0 || minutes > 59){
            //this outputs a error message and tells the reader to try again. 
            cout << "Please enter a valid minmute (0 to 59 ) and try again." << endl;
        }
    }while(minutes < 0 || minutes > 59); // repeats the loop if the reader inputs minutes under 0 and over 59, bc these are not valid. 
}

// function to start the conversation. 
void conversation(){
    cout << "\n\nDHello reader welcome to my program." << endl;
    cout << "This program will convert 24 hour time to 12 hour time" << endl;
    cout << "You will be prompted to enter a number for hours and minutes." << endl;
}
void output(){

    // if it is over 12pm
    if ((hours > 12) & (hours != 24)){
        hours = hours - 12;
        cout << "Your time is "  << hours << ":" << minutes << " P";
    }/*if (hours == 24){
        cout << "Your time is 12: " << minutes << "A";
    }*/
    else{
        cout << "Your time is " << hours << ":" << minutes << " A";
    }

}
int main(){ 
    /*I like to do a do while loop to repeat things based on an input from the reader*/
    do{

    //we can utilize our previous functions, and this makes the intmain cleaner.
    conversation();
    input();
    output();

    cout << "\nDear reader, woudld you like to continue? Please press [Y/N]" << endl;
    cin >> choice;
    }while(choice == 'Y' || choice == 'y'); //saying go back to do statement if reader inputs y or Y.

    cout << "Dear reader, have a nice day. Good Bye:)!" << endl; //end statement if the reader does not press y.
}
