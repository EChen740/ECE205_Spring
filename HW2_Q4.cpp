//ECE 205, Homework2 Q4
//Elvis Chen
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

int main(){
    
    //setting up initial integer variables, winner[4] creates a 1x4 array similar in matlab
    int x, i, duplicate, winner[4]; 

    // outputs an initial message
    cout << "The winners are: ";
    
    // https://www.youtube.com/shorts/T1EeAX5SAfY, video was helpful to do randomly gen. numbers that are not the same . 
    srand(time(0));

    /*sets up for loop with conditions as such x starts at zero, and stops at 3, increases 1 increments every loop*/
    for (x = 0; x < 4; x++){ 
    
        /*This is a do{} while() condition. Essentially tells program to repeat the process again if duplicate is found
        which prevents the 1x4 "winner" array from storing that number in the column.*/
        do{

            duplicate = 0; //initially sets duplicate to zero, bc we assume initially there is no duplicates. 
            winner[x] = rand() % 25 + 1; //makes random numbers between 1 adn 25
            
            /*after the firt cycle, use another variable i, which checks to see if the current x is an duplicate 
            of the values in the past, this is why this for loop doesn't run the first iteration. after the second,
            it will check the winner[0] value and compare it to winner[1].*/
            for (i = 0; i < x; i++){
                if (winner[x] == winner[i]){
                    duplicate = 1; // if duplicate is found duplicate is true, and the for loop stops
                    break;
                }
            }

        }while(duplicate ==1); // condition for the foor loop to be true, and return back, if not, go to next line
        cout << winner[x] << " "; // prints out the random numver stored in winner[x] 1x4 array, then circle back to for loop. 
    
    }

    /*winner[x] starts count [0,3] and these displays the results*/
    cout<< "\nThe first winner is contestant: " << winner[0] << endl;
    cout << "The second winner is contestant: " <<winner[1] << endl;
    cout << "The third winner is contestant: " << winner[2] << endl;
    cout << "The fourth winner is contestant: " << winner[3] << endl;    
}