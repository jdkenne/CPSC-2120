#include <string>
#include <iostream>
#include <stack>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    stack<int> Stack; 
    int val1;
    int val2;
    int exp;
    if (length == 0) {
        return 0;
    }
    if(length == 1 && !isdigit(expression[0][0])) {
        return 0;
    }
    if(length == 1 && isdigit(expression[0][0])) {
        exp = stoi(expression[0]);
        return exp;
    }
    if(length <= 2 && !isdigit(expression[1][0])) {
        return 0;
    }
    if (length <= 2 && isdigit(expression[0][0])) {
            exp = stoi(expression[0]);
            cout << exp << endl;
            return exp;
    } else {
        for (int i = 0; i < length; i++)  {  
            if (isdigit(expression[i][0]))  {
                exp = stoi(expression[i]);
                Stack.push(exp);
            } else {  
                val1 = Stack.top();
                Stack.pop();
                val2 = Stack.top();
                Stack.pop();
                if ( expression[i] == "+") {
                    Stack.push(val2 + val1);                
                    break;
                } else if ( expression[i] == "-") {
                    Stack.push(val2 - val1);
                    break;
                } else if ( expression[i] == "*") { 
                    Stack.push(val2 * val1);
                    break;
                } else if ( expression[i] == "/") {
                    Stack.push(val2/val1);
                    break;
                } else if( expression[i] == "%") {
                    Stack.push(val2 % val1);
                }
            }
        }
    int finalNum = Stack.top();
    Stack.pop();
    return finalNum;
    }
}

int main() {
   string exp[] = {"1"};
   int value = calculatePostfixExpression(exp, 1);
   cout << value << endl;
   return 0;
}
    