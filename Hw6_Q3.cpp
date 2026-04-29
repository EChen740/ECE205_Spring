#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <vector> //need to access vector class
using namespace std; //allow the use of standard library tools without std::


/*A prime number is an integer greater than 1 and divisible only by itself and 1. Implement the
Sieve of Erathosthenes algorithm to find all prime integers less than a user-entered integer N. More
information on the algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes . Use vectors in
your implementation and output all prime numbers calculated to the console.*/


//prototypes: 
int get_input(); //this function will get the input number for this 
vector <int> convert_vector(int number); //thsi will convert the integer that we into into a avector 
void check_prime(vector <int> &avector); //thirs step, check if the numbers are prime 

//set up the main function
int main(){
    cout << "Welcome to my program, today we will find all the prime numbers less than the integer you input"<<endl;
    int int1 = get_input(); //int1 will be equal to what get_input() gave us
    if(int1 < 2){ //is the number is less than two, the return that the number is not valid. 
        cout << "Number is not valid. Please enter a number greater than 2." << endl;
        return 0; // if number is less than 2, 
    }
    
    vector <int> output_vector; //sets the output vector so then this can be filled with numbers leading up to that number
    output_vector = convert_vector(int1); //the new vector will eb called output vector andwill take in int1, output_vector is now equal to the return myvector below. 
    cout << "We will check which one of these numbers are prime: "<<endl;
    for (int y : output_vector){ //outputs the vector so that the user can see it. 
        cout << y << " ";
    }
    cout << endl;


    //after checking the prime numers in check_prime using the SoEA method
    cout << "These numbers are prime: ";
    check_prime(output_vector); //checks which numbers of the output_vectors are prime , and a copy of that will be sent to the out_put vector, this then lets use print out all the prime numbers that did not fail the test
    for (int z : output_vector){
        cout << z << " ";
    }
    return 0;
}


void check_prime(vector <int> &avector){ //thirs step, check if the numbers are prime 
    int w = avector.back(); // the last vector value

    vector<bool> prime_ch(w + 1, true); //initially we will make every vector to be true. if the number is 10, the new vector size will be 11 to include the zero 0:10
    prime_ch[0] = false;
    prime_ch[1] = false;

    //now using the sieve of eraosthenes:
    
    //first on essentially go up by two, the equared cannot be graeter tha the greatest integer
    for (int i = 2; i * i <= w; i++) {
        if (prime_ch[i]) {
            for (int j = i * i; j <= w; j += i) {//every 2x is false, every 3x is false etc.... 
                prime_ch[j] = false;
            }
        }
    }


    vector<int >prime_numbers; //make a new vector to take in the prime numbers, whcih will be the reamining vector in the pervious vector that is not false 
    for (int number: avector){
        if(prime_ch[number]){ //true
            prime_numbers.push_back(number);//then this will push_back the numbers.
        }
    }
    avector = prime_numbers; //a vector will equal to the prime_numbers and output this 
}
//step2: convert the number into a vector from 1-____
vector <int> convert_vector(int number){
    vector<int> myVector; //makes a new vector clalled myVector
    for (int i = 0; i < number; i++){
        myVector.push_back(i+1); // the vector will push back 1 value large, so when i = 0, the vector will store 1 
    }
    return myVector; //this returns for myVector vector<int> this can later be set to another vector<int> 
}


//step 1: get an input
int get_input(){
    int inte; //set up inte as a integer
    cout << "Please enter a integer: ";
    cin >> inte;
    return inte; //return this number, will be set equal to something else later 
}


