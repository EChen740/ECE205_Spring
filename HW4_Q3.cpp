#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

//void print_seat(){

//}


char choice; //sets us the character choice 
int main() {
    // Seat layout (10 rows, 4 seats each)
    //char allows us to hold letters. 
    char seats[10][4] = {
        {'A','X','C','D'},
        {'A','B','C','D'},
        {'A','B','C','X'},
        {'A','B','C','D'},
        {'X','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'},
        {'A','B','C','D'}
    };

    do{ //we will do this function again as long as the user wants to enter another seat.
        cout << "\nSelect your seat using the chart below. 'X' means the seat is taken"<< endl;
        cout << "\nSeating Chart:\n" << endl;

        // this prints out the array, it first go through the first row, then start the next row in the next line after it goes through thru all the columns
        for (int i = 0; i < 10; i ++){
        cout << i + 1 << "  ";
            for (int j = 0; j < 4; j++){
            cout<< seats[i][j] << "  ";
            }
            cout <<endl;
        }
        int row;
        char letter;
        int column_number; // have to declare it here so the while loop can identify the column_number as int
        do{
            cout << "Enter seat row [1-10]: ";
            cin >> row;
            cout << "Enter Seat Letter [Uppercase A-D]: ";
            cin >> letter;
            
            // A cool technique is that we can number the letter, bc they are in ASCII, subtract A from the we will get the number, this is how u turn a char to int
            // A = 65 and B = 66, so B = B-A = 1, reader will not see this part
            column_number = letter - 'A';

            // here if we determine if the row is less than 1 or greater than 10, or the column is not [A,D], then it will be invalid. 
            if (row < 1 || row > 10 || column_number < 0 || column_number > 3){
            cout << "Invalid input, Try again.\n";
            }

            else if (seats[row - 1][column_number] == 'X'){
            cout << "This seat is already taken, please choose another one" << endl;
            } 
            }while (row < 1 || row > 10 || column_number < 0 || column_number > 3 || seats[row - 1][column_number] == 'X');

        seats[row - 1][column_number] = 'X'; // this will update the seating chart when the user chooses to pick another seat

        cout << "Your seat is sucessfully booked" << endl;

        cout << "Would you like to book another seat? [Y/N]";
        cin >> choice; // this is if the user inputs an answer


    }while (choice == 'Y' || choice == 'y'); // takes both capital and lowercase letters. 
}

        

