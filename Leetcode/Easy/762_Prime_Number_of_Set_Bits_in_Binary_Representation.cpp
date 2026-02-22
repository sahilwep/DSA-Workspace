/*

//  762. Prime Number of Set Bits in Binary Representation


//  Problem Statement: 
    - Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
    - Recall that the number of set bits an integer has is the number of 1's present when written in binary.
        - For example, 21 written in binary is 10101, which has 3 set bits.

 
// Example:
    Example 1:
        Input: left = 6, right = 10
        Output: 4
        Explanation:
        6  -> 110 (2 set bits, 2 is prime)
        7  -> 111 (3 set bits, 3 is prime)
        8  -> 1000 (1 set bit, 1 is not prime)
        9  -> 1001 (2 set bits, 2 is prime)
        10 -> 1010 (2 set bits, 2 is prime)
        4 numbers have a prime number of set bits.

    Example 2:
        Input: left = 10, right = 15
        Output: 5
        Explanation:
        10 -> 1010 (2 set bits, 2 is prime)
        11 -> 1011 (3 set bits, 3 is prime)
        12 -> 1100 (2 set bits, 2 is prime)
        13 -> 1101 (3 set bits, 3 is prime)
        14 -> 1110 (3 set bits, 3 is prime)
        15 -> 1111 (4 set bits, 4 is not prime)
        5 numbers have a prime number of set bits.


//  Observations:
    - Given left & right, we need to find all the number whose set-bits are prime
    
    // Approach:
        - First we will get every number & find the count of set bits
        - then we can check wether they are prime or not?
        - If we observe carefully about prime numbers:
            
                2, 3, 5, 7, 11, 13, 17, 19, 31..
            
            We only need till 19, because if we have all 31 set-bits then that number is very large
            and our constrains not go beyond 1e6
        
        // Complexity:
            - TC: O(right - left)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int countBits(int n) {  // TC: O(1) as it travels only 32 iterations.

        int cnt = 0;
        for(int i = 1; i <= 32; i++) {
            int bit = n & 1;    // get the last set bits
            cnt += bit;
            n >>= 1;
        }

        return cnt;
    }
    bool isPrime(int n) {   // O(1)
        vector<int> bits = {2, 3, 5, 7, 11, 13, 17, 19};    // these are the number of bits in every prime in possible range.
        for(auto &it: bits) if(it == n) return true;
        return false;
    }
public:
    int countPrimeSetBits(int left, int right) {
        
        int cnt = 0;
        for(int i = left; i <= right; i++) {    // O(K)     => k = right - left
            int bits = countBits(i);            // O(1)
            
            cnt += (isPrime(bits)) ? 1 : 0;
        }

        return cnt;
    }
};