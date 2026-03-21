#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff

//create function to print the chart, will update accordinly
void print_chart(char seats[3][3]){
    for (int i = 0; i < 3; i ++){
        //cout << i + 1 << "  ";
            for (int j = 0; j < 3; j++){
                cout<< seats[i][j] << "  ";
            }
            cout <<endl;
        }
}
void intro(){ //give intro
    cout << "\nWelcome Player1 (X) and Player 2 (O), here is the tik tak toe board"<< endl;
    cout << "\nTik-Tac Tow Board:\n" << endl;
}

//takes in the values,some are needed to have updates for it work work, ones with &
void player1_get(int &player1_move, int &row_number1, int &column_number1, char seats[3][3]){
      //will do this as long as the player enters invalid number or the spot is already filled
    do{ ///p1 first move
        cout << "\nPlayer1, select a number ";
        cin >> player1_move;

        if(player1_move < 1 || player1_move > 9){
            cout << "Invalid Number, Please input a number [1-9]" << endl;
        }else{
            row_number1  = (player1_move -1)/3;
            column_number1 = (player1_move -1) %3;} // modulus is used for this, and so happens to work well
            
            //this will turn the number that player1 chooses to be in row and column
            // /3 will output the nearest whole integer for this, if it is 7, 7-1=6 6/3 = 2, therefore row 2
            if((seats[row_number1][column_number1] == 'X') || (seats[row_number1][column_number1] == 'O')){
                cout << "INVALID SPOT, Please Try again" << endl;
            }
    }while(player1_move < 1 || player1_move > 9 || (seats[row_number1][column_number1] == 'X') || (seats[row_number1][column_number1] == 'O'));
}

//same concept as part1, its just changing the varirables. 
void player2_get(int &player2_move, int &row_number2, int &column_number2, char seats[3][3]){
    do{ //P2 first move
        cout << "\nPlayer2, select a number ";
        cin >> player2_move;

        if(player2_move < 1 || player2_move > 9){
            cout << "Invalid Number, Please input a number [1-9]" << endl;
        }else{
            row_number2  = (player2_move -1)/3;
            column_number2 = (player2_move -1) %3;} // modulus is used for this, and so happens to work well
            
            //this will turn the number that player1 chooses to be in row and column
            // /3 will output the nearest whole integer for this, if it is 7, 7-1=6 6/3 = 2, therefore row 2
            if((seats[row_number2][column_number2] == 'X') || (seats[row_number2][column_number2] == 'O')){
                cout << "INVALID SPOT, Please Try again" << endl;
            }


    }while(player2_move < 1 || player2_move > 9 || (seats[row_number2][column_number2] == 'X') || (seats[row_number2][column_number2] == 'O'));
}

// we are going to check to winner, using a true or false output, put inot if statement later
bool check_winner(char seat[3][3], char symbol){
    for (int i = 0; i <3; i++){ //winner if the row all have the same symbol
        if ((seat[i][0] == symbol) && (seat[i][1] == symbol) && (seat[i][2] ==symbol)){
            return true;
        }
    }
    for (int j = 0; j < 3; j++){ //winner if any of the column have the same suymbol
        if ((seat[0][j] == symbol) && (seat[1][j] == symbol) && (seat[2][j] == symbol)){
            return true;
        }
    }
    //if diagonals are solutions
    if ((seat[0][0] == symbol) && (seat[1][1] == symbol) && (seat[2][2] == symbol)){
        return true; 
    }
    if ((seat[0][2] == symbol) && (seat[1][1] == symbol) && (seat[2][0] == symbol)){
        return true;
    }
    return false; //if none of these work
}




int main(){
    char seats[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    intro();

    // this prints out the array, it first go through the first row, then start the next row in the next line after it goes through thru all the columns
    print_chart(seats);
    int player1_move, row_number1, column_number1,player2_move, row_number2, column_number2; //declared these as integers so they work in the while () in the do{}while() relation
    
    //Move 1
    cout <<"\nMove 1" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);

    //Move 2
    cout <<"\nMove 2" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);

    //Move 3
    //move three is essential becasue once past move three, winners are possible, therefore once there is winners, we return 0, to exit the progrma
    cout <<"\nMove 3" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }   


    //Move 4
    cout <<"\nMove 4" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }

    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }   



    //Move 5
    cout <<"\nMove 5" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }

    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }   



    //Move 6
    cout <<"\nMove 6" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }   

    //Move 7
    cout <<"\nMove 7" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }   

    //Move 8
    cout <<"\nMove 8" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }

    //Move 9
    //lasty if there is no winners, there is a draw, therefore return a draw if there is not combinations. 
    cout <<"\nMove 9" << endl;
    //Player 1
    player1_get(player1_move, row_number1, column_number1, seats);
    seats[row_number1][column_number1] ='X';
    print_chart(seats);
    if (check_winner(seats, 'X')){
        cout << "PLAYER1 IS A WINNER!"<< endl;
        return 0;
    }else{
        cout << "DRAW" << endl;
        return 0;
    }
    //Player 2
    player2_get(player2_move, row_number2, column_number2, seats);
    seats[row_number2][column_number2] ='O';
    print_chart(seats);
    if (check_winner(seats, 'O')){
        cout << "PLAYER2 IS A WINNER!"<< endl;
        return 0;
    }else{
        cout << "DRAW" << endl;
        return 0;
    }


}
