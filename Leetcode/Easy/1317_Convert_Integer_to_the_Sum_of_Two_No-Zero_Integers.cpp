/*

//  1317. Convert Integer to the Sum of Two No-Zero Integers


//  Problem Statement: 
    -> No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
    -> Given an integer n, return a list of two integers [a, b] where:
        -> a and b are No-Zero integers.
        -> a + b = n
    -> The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.


//  Example:
    Example 1:
        Input: n = 2
        Output: [1,1]
        Explanation: Let a = 1 and b = 1.
        Both a and b are no-zero integers, and a + b = 2 = n.

    Example 2:
        Input: n = 11
        Output: [2,9]
        Explanation: Let a = 2 and b = 9.
        Both a and b are no-zero integers, and a + b = 11 = n.
        Note that there are other valid answers as [8, 3] that can be accepted.

// Observations:

    n = 11
        
        1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 

        We can divide 11 one by 1
        We will have to side left & right
        Summing up left & ring will make whole number
        
            1 1 1 1 | 1 1 1 1 1 1 1
                4   +   7          => 10

        Let's Consider as left & right
        NOTE: left & right number should not contains any '0'
        We will start from n - 1 = 10 & iterate till 1st position
        Anywhere in b/w if we are able to find such two side left & right which are not divisible by 10 -> Our answer...

            iterate: (i => n-1 to 1)
                check: (n % i != 0 && i % 10 != 0) => Our answer.


    // Complexity:
        -> TC: O(n)
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    bool isZero(string& s) {
        for(auto&it: s) if(it == '0') return false;
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        if(n == 2) return {1, 1};

        // Find the sequence pair, which not divisible by 5 or 10, because those numbers will have '0'
        for(int i = n-1; i >= n/2; i--) {
            int left = i;
            int right = n % i;

            // Quick Check for 0's:
            cout << left << " " << right << endl;
            string temp = to_string(left) + to_string(right);
            if(isZero(temp)) return {left, right};
        }
        return {};
    }
};

