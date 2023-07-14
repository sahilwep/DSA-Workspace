/*
    Multiple Recursion Calls : 

    fibonacci Series :  0 1 1 2 3 5 8 13 21...

    so Suppose we need to print the nth fibonacci no, So

    suppose n = 4, then
    fibonacci Series :  0 1 1 2 3 5 8 13 21...
                n    :  0 1 2 3 4 5 6 7 8  9...

    so n = 4, then, nth no is : (n-1 + n-2), because
                    suppose n = 4, then (n=3 + n=2) = (n=4)
                                          2   +  1  =   3
    logic like :                    
            f(n)
            when (n<=1) return n  // this will be our base case, because we have to find the nth fibonacci number, so we will go from n to 1. and add those numbers.
                     last = f(n-1)  // first recursion, will give us value of n-1, i.e 2, for n = 4
              second_last = f(n-2)  // second recursion, will give us valueof n-2, i.e 1, for n = 4 
    
            return (last + second_last)

    Recursion Tree :    
                    f(n)    //function
                        f(n-1)  // first recursion. 
                        f(n-2)  // second recursion.

                Tree : 

                    f(4)
            f(3)           f(2)
        f(2)    f(1)    f(1)    f(0)
    f(1)    f(0)  

        Time Complexity : O(2^n), exponentially
        Space Complexity : O(2^n)
        because, at every time it goes for 2 recursion, so, 2x2x2x2...n So, 2^n
*/

#include <iostream>
using namespace std;

int f(int n){
    if(n <= 1) return n;    // Base case.
    int last = f(n-1);  // fist recursion call, return n-1, i.e 2, for n=4
    int sLast = f(n-2); // second recursion call, return n-2, i.e 1, for n=4
    return last + sLast;
}

int main(void){

    int n = 4;  // we need the 4th fib no.
    cout << "Value is : " << f(4);

    return 0;
}