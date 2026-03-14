/*

//  Count Digits

//  Problem Statement: 
    - Given a natural number n. You have to find the number of digits in it and return it.


// Examples:
    Input: n = 12
    Output: 2
    Explanation: 12 has 2 digits

    Input: n = 456
    Output: 3
    Explanation: 456 has 3 digits


    // Normal Way: 
        - Count the number of digits by simply dividing it by 10 until it's not get to '0'.


    // Efficient way:
        
        - TotalDigit = log10(n) + 1         => log10 will count decimal 
        
        - TotalDigit = log2(n) + 1          => For any number it will count the binary digits in that number



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Way:
class Solution {
  public:
    int countDigits(int n) {
        return log10(n) + 1;
        
    }
};


// Normal Way:
class Solution {
  public:
    int countDigits(int n) {
        
        int cnt = 0;
        while(n > 0) {
            n /= 10;
            cnt++;
        }
        
        return cnt;
    }
};