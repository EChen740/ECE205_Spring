//ECE 205, Homework2 Q1
//Elvis Chen
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <math.h> // access to math functions, we use pow() for exponents

using namespace std; // don't need to write std for cout, cin and exponents

double force_equation(double m1, double m2, double d){//creates a function that can be used in the int main
    double G = 6.673e-11; //gravitational constant of gravity m^3/kg/s^2
    double F = G * m1 * m2 / pow(d, 2); //calculates the gravitational force using formula F = G*m1*m2/d^2
    double dyne = F * 1e5; //newtwon to dyne, bc questions wants us to calcualte this in dyne
    return dyne; //returns the value of dyne to be used in the main function
}

int main(){
    double m1, m2, d, dyne; // sets up variable for mass1, mass2, G-constant, distance, and force in dyne
    char c; //creates a character variable to ask the user if they want to repeat the program
    
    /*The do{}, while{} while funciton is basically a loop, it tells the program to do this, while a statement is true
    for out case the programs will do the program while the user indicates y or Y after the first run*/
    do{ 
    cout << "\n\n-----------------------------------------------------------------------";
    cout << "\nHello reader, welcome to my program!\n"
    << "This program will calculate the gravitation force between two objects.\n"
    << "\nTo start please enter the mass[kg] of the first object, this will be m1: ";
    cin >> m1; //this lets the reader enter the numerical value for m1
    cout << "Please enter the mass[kg] of the second object, m2: ";
    cin >> m2; //this allws the reader to enter the mass for m2
    cout << "Now, please enter the distance[m] between the two objects, d: ";
    cin >> d; //this allows the reader to enter the distance between the two objects

    dyne = force_equation(m1,m2,d); //calls the function we made earlier to calculate the force in dyne
    // m1,m2,m3 are parameters that the user enter and we substitute it into the function, and the functions calculates this. 
    
    cout << "\nThe gravitational force [dyne] between the two objects is: " << fixed << setprecision(4) 
    << dyne << " dyne(s)" << endl; //outputs the force, with two decimal places and units of Newtons        
    
    cout << "\nDear reader would you like to calculate again? Please press [Y/N}]: ";
    cin >> c;
    }
    while (c == 'y' || c == 'Y'); //this allows the user to repeat the program if they want to, by entering y or Y,

    cout << "\nGoodbye reader, have a nice day!:)" << endl; //goodbye message
return (0);
}

