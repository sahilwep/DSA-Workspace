/*

//  386. Lexicographical Numbers


//  Problem Statement: 
    -> Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
    -> You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 
// Example: 
    Example 1:
        Input: n = 13
        Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

    Example 2:
        Input: n = 2
        Output: [1,2]

// Solution: 
    -> for lexigraphically sorted, first convert int to string & then generate all the numbers, & while storing answer, convert from string to int.

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N)

    // Optimal Solution: 
        -> 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {

        set<string> st;
        for(int i = 1; i <= n; i++) {
            st.insert(to_string(i));
        }

        vector<int> ans;
        for(auto&it: st) {
            ans.push_back(stoi(it));
        }

        return ans;
    }
};