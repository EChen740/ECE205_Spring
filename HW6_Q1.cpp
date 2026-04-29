#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <vector> //need to access vector class
using namespace std; //allow the use of standard library tools without std::


//--Prototype fnctions

//First Step: Set up getting the input
vector <int> get_input();

//Second Step: Set up to compute the histogram: 
void compute_histogram(vector<int> &vector1, vector<int> &bin);

//Step 3: Prinitng out the histogram
void print_histogram(vector<int> &bin);

//main function
int main(){
    vector <int> output_vector = get_input();
    vector <int> bin; //setting up bin, intial bin size will be zero
    compute_histogram(output_vector, bin); //calls the function to compute the histogram
    print_histogram(bin); //calls the histogram to print the histogram 

}



//First step: getting the input
vector<int>  get_input(){
    vector <int>myVector;
    int number;
    cout << "Please enter a non negative number: ";
    cin >> number;
    while (number >= 0){ //when the number is greater than or equal to zero, the while loop will continue true 
        myVector.push_back(number); //store the number
        cout << "Please enter a non-negative integer. enter a negative number to end: ";
        cin >> number;
    }return myVector; //this will return a vector for the get_input, which will be an int 
} 


//Second step: computing the histogram
void compute_histogram(vector<int> &vector1, vector<int> &bin){//bin is a reference parameter bc it is a void function, and after thisfunction is complete, i can call bin 
    for (int x : vector1){ //for x to the vector1, this will kind of read it
        int bin_index = x / 10; //this calcualtes the bin index ex, x = 29 / 10 = 2 etc...
        if (bin_index > static_cast<int>(bin.size())){ //makes the bin.size() a int, bc it is a unsigned type at first 
            bin.resize(bin_index + 1, 0); //this will resize the bin the be one greater and all be filled with zero at the start so later they can be filled in with a value
        }
        bin[bin_index]++; // if this is smaller than the current bin size, then it will just add one to the index of the bin array.
    }   
}

//Step 3: Prinitng out the histogram
void print_histogram(vector<int> &bin){
    cout << "\nHistogram" << endl; //print out title
    for (int i = 0; i < static_cast<int>(bin.size()); i++){//this will print out the values from the computed_histogram stored in the bin
        cout << (i*10) << " -> "<< (i*10+9) << ": " <<bin[i] << endl; //this will output everything stores in the bin, which held the histogram. 
    }
}



