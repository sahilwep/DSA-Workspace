/*
// All divisors of a numbers.

// Example : 
    I/p : n = 15 
    O/p : 1, 3, 5, 15

    I/p : n = 100
    O/p : 1, 2, 4, 5, 10, 20, 25, 50, 100

    I/p : n = 7
    O/p : 1, 7

// Bruteforce Solution : 
    * iterate from 1 to n & check for each number that is able to divide or not..


// Better Solution : 
    * Divisors of a number will always appear in pairs.
        30 : (1, 30), (2, 15), (3, 10), (5, 6)
             (i, (n/i)), (i, (n/i))..
        we are printing i & (n/i)

    * One of the divisor in every pair is smaller an or equal sqrt(n).
        for a pair (x, y)
            x * y = n
        Let x be the smaller, i.e x <= y
            x * x <= n
            x <= sqrt(n)
    * example :
        n = 25
            i = 1   print(1)
                    print(25)
            i = 2
            i = 3
            i = 4
            i = 5  print(5)
    * Approach : 
        * here we can iterate from i=1 to sqrt(n)
        * we will print the pairs (i, (n/i))
        * if (i = n/i) we will ignore that case for perfect square.

    NOTE : we can have our all the divisor but these are not in sorted order.


// Efficient Solution : 
    * we will use same approach, but to print in sorted order :
        * print all the divisor from 1(inclusive) to sqrt(n)(exclusive).
        * print all the divisor from sqrt(n)(inclusive) to 1(inclusive).
    
    * In layman language : we will iterate from 1 to sqrt(n) & print all the divisor(i),
    * then again we print from sqrt(n) to 1 & print all the divisor(n/i).
    
    * Example : 
        n = 15
            * 1st loop : 
                i = 1; print(1) : (i)
                i = 2;
                i = 3; print(3) : (i)
            * 2ns loop : 
                i = 4;
                i = 3; print(5) : (n/i)
                i = 3;
                i = 1; print(15) : (n/i)

    * TC : sqrt(n)

*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce Solution : TC : O(n)
void getDivisor(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0) cout << i << " ";
    }
}

// Better Solution :  TC : O(sqrt(n))
void getDivisor_1(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout << i << " ";
            if(i != n/i){   // this condition is to eliminate the condition for perfect square like : 25, we can have pair(5, 5), so to eliminate 5 for two times we use this condition.
                cout << n/i << " ";
            }
        }
    }
}

// Efficient Solution : TC : O(Sqrt(n))
void getDivisor_2(int n){
    int i;
    for(i=1;i*i<n;i++){
        if(n%i == 0){
            cout << i << " ";
        }
    }
    for(;i>=1;i--){
        if(n%i==0){
            cout << n/i << " ";
        }
    }
}

int main(void){
    int n;
    cin >> n;
    getDivisor_2(n);

    return 0;
}