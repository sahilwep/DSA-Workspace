/*

//  Check Prime:


//  Problem Statement: 
    - Given a number n, determine whether it is a prime number or not.
    - Note: A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.


// Examples :
    Input: n = 7
    Output: true
    Explanation: 7 has exactly two divisors: 1 and 7, making it a prime number.

    Input: n = 25
    Output: false
    Explanation: 25 has more than two divisors: 1, 5, and 25, so it is not a prime number.

    Input: n = 1
    Output: false
    Explanation: 1 has only one divisor (1 itself), which is not sufficient for it to be considered prime.

    // Observations:
        - For checking Prime number property for any number, we only need to iterate till the sqrt() of that number..

*/

#include <bits/stdc++.h>
using namespace std;

// Efficient Way:
class Solution {
  public:
    bool isPrime(int n) {
        if(n == 1) return 0;
        if(n == 2 || n == 3) return 1;
        if(n % 2 == 0 || n % 3 == 0) return 0;
        for(int i=5;i*i<=n;i+=6){
            if(n % i == 0 || n % (i+2) == 0){
                return 0;
            }
        }
        
        return 1;
    }
};

// Normal Way:
class Solution {
  public:
    bool isPrime(int n) {
        
        if(n == 1) return false;    // 1 is not prime number as it has only single divisor
        
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }

        return true;
    }
};