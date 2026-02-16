//ECE 205, Homework2 Q2
//Elvis Chen
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

int main(){
    ifstream score_file; //this is the "cin"
    
    // this tries to open the file, and is similar to .open() in python
    // I've tried to use the name of the file becasue it is in the same folder, but it doesn't work
    // so this is the direct path
    score_file.open("C:\\Users\\elvch\\Desktop\\ECE205\\Homework\\scores.txt"); 

    if (score_file.is_open()){

        double a, b, c, d, e; // variables that we are going to read and store for the file 
        score_file >> a >> b >> c >> d >> e; // reads the files and store each value in the each one of the abcde

        // this outputs the values that we read from the file
        // https://www.youtube.com/watch?v=ASVgecY7ZbI used this link to teach me this method

        //this technique will fail if the file have like 100 numbers, this is only okay because this file only have 5 numbers
        cout << "\nThe file reads: " << a << " " << b << " " << c << " " << d << " " << e << endl; 
        double average = (a + b + c + d + e) / 5; // calculates the average of the 5 scores

        // outputs the average with 2 decimal place 
        cout << "The average of the scores is: " << fixed << setprecision(2) << average; 

        /* attempted to calculate the std, pow(x,y), where x is the base and y is the power, it can be divided by 5 or 4 
        depending on if we are calculating the population or the sample std */
        double standard_deviation_p = sqrt((pow(a - average, 2) + pow(b - average, 2) + pow(c - average, 2) + pow(d - average, 2) + pow(e - average, 2)) / 5);
        cout << "\nThe standard deviation of the scores is: " << fixed << setprecision(2) << standard_deviation_p        
        << " if we assume this is a population size which divides by n = 5"; // outputs the std with 2 decimal place

        //assume we are using a sample size which is divided by n-1, which is 4 in out case
        double standard_deviation_s = sqrt((pow(a - average, 2) + pow(b - average, 2) + pow(c - average, 2) + pow(d - average, 2) + pow(e - average, 2)) / 4);
        cout << "\nThe standard of deviation of the score is: " << fixed << setprecision(2) << standard_deviation_s
        << " if we assume this is a sample size which divides by n - 1 = 5 - 1 = 4" << endl; // outputs the std with 2 decimal place

        score_file.close(); // similar to file.close in python, 
    } else {
        cout << "ERROR: File cannot be founded/opened, please try again!"<<endl; 
    }
}

