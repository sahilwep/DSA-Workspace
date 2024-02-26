/*
// Factorial of number : 


// Example : 
    I/p : 4
    O/p : 24

    I/p : 6
    O/p : 720

    I/p : 0
    O/p : 1

    n >= 0

// Observation : 
    * n! = 1*2*3*.....*(n-1)*n

    // Iterative Solution : 
        * iterate from 1 to n & multiply.
    
    // Recursive Solution : 
        * multiply x with (x-1) in recursive calls, until (x != 1).

*/

#include<bits/stdc++.h>
using namespace std;

// Iterative Solution : TC : O(n), AS : O(1)
int fact(int x){
    int res = 1;
    for(int i=1;i<=x;i++){
        res = res * i;
    }
    return res;
}

// Recursive Solution : TC : O(n), AS O(n)
int fact_Rec(int x){
    if(x == 1) return 1;
    return x * fact(x-1);
}

int main(void){

    int x;
    cin >> x;
    cout << fact(x) << endl;
    cout << fact_Rec(x) << endl;

    return 0;
}