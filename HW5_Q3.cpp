#include <iostream> //allow the use of input output tools
#include <string> //need to access string class
#include <iomanip> //need to access the manip class to set percision
#include <vector> //need to access vector class
using namespace std; //allow the use of standard library tools without std::

//needs a order class that has a private vecotr of type Pizza

class Pizza{
    int type; //keep track of deep_dish, hand_tossed, or pan;
    int size; //will keep track of small, medium, or large pizza
    int toppings; //will track the nuber of toppings

    public:
    
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

    //member functions
    //gettting input
    void get_input();

    //computing price
    double compute_price();

    //output descripton
    void output_description();

};

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
    cout << "Please Enter the [1,2,3] for the pizza you want: ";
    cin >> type;
    cout << "\nChoose the size of pizza you want: " <<endl;
    cout << "------------------------------------------"<<endl;
    cout << "1: Small [$10] \n2: Medium [$14] \n3: Large [$17]" << endl;
    cout << "------------------------------------------"<<endl;
    cout << "Please Enter the [1,2,3] for the size you want: " ;
    cin >> size;
    cout << "\nEnter the number of toppings [$2 Each]: " ;
    cin >> toppings;
    //too complicated, but another approach class approach
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
//computes the price for the pizza
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

//outputs the description of the pizza ordered. Each pizza type is defined to a integer, so this makes it easier to outputthe description, 
//bc the initally i couldnt output a string that had a space
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

    if (size == 1){
        size_name = "Small";
    }
    else if(size == 2){
        size_name = "Medium";
    }
    else if (size == 3){
        size_name = "Large";
    }

    //cout << "------------------------------------------"<<endl;
    //cout << "\nOrder Description: "<< endl, this way it will print the price along with the description for each pizza for the ones that they ordered
    cout << size_name << " " << type_name << " Pizza w/ " << toppings << " toppings." << " Price: $" << fixed << setprecision(2) << compute_price() << endl;


}

//adding a order class
class Order{
    vector<Pizza> pizza_ordered; //this is the vector class for pizza
    public: 
    void add_pizza(const Pizza &pizza1){
        pizza_ordered.push_back(pizza1); //places new element in the next avaible spot inthe array, creates and array [pizza1, pizza2, etc.....]

    }
    //calculates the total price
    double total_price(){
        double total_price; // the total prices can be changed 
        for (int i = 0; i < pizza_ordered.size(); i++){
            total_price += pizza_ordered[i].compute_price(); // compute the price for x amount of times, for the number of pizzas ordered of the same pizza type
        }        
        return total_price;
    }

    //print out the output description for the pizza ordered
    void print_order(){
        for (int i = 0; i < pizza_ordered.size(); i++){
            //cout << "\n-----------------------------------------------------"<<endl;
            //cout << "Order Summary: " << endl;
            //cout << "-----------------------------------------------------"<<endl;
            cout << "Pizza #" << i + 1 << ": ";
            pizza_ordered[i].output_description(); // prints description for each pizza ordered, so the prices can be seen, alongside the outstanding balance.
            cout << endl;
        }
        //cout << "Total Price: $" << fixed << setprecision(2) << total_price() << endl; can be added later
    }

};

int main(){
    Pizza p1;
    Order order;
    char choice;
    do{

        p1.get_input(); //member function
        order.add_pizza(p1);

        cout << "Would you like to order another pizza? (y/n): ";
        cin >> choice;
    }while (choice == 'y' || choice == 'Y');
    cout << "\n-----------------------------------------------------"<<endl;
    cout << "Order Summary: " << endl;
    cout << "-----------------------------------------------------"<<endl;
    order.print_order(); //called the member function
    
    cout << "-----------------------------------------------------"<<endl;
    cout << "Total Price: $" << fixed << setprecision(2) << order.total_price() << endl;
    cout << "Thank you for your order!\n\n" << endl;
    // cout << "Your Total Is: $" << fixed << setprecision(2) << order.total_price() << endl;

}



