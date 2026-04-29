#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <vector> //need to access vector class
using namespace std; //allow the use of standard library tools without std::


/*Write a program that takes user input for a list of 
characters. Use vectors for storage. The program will then scan 
the characters, delete any repeated entries, and sort the vector
 in decreasing (z to a) order using selection sort. Prompt the user to enter a 
 character, one at a time. To stop user input, 
the user will enter 0 (character '0'). Write a function*/

//Prototype: 

//Step 1: get the input function down
vector <char> get_input();
//Step 2: delete the deuplicate letters
void deleteRepeatedChars(vector<char>& vector); //use the & so that the void function doesnt need to return anything 
//Step 3: order the vector from z->a
void selectionSort(vector<char>& myVector);



int main(){

    vector<char> input_vector = get_input(); //input_vector is now equal to myVector
    cout << "\nYou Entered: ";
    for (char i : input_vector){
        cout << i << " ";
    }
    cout << endl;

    //remove the deleted letters
    deleteRepeatedChars(input_vector);
    cout <<"After removing the duplicates, your output will be: "<< endl;
    for (char y : input_vector){
        cout << y << " ";
    }
    cout << endl;
    //sort them out from z ->a, uses ascii so i can just do if x > y 
    selectionSort(input_vector);
    cout <<"After sorting the vector, vector will be output from z->a order: "<< endl;
    for (char x : input_vector){
        cout << x << " ";
    }
    cout << endl;
}

//Step3: sort from z-> a

void selectionSort(vector<char>& myVector){
    for (int i = 0; i < myVector.size() -1; i++){//myVector has to be -1 from amx otherwise there is no other vectors to comapre
        int index=i; //place holder
        //check it with the other vectors to see if it is greater or less 
        for (int j = i +1; j < myVector.size();j++){//we want it to check all thewa through 
            if(myVector[j] > myVector[index]){ //if the vector that we check after i is greater than the one it is at, we want to swap places 
                index = j; // bc j is greater the index will not be j
            }
        }
        swap(myVector[i], myVector[index]);
    }
}


//Step 2: delete the deuplicate letters
void deleteRepeatedChars(vector<char>& vector){ //the & keeps the copy of the vector, so this is what the variable it takes in gonna be 
    for (int i = 0; i < vector.size(); i ++){
        for (int j = i + 1; j < vector.size(); j++){
            if (vector[i] == vector[j]){
                vector.erase(vector.begin() + j); //will delete the vector at veector[j]. it will erase the vector j value after the the first number. 
                j--; //j should stay the same after removing the duplicate, making sure the next one is not duplciate 
            }
        }
    }
}


//Step 1: Start the function to get the input
//the user will enter as much letter, before they enter 0, which will stop collecting user inouts. 
vector<char> get_input() {
    vector<char> myVector;
    char letter_input; //enters the letter until the user enters 0, then program will stop 

    cout << "Enter a letter, enter 0 to stop: ";
    cin >> letter_input; //users enter the letter

    while (letter_input != '0') { //while the letter is not zero, then it will keep askign the user to entr a letter, when the letter is 0, then break the loop,
        myVector.push_back(letter_input);
        cout << "Enter a letter, enter 0 to stop: ";
        cin >> letter_input;
    }

    return myVector;//get_input will return myVector, as a vecter<char>
}