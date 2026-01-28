//HW1_Q1_Elvis_Chen
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision


using namespace std; // standard namespace, eliminates the need to write std::cout <<""; everytime

//main code
int main(){ //program starts
    int num_of_seconds; //sets integer variable take in the number of seconds the user inputed
    cout << "\nHello readers. " //welcomes the reader to the program
        << "Welcome to my program!!\n"
        << "This program will convert seconds to <Hours><Minute><Seconds>.\n"
        << "Please enter the number of seconds: ";
        cin >> num_of_seconds; //takes in the input as the previous set integer variable

        //creates new integer variables, and for certain variables.
    int sec_in_min = 60;
    int min_in_hour = 60; 
    int sec_in_hour = sec_in_min * min_in_hour; //60*60 = 3600
    int hours = num_of_seconds / sec_in_hour; //hours and round it to the nearest whole integer w/out remainder
    int minutes = (num_of_seconds % sec_in_hour) / 60; //takes the remainder of the inputed seconds divided by 3600
                                                       // then divde the remainder by 60 and get the greatest integer value before remainder
    int remaining_seconds = num_of_seconds % 60;// divides input seconds by 60, and takes the remainder, that is the "leftover" seconds

    //program output
    cout << "The time in hours minutes seconds is: " 
        <<hours<<"hr "
        <<minutes<<"min "
        <<remaining_seconds<<"sec."<<endl;
    //decimal so settting double variables
    double num_of_second = static_cast<double>(num_of_seconds); // using online coding forums, this allows num_of_seconds (integer) to be converted to a double without the need of creating another variable.
    double num_of_hours = num_of_second / 3600.0;
    double num_of_mins = num_of_second / 60.0;
    
    // using online tutorial, "<<fixed<< setprecision(4)"  output variables to 4 decimal places.
    cout << "The number of hours is: " <<fixed<< setprecision(4)<< num_of_hours << endl; 
    cout << "The number of minutes is: " <<fixed << setprecision(4) << num_of_mins <<endl;

    return(0);   
}

