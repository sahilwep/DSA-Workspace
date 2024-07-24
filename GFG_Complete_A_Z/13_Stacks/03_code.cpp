/*
// Vector Implementation of stack:

// As we know that vector is dynamic in size, so it can change their size accordingly...
    * So Amortized Time complexity will be O(1) for insertion & deletion
    * Rest will be same...
    * we don't need to maintain any capacity or something, because vector has many inbuilt function that will help in these scenario.

// Amortized TC of every operation: O(1)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct MyStack{
    vector<int> v;
    void push(int x){
        v.push_back(x);
    }
    void pop(){
        // int res = v.back();
        v.pop_back();
        // return res;
    }
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.empty();
    }
    int peek(){
        return v.back();
    }
};

int main(void){

    MyStack s;
    s.push(10);
    s.push(20);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    
    return 0;
}