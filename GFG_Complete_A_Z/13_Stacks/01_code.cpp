/*

// Stack Data Structure:

    * Stack is a liner data structure that follow last in first out.
    * It has box like structure that has only one end for insertion & removal of any item.
    * Insertion operations is known as: push()
    * Deletion operations is known as: pop()
    * There are several others function in stack: 
        * peek() = tells us the top element of stack
        * size() = return the size of stack
        * isEmpty() = return if the stack is empty or not..

// OverFlow & UnderFlow
    * Overflow is a condition when the stack is full & we are trying to insert an element into stack.
    * Underflow  is a condition when the stack is empty & we are trying to remove an element from the stack.

// Let's see the STL implementation of stack..
    * In STL we have predefined stack..
        * Function are like:
            push()
            pop()
            top()
            empty()
            size()
            ...


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(void){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " <<  s.top() << " & size: " << s.size() <<  endl;
    s.pop();
    cout << "Top: " << s.top() << " & size: " << s.size() <<  endl;
    s.pop();
    cout << "Top: " << s.top() << " & size: " << s.size() <<  endl;
    s.pop();

    (s.empty()) ? cout << "Stack Empty" : cout << "Stack Not Empty";
    cout << endl;

    return 0;
}