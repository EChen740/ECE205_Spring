
#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
using namespace std; //allow the use of standard library tools without std::



class BicycleSpeedOdometer{

    double distance_traveled; //sets distance_traveled to be in private
    double time_taken; //sets time_taken traveled to be in private

    //sets up public variables
    public:
        //muator
        double get_distance(double distance1){
            if(distance1 >= 0){
                distance_traveled = distance1;
            }else{
                cout << "Invalid Distance Input [Distance = 0]" << endl;
                distance_traveled = 0.0;
            }
            return distance_traveled;
        }
        //mutator
        double get_time(double time1){ 
            if(time1 >=0){
                time_taken = time1;
            }else{
                cout << "invalid Time Input [Time = 0]"<< endl;
                time_taken = 0;
            }
            return time_taken;
        }
        
        //member function
        double avg_speed(double distance1, double time1);

};

//create average speed function outside instead of inside class, take in distance and time as parameter to be used inside the function f(x,y) to callcualte the average speed. 
double BicycleSpeedOdometer :: avg_speed(double distance1, double time1){
    double avg_speed = (distance1) / (time1/60.0); // thsi will find the avg speed mph, miles per hour
    return avg_speed;
}

int main(){
    BicycleSpeedOdometer b1; //sets up the speedometer
    double distance;
    cout << "Input the distance traveled [miles]: " << endl;
    cin >> distance;
    double x = b1.get_distance(distance); // set x to be the distance inputted by the reader

    double time;
    cout << "Input the time taken [minutes]: " << endl;
    cin >> time;
    double y = b1.get_time(time); // set y to be the time inputted by the reader
    //b1.avg_speed(x,y); // not needed
    cout << fixed << setprecision(2) << "Your average speed is " << b1.avg_speed(x, y) << " miles per hour." << endl;


}
