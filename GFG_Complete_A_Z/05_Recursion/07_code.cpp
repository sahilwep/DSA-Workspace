/*
// Writing base case in Recursion:
    * Whenever we get some problem & we come up with subpart of solution, 
    * but writing wrong base case will leads recursive call to stackOverFlow.
        * So, we have to carefully choose the base case of recursive calls...


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// factorial of number:
int factorial(int n){
    // if(n == 1) return 1;    // wrong base case, because for n = 0, segmentation fault..
    // if(n == 0) return 1;    // right base case, or
    if(n == 1 || n == 0) return 1;      // right base case
    return n * factorial(n-1);
}


// nth fibonacci number:
int fib(int n){
    // base case: 
    // if(n == 0) return 0;
    // if(n == 1) return 1; 
    if(n <= 1) return n;    // equivalent to upper statements..
    return fib(n-1) + fib(n-2);
}

int main(void){
    
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    cout << fib(n) << endl;
    
    
    return 0;
}