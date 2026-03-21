#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

// this is a simple functions that asks for an input. It will take in a value as long as it is in the range. 
double get_degree_of_difficity(){
    double difficulty;
    do{
        cout << "Enter the degree of difficulty (1.2 - 3.8): ";
        cin >> difficulty;
        if (difficulty < 1.2 || difficulty > 3.8){
            cout << "Please enter a valid number." << endl;
        }
    }while(difficulty < 1.2 || difficulty >3.8);
    return difficulty;
}

// this function allows us to input 7 values in a single loop instead of making 7 loops. 
//The do while function is there so that it will check if the scores the judges put are in range. 
void get_score(double a[], int size_array, int &index){
    double score;
    //int i = 0; 
    index = 0;
    for (int i = 0; i < size_array; i ++ ){

        // simple do while function that makes us find a value if the score is not within range. 
    do{
        cout << "Enter different value 1-10: " << "[" << i+1 << "]: "; // this allowe us to keep track of which value we are at. 
        cin >> score;
        if (score < 0 || score > 10){
            cout << "Please try again" << endl;
        }else{
            a[index] = score;
            index ++;
        }      
    }while (score < 0 || score > 10);
    }
}


//this will essentially read the minimum value, it will go through 1, then start at 2, then start at 3 and compare, the smallest values, also in lecture noted
int min_value(double a[], int start_index, int size){

    int min_index = start_index;
    for (int i = start_index; i < size; i++){
        if (a[i] < a[min_index]){
            min_index = i;
        }
    }
    return min_index;
}

// this will reorder the values if the next value is smaller it will go before it. 
void swap_values (double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}


int main(){
    // set difficulty as the output of the function, and we keep that
    double difficulty = get_degree_of_difficity();
    // cout << x;
    double a[7];
    int array_size = 7;
    int index;
    get_score(a, array_size, index);
    
    //this was from class ntoes, it organizes all the values from min to max, then it is easier to omit the lowest and highest
    for(int i = 0; i< array_size; i++){
        int start_index = i;
        int min_index = min_value(a, start_index, array_size);
        swap_values(a[i], a[min_index]);
    }
    
    // this is just there for you to output the numers in order
    /*for (int i = 0; i<array_size; i++){
        cout << a[i++] << " ";
    }
    cout << endl;*/
    
    // the rest of these are just for the calculation
    double sum = 0;
    for (int i = 1; i < 6; i++){
        sum += a[i]; //adds up the seconds through second to last number numbers, ommits first and last
    }
    cout << "Your sum is: "<<sum << endl;

    //calculates the final score
    double final = sum * difficulty * 0.6;
    cout << "Your final score is: " << final << endl;
}

