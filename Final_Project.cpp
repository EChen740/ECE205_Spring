#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// prototypes
int order_importance(char operation); //makes sure that multiplication and division comes first 
bool operator_check(char operation); //checks to see if it is a valid operator and nothing else
int evaluate_postfix(string postfix); //calculate the outputted post fix value

//method: Inflix => output postfix expression => calculate postfix expression => print out result 
int main() {
    cout << "\n-----------------------------------"<< endl;
    cout << "Hello reader welcome to my program " << endl; 
    cout << "This program will take a expression, convert it to postfix form, and then evaulate. " << endl;

    string expression; //= "(168+2)*5-28/4"; //input expression
    cout << "Please Enter an expression (no spaces needed): ";
    cin >> expression;
    cout << "You have entered: " << expression << endl; //input lines
    string postfix = ""; //postfix intialization



    stack<char> ochar; // this will later be used to hold operators and () stuff;

    //infix to postfix operation: 
    for (int i = 0; i < expression.length(); i++) { //go thru each indent on the string expressions
        char x = expression[i];//set x to be the number of the indent;

        if(isdigit(x)){ //checks to see if x is a number, if it is then set up the string nums up
            string nums = "";
            //while loops allows multidigits
            while(i < expression.length() && isdigit(expression[i])){//makes sure that the value will continue to go until they hit a operator, which will stop
                nums += expression[i]; //adds this to nums, nums = nums + x;
                i++; //adds up number until it hits a nondigit;
            }
            i--;//this will subtract the i++ done in the for loop, that kicked it out, now the operator will return to the for loop which will add 1 to the i;
            postfix = postfix + nums + " "; // this will adds the number up the operator. this allows multidigit number
        }

        //check other operator and what to do then:
        else if (x == '('){
            ochar.push(x);//temporary stores x into the stack
        }

        //check close parthenetsis
        else if (x == ')'){ //never add closing parthenteisis to stack
            while(!ochar.empty() && ochar.top() != '('){
                postfix += ochar.top(); //adds the operator from the top of the stack of operators which likely includes [(, some operator, )]
                postfix += " "; //adds space
                ochar.pop(); //removes the top operator
            }
            ochar.pop(); //removes the "(" from stack
        }

        //checking the operator
        else if(operator_check(x)){ //operator will check, bool function if operator it will run if not it wont 
            // if the stack is not empty, and the operator that is currently there is larger than the one coming in, then it must be put out side,
            while(!ochar.empty() && order_importance(ochar.top()) >= order_importance(x)){
                postfix += ochar.top(); //this adds the greater ooperator
                postfix += " "; // adds a space
                ochar.pop(); 
            }
            ochar.push(x); //if the current oerator is more important or ifd the stack if empty we insert this, skip the while loop
        }
    }
    //this will read the ones the operands that are left over. If there is too muc operators but not enough numbers 
    while (!ochar.empty()) {
        postfix += ochar.top(); // same thing as before read the stornger operand, add that to the postfix
        postfix += " "; //add space
        ochar.pop(); //pop that value, and read the nuext one until empty, while loop will break and postfixes will be printed out. 
    }
    cout << "Postfix Expression: " << postfix << endl;
    
    int result = evaluate_postfix(postfix);
    cout << "Calculated Result: " << result << endl;

    return 0;

}

//prototype 

//pemdas
int order_importance(char operation) {
    if (operation == '*' || operation == '/') return 2;
    if (operation == '+' || operation == '-') return 1;
    return 0;
}

// check operator
bool operator_check(char operation) {
    if (operation == '+' || operation == '-' || operation == '*' || operation == '/'){
            return true;
    };
    return false;
}

//postfix evulation: 
//calculate the outputted post fix value
int evaluate_postfix(string postfix){
    stack<int> answer; //make a stack call answer to hold the calculated value
    string num = ""; //start a number string once everything is apprehended make it into a int

    for(int i = 0; i < postfix.length(); i++){ //cehck every indent in the posftfix stiring made earlier
        char x = postfix[i];//set x to equal to the postfix indent value

        if(isdigit(x)){ //of x ios a digit add it to the number
            num +=x; //adds x to the numbers and continue to add numbers after that
        }

        // if x is a space, and the if number is not empty:
        else if( x == ' ' && !num.empty()){
            answer.push(stoi(num)); // force the string number to be a intk and then push it into stack number 
            num = ""; // new initializaation:
        }

        //checks the operator once we hit the operator
        else if(operator_check(x)){
            int top = answer.top(); //take the top value [5,3] tale 3
            answer.pop(); //pop that value 
            int bottom = answer.top(); //take the lower value [5,3] take 5
            answer.pop(); //pop the bottom value

            if(x == '+'){ //plus operator
                answer.push(bottom + top);
            }
            if(x == '-'){ //minus operator
                answer.push(bottom - top);
            }
            if(x == '*'){ //x operator
                answer.push(bottom * top);
            }
            if(x == '/'){ //divide operator
                answer.push(bottom / top);
            }
        }
    }
    return answer.top(); // returns the answer
} 

