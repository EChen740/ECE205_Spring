//ECE 205, Homework2 Q3
//Elvis Chen
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff




int main(){

    /*variables that we are going to use, set them to double becasue they have decimals */ 
    double height, weight, age, hat_size, jacket_size, waist_size; 
    cout << "---------------------------------------------------------" << endl;
    cout << "Dear reader, welcome to my program. Please enter some information" 
    << " and this program will calculate some sizes for you!"<< endl; // welcome message
    cout << "Please enter your height in [inches]: "; // asks reader 
    cin >> height; // gets the height from the reader
    cout << "Please enter your weight in [pounds]: "; // asks reader
    cin >> weight; // gets the weight from the reader
    cout << "Please enter your age in [years]: "; // asks reader
    cin >> age; // gets the age from the reader

    hat_size = 2.9 * weight / height; // calculate the hat size
    cout << "Dear reader thank you for your information" << endl; 
    cout << "Your hat size is: " << fixed << setprecision(2) << hat_size << endl; // outputs the hat size
    

    /*This if else loops essentially checks if the user is over 30 years old, if they are, 
    it will just calculate it without the additional 1/8 inch per decade*/
    if (age >= 30) {
        double years_over_30 = age - 30; // calculates how many years over 30, integer division so 21/10 = 2 etc
        jacket_size = (height * weight) / 288.0 + (1.0/8.0) * (years_over_30/10.0); // implements the age of 30 part integer division
        
    }
    else{
        jacket_size = (height * weight) / 288.0;  // calculate the jacket size if you are under 30 years old.
        
    }
    //basically the same concept as the jacket size, but with 1/10 incches for every two years instead of 10
    if (age >= 28){
        double years_over_28 = age - 28 ;
        waist_size = weight / 5.7 + (1.0/10.0) * (years_over_28/2.0); // gets the waist size 
         
    }else{
        waist_size = weight / 5.7; // if you are under 28 years old, no need to add 1/10 of an inch
        
    }

    //outputs the jacket size and the waist size for 2 decimals places
    cout << "Your jacket size is: " << fixed << setprecision(2) << jacket_size << endl;
    cout << "Your waist size is: " << fixed << setprecision(2) << waist_size << endl;
    return (0);

}