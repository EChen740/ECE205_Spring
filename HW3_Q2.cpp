#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <cmath> // access to math functions, we use pow() for exponents
#include <fstream> // need this to access file, similar to file.read in python
using namespace std; // don't need to write std for cout, cin and other stuff



void function(double a, double b, double c, double &p, double &area){
    p = a + b + c;
    double s = p/2;
    area = sqrt( s*(s-a)*(s-b)*(s-c)); // the formula provided
    cout << "The perimeter of the triangle is " << p << endl;
    cout << "The half perimeter of the triangle is: " << s << endl;
    cout << "The area of the triangle is: " << fixed << setprecision(3) << area << " [units]^2" << endl;
}


int main(){
    double a, b, c, perimeter, area;
    cout << "\n\nDear Reader, welcome to my program." << endl;
    cout << "Today I will ask you for three values and we will determine the area of a triangle" << endl;
    cout << "To start, please enter your value for side a: ";
    cin >> a;
    cout << "Enter your value for side b: ";
    cin >> b;
    cout << "Enter your value for side c: ";
    cin >> c;

    function(a, b, c, perimeter, area ); //allows the function to take in these parameters, and perform the calculation

}