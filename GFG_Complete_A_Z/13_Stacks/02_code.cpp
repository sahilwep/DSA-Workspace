/*
// Array implementation of stack : 


*/

#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    int *arr;
    int top;
    int cap;
    MyStack(int c){
        cap = c;
        top = -1;
        arr = new int[c];
    }
    void push(int x){
        if(isFull()) return;
        top++;
        arr[top] = x;
    }
    int pop(){
        if(isEmpty()) return INT_MAX;
        int res = arr[top];
        top--;
        return res;
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return (top == cap-1);
    }
    int size(){
        return top;
    }
    int peek(){
        return arr[top];
    }
    void display(){
        for(int i=0;i<cap;i++) cout << arr[i] << " ";
    }
};

int main(void){
    
    MyStack s(5);
    s.push(10);
    s.push(130);
    s.push(110);
    s.push(10);
    s.push(20);

    s.display();


    return 0;
}