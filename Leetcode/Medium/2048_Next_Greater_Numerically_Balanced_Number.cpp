/*

//  2048. Next Greater Numerically Balanced Number


//  Problem Statement: 
    -> An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
    -> Given an integer n, return the smallest numerically balanced number strictly greater than n.

 
// Example: 
    Example 1:
        Input: n = 1
        Output: 22
        Explanation: 
        22 is numerically balanced since:
        - The digit 2 occurs 2 times. 
        It is also the smallest numerically balanced number strictly greater than 1.

    Example 2:
        Input: n = 1000
        Output: 1333
        Explanation: 
        1333 is numerically balanced since:
        - The digit 1 occurs 1 time.
        - The digit 3 occurs 3 times. 
        It is also the smallest numerically balanced number strictly greater than 1000.
        Note that 1022 cannot be the answer because 0 appeared more than 0 times.

    Example 3:
        Input: n = 3000
        Output: 3133
        Explanation: 
        3133 is numerically balanced since:
        - The digit 1 occurs 1 time.
        - The digit 3 occurs 3 times.
        It is also the smallest numerically balanced number strictly greater than 3000.



// Observations:
    - X is numerically balanced if for every digit 'd' in the number 'x', there are exactly d occurrence of of that digit in x.
    - Given 'n', return the smallest numerically balanced number strictly grater than n.

    // Example:
        n = 1
            next: 
                2
                3
                4
                5
                6
                7
                8
                9
                10
                11  -> two occurrence of '1' 
                12
                13
                ..
                ..
                21
                22  -> two occurrence of '2' -> "Answer"

         example:
            n = 1000
                1001
                ...
                ...
                1222    -> 1 occurrence of 1 & 3 occurrence of '2' wrong.
                ...
                ...
                1333    -> 1 occurrence of 1 & 3 occurrence of '3' "Answer"


        // BruteForce Approach:
            -> start from (n + 1) till "1e6", as per the constrains |OR| until we not find such number..
            -> for every number check their frequency..
                -> simple hash the number into 10 size array from 0 to 9
                -> hash every value current number by getting the digits (n % 10 to get the last num)
            -> If we are able to find such number which has exactly their number time frequency, return that number
            -> Else keep going & exploring...

    // Complexity: 
        -> TC: O(k)
        -> SC: O(1)
            range: (n < k <= 1e6)
            k = (1e6 - n) Aproxx...


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        int num = n + 1;

        while(num <= 1e6) {
            int currNum = num;

            // Hash & check wether this can be our answer?
            vector<int> hash(10, -1);
            while(currNum > 0) {
                int digit = currNum % 10;
                currNum /= 10;

                // Hash:
                if(hash[digit] == -1) { // for the first time:
                    hash[digit] = 1;
                } else {  // rest of the times..
                    hash[digit]++;      
                }
            }

            // For debugging:
            // for(auto &it: hash) cout << it << " ";
            // cout << endl;

            // Now check that number:
            bool isCapable = true;
            for(int i = 0; i < 10; i++) {
                if(hash[i] == -1) continue;
                if(hash[i] != i) {
                    isCapable = false;
                    break;
                }
            }

            if(isCapable) return num;

            // Else increase that number for next check:
            num++;
        }

        return 1224444; // first such number, after constrains ends.
    }
};