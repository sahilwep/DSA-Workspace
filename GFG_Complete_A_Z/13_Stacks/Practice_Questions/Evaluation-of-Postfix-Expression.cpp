/*
// Evaluation of Postfix Expression

// Example: 

    Input: str = “2 3 1 * + 9 -“
    Output: -4
    Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
            Initially: 2 3 1 * + 9 -
                -> 2 (3 * 1) + 9 -
                -> 2 + (3 * 1) 9 -
                -> (2 + (3 * 1)) - 9 
                ->  5 - 9 => 4

    Input: str = “100 200 + 2 / 5 * 7 +”
    Output: 757
    Explanation: 
            Initially: 100 200 + 2 / 5 * 7 +
                -> (100 + 200) 2 / 5 * 7 +
                -> ((100 + 200) / 2) 5 * 7 +
                -> (((100 + 200) / 2) * 5 ) 7 +
                -> ((((100 + 200) / 2) * 5) + 7) 
                -> ((((100 + 200) / 2) * 5) + 7)     => (150 * 5) + 7 => 750 + 7 => 757


// NOTE: 
    Operands: are numbers like 1, 12, 4 4,
    Operators: +, -, *, /

// Observations: 
    * Postfix means we need to perform operation on operands with given postfix operators..
    * In postfix operators are given after the operands, so we need to take it & move it to front to the give number & perform the arithmetic operations..

// Intrusion: 
    * We will iterate throughout string.
        * if we encounter any operands during traversal, we will insert into the stack
        * else: if we encounter any operator
            * pop tow element from the stack that we have stored recently..
            * perform that operator operations with them.
        * Once we have perform the operations, we will have to store the result into stack, so that next time we will compute the operations with this result..


*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s){
        stack<int> stk;     // initialising stack

        for(int i=0;i<s.size();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                stk.push(s[i] - '0');   // inserting operands into stack, & we are converting string to number
            }
            else{
                // get the two recently pushed values from stack.
                int top1 = stk.top();   // first element of stack that recently pushed
                stk.pop();  // pop, so that we can get second element.
                int top2 = stk.top();
                stk.pop();

                char ch  = s[i];    // operator that we have to perform:
                // compare the operator & perform that arithmetic operations & store it into the stack.
                switch (ch){
                case '+':
                    stk.push(top1 + top2);  // once the operations is done, we will insert into stack, so that we can perform next operations with this stored value...
                    break;  // break out will break out from switch not loop.
                case '-':
                    stk.push(top2 - top1);
                    break;
                case '*':
                    stk.push(top2 * top1);
                    break;
                case '/':
                    stk.push(top2 / top1);
                    break;
                }
            }
        }   // end of for loop

        return stk.top();   // at last we have only one value in stack that is our result, so we return that...
    }
};


int main(){
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string S;
        cin>>S;
        Solution obj;
        
        cout<<obj.evaluatePostfix(S)<<endl;
    }

    return 0;
}