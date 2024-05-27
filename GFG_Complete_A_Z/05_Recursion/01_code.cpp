/*
// Recursion Introduction: 
    * Recursion is a way to solve a problem or way to write function which call itself.

void func(){
    .....
    .....
    .....
    func();
    .....
    .....
    .....
}

// function call stack: 
    main()
      |----> function()
                |----> function()
                         |----> function()
                                    ....
                                    ....

* It's call itself until the base case is not hit..
* Recursion can be direct or indirect: 
    // Direct 
        fun1(){
            ...
            fun1();
            ...
        }

    // Indirect 
        fun1(){
            ...
            fun2();
            ...
        }
        fun2(){
            ...
            fun1();
            ...
        }

* Note If function calls itself again & again, it's get segmentation fault after a time when memory is full..
* We use Base case to prevent function stuck in loop of calling itself...
* In recursion we have two things: 
    * Base case: when function exit from falling into recursive case.
    * Recursive case: when function calls itself...


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void func(int x){
    // Base case: 
    if(x == 0){
        return;
    }
    cout << x << " ";
    // Recursive Case: 
    func(x-1);
}


int main(void){
    
    func(10);

    return 0;
}