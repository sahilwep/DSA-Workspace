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


// Observations:
    - we are given nums that contains n unique binary string of each length 'n'
    - return the binary string of length 'n' that does not appears in the nums.
    - if there are multiple answer, return any.


    // Approach:
        - first put all the binary string into the unordered_set so that we can have O(1) query time
        - Then, generate all the possible binary string with size 'n' with 0 & 1
        - and once we are done with that, query and return the missing one..

    // Complexity:
        - TC: O(2^n * n)
        - SC: O(2^n * n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n;
    unordered_set<string> st;
    void generate(int pos, string& s) {
        if(pos == n) {
            st.insert(s);
            return;
        }

        // Two choice: either '0' or either '1'

        s.push_back('0');
        generate(pos + 1, s);
        s.pop_back();


        s.push_back('1');
        generate(pos + 1, s);
        s.pop_back();
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].size();

        // generate all the possible string:
        string s = "";
        generate(0, s);     // TC: O(2^n * n)


        // Now filter out the generated string..
        for(auto &s: nums) {    // O(n)
            if(st.count(s)) {
                st.erase(s);
            }
        }

        if(!st.empty()) return *st.begin(); // if we have something left, return any

        return "";  // else return emtpy string
    }
};