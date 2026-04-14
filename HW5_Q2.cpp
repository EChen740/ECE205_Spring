#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
using namespace std; //allow the use of standard library tools without std::



class Pizza{
    int type; //keep track of deep_dish, hand_tossed, or pan;
    int size; //will keep track of small, medium, or large pizza
    int toppings; //will track the nuber of toppings

    public:
    
    //define const parameter, help keep track
    /*enum types {
        deep_dish = 1,
        hand_tossed = 2,
        pan = 3
    };

    enum sizes {
        small =1,
        medium = 2,
        big = 3
    };*/

    //mutators for pizza typel size and toppings
    void set_type(int type1){
        type = type1;
    }
    void set_size(int size1){
        size = size1;
    }
    void set_toppings(int toppings1){
        toppings = toppings1;
    }

    //accessors for pizza_type, size and toppings
    int get_type(){
        return type;
    }

    int get_size(){
        return size;
    }
    int get_toppings(){
        return toppings;
    }

    //gettting input
    void get_input();

    //computing price
    double compute_price();

    //output descripton
    void output_description();

};

//basic message to the user and hwo the terminal can be set up 
void Pizza::get_input(){
    //string type_string, size_string;
    cout << "Welcome to my pizza ordering system!\n" << endl;
    cout << "This ordering system will ask you to input numbers. \n" << endl;
    cout << "Please choose from the following option: " << endl;
    cout << "------------------------------------------"<<endl;
    cout << "1: Deep Dish" << endl;
    cout << "2: Hand Tossed" << endl;
    cout << "3: Pan" << endl;
    cout << "------------------------------------------"<<endl;
    cout << "Please Enter the <number> for the pizza you want: ";
    cin >> type;
    cout << "\nChoose the size of pizza you want: " <<endl;
    cout << "------------------------------------------"<<endl;
    cout << "1: Small [$10] \n2: Medium [$14] \n3: Large [$17]" << endl;
    cout << "------------------------------------------"<<endl;
    cout << "Please Enter the <number> for the size you want: " ;
    cin >> size;
    cout << "\nEnter the number of toppings [$2 Each]: " ;
    cin >> toppings;
    //too complicated, but another approach
    /*if (type_string == "deepdish"){
        type = deep_dish; //+> means that type = 0, becasue deep_dish = 0;
    }
    else if (type_string == "handtossed"){
        type = hand_tossed; //this means type = 1, because hand_tossed = 1;
    }
    else if (type_string == "pan"){
        type = pan; //this means type = 2, because pan = 2; 
    }*/

}

//computes the prices of the Pizza, includes the size of the pizza, and then the toppings of the pizza 2 daolors each
double Pizza :: compute_price(){
    double price;
    if (size == 1){
        price = 10.00 + (toppings * 2);
    }
    else if (size == 2){
        price = 14.00 + (toppings * 2);
    }
    else if (size == 3){
        price = 17.00 + (toppings * 2);
    }
    return price;
}

//this gets the description o the pizza ordered based of of its numbers. When the users chooses a numers this program 
//records what the user inputted. 
void Pizza :: output_description(){
    string type_name, size_name;

    if (type == 1){
        type_name = "Deep_Dish";
    }
    else if(type == 2){
        type_name = "Hand_Tossed";
    }
    else if (type == 3){
        type_name = "Pan";
    }

    //also inoudes the size  of the pizza ordered, based off of what the user chose. 
    if (size == 1){
        size_name = "Small";
    }
    else if(size == 2){
        size_name = "Medium";
    }
    else if (size == 3){
        size_name = "Large";
    }

    cout << "------------------------------------------"<<endl;
    cout << "\nOrder Description: "<< endl;
    cout << size_name << " " << type_name << " Pizza w/ " << toppings << " toppings" << endl;


}

int main(){
    Pizza p1; //creating p1 as an object to be used to call the functions in the pizza class
    p1.get_input(); //calls the input member's function
    //p1.compute_price();
    p1.output_description(); // calls the member function 
    //outpouts the price of the pizza ordered. 
    cout << "Total Price: $" << p1.compute_price() << endl;

}