#include <iostream> //always needed, input output tool
#include <string> //all0w access to the string class to be able to write words. 
#include <iomanip> //allows code to be manipulated
using namespace std;// standard namespace

int main()
{
    //set variables to initial conditions
    //doubles means that the variable contains a decimal point, and int means that the variable contains whole numbers only. 
    double debt = 1000;  //sets up the initial debt of 1k dollars
    double months_per_year = 12; //makes the number of months in a year, bc we are making monthly payments
    double interest_rate_per_year = 0.18; // sets the interest rate per year of 18 percent
    double interest_rate_per_month = interest_rate_per_year / months_per_year; //18%/12 is how nmuch a month
    double monthly_payment = 50.0; //creates the monhtly payment
    int months = 0;        //sets up the initial months to be zero, then counts up by 1
    double total_interest_paid = 0; //sets up the initial interest paid, then counts up
    double total_amount_paid = 0; //sets up the total amount paid, then counts up 
    
    //Generates a table intially ussing new setw(n), in the book from Chapter 12, and online search
    //setw sets strings n spaces apart, this is makes the values to be aligned to the right
    //it is also a more efficent way to align the values instead os using tabs and spaces. 
    cout << "Month#" << setw(16) << "Interest" <<setw(16) << "Principal" << setw(16) << "Balance"
         << setw(24) << "Total Interest" << setw(16) << "Total Paid" << endl;
    while (debt > 0) //while the debt is greater than zero, the program keeps running until debt become zero or less than zero
    {
        //sets up the calculation for debt, interest paid, and keeps track the number of months
        double interest = debt * interest_rate_per_month; //calculates the interest needed to be paid
        total_interest_paid = total_interest_paid + interest; //counts up the total_interest_paid
        debt = debt + interest; //counts up the debt
        months = months  + 1; //counts up the month
        double principle; //creates principle variable that will keep track of principle = principal (spelling error)
        
        //sets up if else statement so that if the debt is greater than the monthly payment it will subtract it
        //if it is anything else it will prevent debt from being negative number and ends to program because debt is 
        //is not greater than 0.00.
        //only happnes when debt is greater than the monhtly payments of 50 dollars
        if (debt > monthly_payment){
            debt = debt - monthly_payment; //debt(with interest) minus monthly payment
            total_amount_paid = total_amount_paid + monthly_payment; 
            principle =  monthly_payment - interest;
            //setw(n) is a useful command that can be used to set the table width evenly apart, and help with alignment
            cout << fixed << setprecision(2);
            cout << setw(6)<< months << setw(11)<< "$"<<setw(5) << interest << setw(11)<< "$"<<setw(5)
            << principle << setw(10)<< "$"<<setw(6) 
            << debt <<setw(24) 
            << setw(18)<< "$"<<setw(6)<<total_interest_paid<< setw(9)<< "$"<<setw(7)<< total_amount_paid << "\n";
        }
        else { //when the debt is less than the monthly payment, we will pay the remaining balance, instead of 50 dollars
            total_amount_paid = total_amount_paid + debt;
            principle =  debt - interest;
            debt = 0.00;
            cout << fixed << setprecision(2); //sets the calculation percision to be zero. 
            cout << setw(6) << months 
            << setw(11)<< "$"<<setw(5) << interest 
            << setw(11)<< "$"<<setw(5) << principle 
            << setw(10)<< "$"<<setw(6)<< "0.00" //the debt amount, just set it to zero for simplicity
            << setw(18)<< "$"<<setw(6) << total_interest_paid 
            << setw(9)<< "$"<<setw(7) << total_amount_paid << "\n";
    }

    }
}
