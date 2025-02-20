/*

//  1980. Find Unique Binary String


//  Problem Statement: 
    -> Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
 

// Example: 
    Example 1:

        Input: nums = ["01","10"]
        Output: "11"
        Explanation: "11" does not appear in nums. "00" would also be correct.

    Example 2:

        Input: nums = ["00","01"]
        Output: "11"
        Explanation: "11" does not appear in nums. "10" would also be correct.

    Example 3:

        Input: nums = ["111","011","001"]
        Output: "101"
        Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(auto &num: nums) {
            st.insert(stoi(num, 0, 2));
        }

        string res = "";
        for(int i = 0; i <= n; i++) {
            if(st.find(i) == st.end()) {
                res = bitset<16>(i).to_string();

                return res.substr(16 - n, n);
            }
        }

        return "";
    }
};