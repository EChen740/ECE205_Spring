//Hw1_Q2_Elvis_Chen
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    double hourly_pay = 36.75; //regular wage, excluding overtime
    double overtime_rate = 1.5; // 1.5x the regular wage
    double social_security = 0.06;
    double income_tax = 0.15;
    double state_tax = 0.04;
    double bethlehem_local_tax = 0.01;
    double union_due = 20;
    double additional = 40; //if over 2 people
    double regular_hours = 40; //regular hours per week
    double hours_worked;
    double dependents;
    cout <<"-----------------------------------------------------------------------";
    cout << "\nHello reader, this program will calculate your net salary per week.";
    cout << "\nPlease enter how much hours you work per week: ";
    cin >> hours_worked;
    cout << "Please enter the number of dependents you have: ";
    cin >> dependents;

    double gross_pay;
    if (hours_worked > 40)
        gross_pay = overtime_rate * hourly_pay * (hours_worked - 40.0) + hourly_pay * regular_hours;
    else
        gross_pay = hourly_pay * hours_worked;

    double net_pay;
    if (dependents > 2)
        net_pay = gross_pay - gross_pay * (social_security + income_tax + state_tax + bethlehem_local_tax) - union_due - additional;
    else 
        net_pay = gross_pay - gross_pay * (social_security + income_tax + state_tax + bethlehem_local_tax) - union_due;

    cout << "Your weekly income is: " <<fixed<< setprecision(2)<< net_pay << endl;

    return(0);


}
