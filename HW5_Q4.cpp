#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <vector> //need to access vector class
using namespace std; //allow the use of standard library tools without std::

//prime number means that a number is not divisible by any number beside 1 and itself. 
class PrimeNumber{
    int number; //numher is a int, and this will check if the number is a prime number or not

    public:
    //mutator for number, sets the number inputted by the user
    void set_number(int n){
        number = n;
    }

    //accessor for number
    int get_number(){
        return number; //returns the number inputted by the user and is tored int he private poart of the class
     }

     bool prime(int n){
        if (n <= 1){
            return false; // if the number is less than or equal to 1, it is not a prime number
        }
        //initialize i to be equal to 2, and it is less than n, it will take each value at a time and see if it is divisible by n, if it is, then it will output false: number is not prime
        for (int i = 2; i < n; i++){
            if (n % i == 0){
                return false; // if the number is divisible by any number between 2 and itself, it is not a prime number, eamning the remainder it zero.
            }
        }
        return true; // if the number is not divisible by any number between 2 and itself, it is a prime number
     }

     //output the next prime prime number
     int next_prime(int number){
        int next = number + 1; // the next prime will have to be one more than the curent prime number
        //a for loop that goes up to infinity should be implemented, but a while loop would be more simple
        while(true){
            if(prime(next) == true){//if the prime of the next number is true, than it will return that number}
                return next; //return the prime number as an integer
        }
        //if this if statement is not true, then one will be added continously until the next prime nuber is found
        next++; // this will add the next number b one
        };
    }


     //output the previous prime number
     int prev_prime(int number){
        int prev_num = number -1; //previous prime number have to be at leadt on less than its current value. 
        while(true){
            if(prime(prev_num) == true){ //if the prime nuber of previous number is true, this will return that number
                return prev_num; //return the prime number as int
            }
            prev_num --; //this will subtract one value from the current value this function is on
        }
     }

};

int main(){
    PrimeNumber p1; //creating p1 as an object so that it can be used to call the functions it contains 
    int num; //sets up the number baraible 
    bool prime;
    cout << "Input a number: ";
    cin >> num; //takes in a number
    p1.set_number(num); //sets the number inputted by the user to be stored in the private part of the class, this will set the num to ben which will be equal to the number in the private 
    prime = p1.prime(num); //sets the boolean variable prime to be the output
    if (prime){
        cout << num << " is a prime number!" << endl;
    }else{
        cout << num << " is not a prime number!" << endl;
    }
    cout << "Next prime number: " << p1.next_prime(num) <<endl; // this should output the next prime number, going to test using 13, next prime number should be 17
    cout << "Previous prime number: " << p1.prev_prime(num) << endl; //this will output the previous prime number
    return 0;


}