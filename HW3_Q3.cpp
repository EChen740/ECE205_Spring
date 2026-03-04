#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

int function(int a, int b){

    /*Lets say for a time we have 0356 we %100 by 100 to get the remainder of minutes*/
    int a_current_minutes = a % 100;
    int a_hour_minutes = (a - a_current_minutes)* 60 / 100; // ended up needing to divide by 100, otherwise we will be 100x too much. (initially did not divide by 100)
    int a_total_min = a_current_minutes + a_hour_minutes; 

    int b_current_minutes = b % 100;
    int b_hour_minutes = (b - b_current_minutes)* 60 / 100;
    int b_total_min = b_current_minutes + b_hour_minutes;
    int difference = abs(a_total_min - b_total_min);
    /*this line makes sure that we are getting the minimum value, for instance 2300 and 0100, should be 120, but we get 1380 - 60 = 1320
    so our program will take the minimum value of difference and 1400 - difference. it will also work if  */
    difference = min(difference, abs(1440 - difference)); 
    return difference;
}

int main(){
    int a, b; // set up integers
    char choice; //set choice as string
    do {

        /*Making a do while function. Meaning that is the user inputs a non valid time, the program will 
        tell them enter another time that is valid and will also tell them what is the valid range*/
        do{
        cout <<"Enter first time in military time: "; 
        cin >> a;
        cout <<"Enter second time in millitary time: "; 
        cin >> b;

        /*If a or b that was enter was over 2359, the function will output an invalid value. 
        Note that values may only be between 0000 and 2359*/
        if((a >2359)||(b > 2359)){
        cout << "Try again, Please enter a valid time between 0000 and 2359." << endl;
        }
        }while((a >2359)||(b > 2359));

        // we are setting "answer" to  function that takes the int parameter of a and b
        int answer = function(a, b);
        cout <<"Your times are " <<answer << " minutes apart." ;

        //here we allow the reader to make their choice of continuing the program or not
        cout << "\nDear reader, would you like to do this again [Y/N]: ";
        cin >> choice;
    } while((choice == 'y') ||(choice == 'Y')); 

    cout << "Goodbye Reader, see you around!";
 
}