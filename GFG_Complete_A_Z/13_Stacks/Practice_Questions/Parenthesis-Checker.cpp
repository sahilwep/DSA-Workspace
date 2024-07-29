/*
// Parenthesis Checker



// Observations: 
    * balanced parenthesis means for every open bracket we have closing once & it should be same, means:
    * Balanced:
        {}
        {()}
        [([({})])]
    * Not Balanced: 
        ([()]
        {[])
        [])

// Key Observations: 
    * The size of string will always even in number if it's balanced, as we have opening & closing bracket.

// Intrusion:
    * Idea is to store all the starting bracket into stack.
    * Now, fetch all the brackets from top of the stack, & start comparing with closing bracket..
    * If we have same closing bracket for every opening bracket we will remove that elements.. 
    * else if it's not matched, we return false..
    * Edge case: when number of starting starting brackets is not same as closing onces:
        * Example: [()]}
        * we have to return false explicitly for this conditions.
    * At last we will return stack.empty() if it's empty means all the parenthesis is balanced & so that they are removed from the stack..


*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        bool ispar(string x){
            int n = x.size();   // getting the size of string.
            stack<char> s;  // creating the stack

            // Iterate throughout the string.
            for(int i=0;i<n;i++){
                // storing all the opening bracket
                if(x[i] == '{' || x[i] == '[' || x[i] == '('){
                    s.push(x[i]);   // pushing into stack
                    continue;   // no need to check further, so continue this iterations.
                }
                // edge case: when we have number of closing bracket is > opening brackets
                if(s.empty()){
                    return false;
                }
                char top = s.top();     // fetching the top element of stack
                // comparing top element with closing element..
                if(top == '{' && x[i] == '}' || top == '[' && x[i] == ']' || top == '(' && x[i] == ')' ){
                    s.pop();    // removing if it's same as closing bracket..
                }
                // if it's not get matched we return false
                else{
                    return false;
                }
            }
            return s.empty();   // return 1 if we have all the character removed successfully from stack.
        }
};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}