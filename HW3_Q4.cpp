#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff



void conversion(int llb, int oz, int &kg, int &g){ // ised &kg and g becasue we want the kg and g to be constant from this function
    //kg = llb / 2.2046; //this is how much pound is in kg
    //g = kg / 1000; // this is how much kg is in g;
    double total_oz = llb * 16 + oz;
    // double total_llb = total_oz / 16; // this will show how much llb is in the total oz
    double total_kg = total_oz / (2.2046 * 16); //this will show how much kg is in the total llb
    // get kg to integer
    kg = static_cast<int>(total_kg); // converts to int, omits everything after the decimal
    double g_leftover = (total_kg - static_cast<int>(total_kg)) * 1000; // this will give us the leftover kg in g, we multiply by 1000 to get g and we should be all set
    g = static_cast<int>(g_leftover); // converts to int, omits everything aftre decimal
}

void get_input(int &llb, int &oz){ // kept &llb and &oz becasue we want pounds and ozes to be constant after this function

    cout << "Enter how much pounds (whole number): ";
    cin >> llb;
    //essentially for this do while loop, we are making sure that the number enetered for oz is less than 16, otherwise it will be invalid
    do{
        cout << "Enter how much oz(whole number): ";
        cin >> oz;
        if(oz >= 16){
            cout << "Try again, please enter a valid number of oz between 0 and 15." << endl;
        }
    }while(oz >= 16);
}

int main(){
    int llb, kg, g, oz; //set up variables to all be int, so it stay contigent with our parameters needed to input into the get_input and conversion function. 
    char choice; // used char choice becasue this allows us to let if the reader choice was yes or no later. 

    do{ // i include a do while loop to allow the reader to convert weights multiple times. 
    get_input(llb, oz);
    conversion(llb, oz, kg, g);
    cout << "Your converted weight is " << kg << "kg " << g << "g." << endl;
    cout << "Dear Reader, would you like to convert another weight? [Y/N]: ";
    cin >> choice;
    } while((choice == 'y') ||(choice == 'Y'));


}
