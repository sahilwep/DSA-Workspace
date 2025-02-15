/*

//  2698. Find the Punishment Number of an Integer


//  Problem Statement: 
    -> Given a positive integer n, return the punishment number of n.
    -> The punishment number of n is defined as the sum of the squares of all integers i such that:
        -> (1 <= i <= n)
        -> The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.

 
// Example:
    Example 1:
        Input: n = 10
        Output: 182
        Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
        - 1 since 1 * 1 = 1
        - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
        - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
        Hence, the punishment number of 10 is 1 + 81 + 100 = 182

    Example 2:
        Input: n = 37
        Output: 1478
        Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
        - 1 since 1 * 1 = 1. 
        - 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
        - 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
        - 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
        Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Memoization Solution: TC: O(n^2 * logn), SC: O(n * logn)
class Solution {
private:
    bool check(int i, int currSum, string s, int num, vector<vector<int>> &t) {
        if(i == s.size()) {
            return currSum == num;
        }

        if(currSum > num) {
            return false;
        }

        // Check in memo table:
        if(t[i][currSum] != -1) return t[i][currSum];


        bool possible = false;
        for(int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);    // substring will be of lenfth i to j
            int val = stoi(sub);

            possible = possible || check(j + 1, currSum + val, s, num, t);

            if(possible) return possible;
        }

        return t[i][currSum] = possible;
    }
public:
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1; num <= n; num++) {
            int sq = num * num;

            string s = to_string(sq);
            vector<vector<int>> t(s.size(), vector<int> (num + 1, -1));

            if(check(0, 0, s, num, t)) {
                punish += sq;
            }
        }

        return punish;
    }
};

// Recursive Solution: TC: O(n⋅2^(logn)), SC: O(logn)
class Solution {
private:
    bool check(int i, int currSum, string s, int num) {
        if(i == s.size()) {
            return currSum == num;
        }

        if(currSum > num) {
            return false;
        }
        bool possible = false;
        for(int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);    // substring will be of lenfth i to j
            int val = stoi(sub);

            possible = possible || check(j + 1, currSum + val, s, num);

            if(possible) return possible;
        }

        return possible;
    }
public:
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1; num <= n; num++) {
            int sq = num * num;

            string s = to_string(sq);
            if(check(0, 0, s, num)) {
                punish += sq;
            }
        }

        return punish;
    }
};