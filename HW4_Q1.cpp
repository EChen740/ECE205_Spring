#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

// &index means that the index will get updated and will change to the new value.
void fill_array(int a[], int size_array, int &index){
    index = 0;
    int value;
    int his[10] = {0}; //this will create a 1x10 array, each array 0-9, 10-19 etc, zero for initial start 
    for (int i = 0; i < size_array; i++){

        // while do function will loop while there is an invalid input, this stops the for loop count of i from going forward. 
        do{
            cout << "Enter positive value (between 0 and 99 to keep things simple) " << i + 1 << ": ";
            cin >> value;
            if (value < 0 && value > 99){
                cout << "Enter a valid number. " << endl;
            }else {
                a[index] = value; // sets each a[i] with their respect values 
                int his_index = value / 10; //this will organize the entered number, bc they will get the ten's value
                his[his_index]++; // means for every time we go thru a number, it will add a value to that column 
                
                // this is just to make sure that the numbers are not negative not needed 
                /*if (his_index >=0){
                    his[his_index]++; // means for every time we go thru a number, it will add a value to that column 
                }*/

                index ++; // increases the index by 1, permanently.

            } 
        }while(value < 0 && value > 99);
    }
    cout << "\nHistogram\n";
    for (int i = 0; i < 10; i++){
        cout << i*10 << " to " << i*10 + 9 << ": " << his[i] << " value[s]" << endl;
    }

}

// this function will ask the reader to call for how many numbers they want to enter
int get_array_size(){
    int size_of_array;
    cout << "How many numbers do you want to enter: ";
    cin >> size_of_array;
    return size_of_array;
}

// this is our main function, the function that does everything
int main(){
    // this function will set the variable to the value output by the get_array_size chosen by reader
    int size_of_array = get_array_size(); 
    int a[size_of_array]; // sets up the size of a[the number of variables we want to enter]
    int index_value; // initilize the index_value to be some integer

    //call the fill_array function, and this will do all the work for us
    //technically the a[] doesn't do much, but keep for now. 
    fill_array(a, size_of_array, index_value); 
}