/*

//  2523. Closest Prime Numbers in Range


//  Problem Statement: 
    -> Given two positive integers left and right, find the two integers num1 and num2 such that:
        -> left <= num1 < num2 <= right .
        -> Both num1 and num2 are Prime Number.
        -> num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
    -> Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, 
    -> return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 
// Example:

    Example 1:

        Input: left = 10, right = 19
        Output: [11,13]
        Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
        The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
        Since 11 is smaller than 17, we return the first pair.

    Example 2:

        Input: left = 4, right = 6
        Output: [-1,-1]
        Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.


// Observations: 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    bool isPrime(int n) {
        if(n <= 1) return 0;
        if(n == 2 || n == 3) return 1;
        if(n % 2 == 0 || n % 3 == 0) return 0;
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return 0;
        }
        return 1;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        if(left == right) return {-1, -1};  // if we have same number {prime / non-prime} return "-1"

        vector<int> pPrime;
        for(int i = left; i <= right; i++) {
            if(isPrime(i)) pPrime.push_back(i);
        }


        // Now Check minimum pairs:
        pair<int, int> res = {-1, -1};
        int minAns = INT_MAX;

        int n = pPrime.size();
        for(int i = 0; i < n - 1; i++) {
            cout << pPrime[i] << " ";
            int num1 = pPrime[i];
            int num2 = pPrime[i + 1];
            if(num1 < num2) {
                if(num2 - num1 < minAns) {
                    minAns = num2 - num1;
                    res.first = num1;
                    res.second = num2;
                }
            }
        }

        return {res.first, res.second};
    }
};