/*
// Array implementation of stack


// We have Primarily push(), pop(), peek(), & size() functions in stack..
    * We will create an array at runtime, using new keyword..
    * we will maintain top pointer that will point the top element of stack

*/

#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    int *arr;   // create an array at runtime
    int top;    // top will point the top of the value from stack.
    int cap;    // this is the size of stack
    // using constructor we have create an array of size c
    MyStack(int c){
        cap = c;    // staring capacity of stack
        top = -1;   // initially stack is empty so it's point to index -1
        arr = new int[c];   // creating an array at runtime of size c
    }
    void push(int x){
        if(isFull()) return;    // if stack is full it will not push element into stack
        top++;
        arr[top] = x;
    }
    int pop(){
        if(isEmpty()) return INT_MAX;   // if stack is empty it will not perform pop() operations
        int res = arr[top];
        top--;
        return res;
    }
    bool isEmpty(){
        return (top == -1); // if top points -1, means there is no such element in stack..
    }
    bool isFull(){
        return (top == cap-1);  // if top points to the last index means (cap-1) it will return true
    }
    int size(){
        return (top + 1); // return the size of stack.
    }
    int peek(){
        return arr[top];    // return the top element
    }
};

int main(void){
    
    MyStack s(5);
    s.push(10);
    s.push(130);
    s.push(110);
    s.push(10);
    s.push(20);

    cout << "Size: " <<  s.size() << endl;
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Size: " <<  s.size() << endl;
    cout << "Top: " << s.peek() << endl;


    return 0;
}