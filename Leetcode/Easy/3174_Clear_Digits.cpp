/*

//  3174. Clear Digits


//  Problem Statement: 
    -> You are given a string s.
    -> Your task is to remove all digits by doing this operation repeatedly:
        -> Delete the first digit and the closest non-digit character to its left.
    -> Return the resulting string after removing all digits.


// Example:
    Example 1:
        Input: s = "abc"
        Output: "abc"
        Explanation: There is no digit in the string.

    Example 2:
        Input: s = "cb34"
        Output: ""
        Explanation: First, we apply the operation on s[2], and s becomes "c4". Then we apply the operation on s[1], and s becomes "".


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string res = "";

        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                // look back from here & delete that character:
                string temp = "";
                bool flag = true;
                for(int j = res.size() - 1; j >= 0; j--) {
                    if(flag && res[j] >= 'a' && res[j] <= 'z') {
                        flag = false;
                        continue;
                    }
                    temp += res[j];
                }
                reverse(begin(temp), end(temp));
                res = temp;
                continue;
            }
            res += s[i];
        }

        return res;
    }
};