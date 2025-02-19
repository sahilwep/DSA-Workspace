/*

//  1415. The k-th Lexicographical String of All Happy Strings of Length n


//  Problem Statement: 
    -> A happy string is a string that:
        -> consists only of letters of the set ['a', 'b', 'c'].
        -> s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
    -> For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
    -> Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
    -> Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


// Example:
    Example 1:
        Input: n = 1, k = 3
        Output: "c"
        Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

    Example 2:
        Input: n = 1, k = 4
        Output: ""
        Explanation: There are only 3 happy strings of length 1.

    Example 3:
        Input: n = 3, k = 9
        Output: "cab"
        Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"


// Observations:
    -> We are given integer 'n' and integer K. We have to generate sequence of with alphabet 'a', 'b', 'c' only of size in in lexigraphically order.
    -> We have to return kth sequence from that list.

    -> When we have to generate all possible sequence, we will use backtracking
        -> NOTE: we have to follow the given conditions: s[i] != s[i+1]
    
    -> Backtracking: process it until we have explored all possible cases.
        -> Try:
        -> Explore
        -> Revert back


// Complexity: 
    -> TC: O(n * 2^n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    void sequence(int n, string &curr, vector<string> &ans) {
        if(curr.size() == n) {  // if we generate 'n' size string, push it into our answer list & return for next possible string generations.
            ans.push_back(curr);
            return;
        }

        // We are given 3 characters which we have to use to generate string.
        for(auto ch: {'a', 'b', 'c'}) {
            if(!curr.empty() && curr.back() == ch) {    // condition: s[i] != s[i+1]
                continue;
            }

            // backtracking:

            curr.push_back(ch); // try:
            
            sequence(n, curr, ans); // explore
            
            curr.pop_back();    // revert
        }

    }
public:
    string getHappyString(int n, int k) {

        vector<string> ans; 

        string curr;
        sequence(n, curr, ans);

        if(k > ans.size()) return "";
        return ans[k-1];    // return k-1, because of 1 based index..
    }
};