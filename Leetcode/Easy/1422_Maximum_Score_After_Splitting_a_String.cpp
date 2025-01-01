/*

//  1422. Maximum Score After Splitting a String

//  Problem Statement:
    -> Given a binary string, return the max score after spliting the string into two non-empty "substring" i.e (left substring & right substring)
    -> The score after spliting a string is the number of zeros in the left substring plus the number of ones in the right substring.


// Example:

    // Example:
            Input: s = "011101"
            Output: 5 
            Explanation: 
            All possible ways of splitting s into two non-empty substrings are:
            left = "0" and right = "11101", score = 1 + 4 = 5 
            left = "01" and right = "1101", score = 1 + 3 = 4 
            left = "011" and right = "101", score = 1 + 2 = 3 
            left = "0111" and right = "01", score = 1 + 1 = 2 
            left = "01110" and right = "1", score = 2 + 1 = 3


// Approach:
    -> We need left & right side values & we have to apply k partitions on every possible index from 1 to n-2



// BruteForce Solution: 
    -> We can count left side 0's & right side 1's in every traversal.
    -> TC: O(n^2)


// Efficient Solutions:
    -> First Count number of 1's
    -> Then iterate and count number of 0's & subtract 1's depending on the values we get.
    -> Store maximum possibilities.
    -> TC: O(n)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: TC: O(n)
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ans = 0;

        // count number of 1's & 0's:
        int zCnt = 0, oCnt = 0;
        bool isAllOne = true;
        for(auto i: s){
            if(i == '1') oCnt++;
            else isAllOne = false;
        }
        if(isAllOne) return oCnt - 1;   // case when we have all ones.

        // Now iterate & subtract 1's cnt:
        for(int i=0;i<n-1;i++){
            if(s[i] == '0') zCnt++;
            if(s[i] == '1') oCnt--;

            // store the max Result:
            ans = max(ans, (zCnt + oCnt));
        }

        return ans;
    }
};


// BruteForce Solution: TC: O(n^2)
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            // Count 0's
            int zCnt = 0;
            for(int j=0; (j <= i) && (j < n-1);j++){    // one extra condition we need to add (j < n-1), because we need to split it into two substring.
                if(s[j] == '0') zCnt++;
            }

            // Count 1's
            int oCnt = 0;
            for(int j=i+1;j<=n-1;j++){
                if(s[j] == '1') oCnt++;
            }

            // Last get the maximum answer:
            ans = max(ans, (zCnt + oCnt));
        }

        return ans;
    }
};