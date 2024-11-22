/*

//  6. Zigzag Conversion


// Approach:
        Input: s = "PAYPALISHIRING", numRows = 4
        Output: "PINALSIGYAHRPI"
        Explanation:
            P     I    N
            A   L S  I G
            Y A   H R
            P     I

    -> Observation:
        -> If we can create numRows size string vector & generate every row one by one, by iterating in string, we can generate this zig-zag pattern.


    -> We have to generate result in given pattern:
        -> Create numRow size string vector:
        -> We can iterate in string:
            -> While ideating, either we can go upward or downward..
            -> we can use flag that make sure to move upward or downward, whenever i is at 'corner'(upward corner or downward corner)
            -> Based on the flag direction we can increment or decrement 'i' pointer, to store next character of string, in that ith string in vector

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    string convert(string s, int n) {
        
        if(n == 1) return s;    // If there's only one row, the zigzag pattern is the string itself

        vector<string> pat(n);  // Create a vector of strings to represent rows in the zigzag pattern

        int i = 0;  // this is used to access the correct number of string from 'pat' vector to store the correct string character.
        bool flag = 1;  // 1 = going down, 0 = going up
        
        int k = 0;  // used to iterate in string
        while(k < s.size()){    // Iterate in string:
            // first store the character, in pattern[ith] string value.
            pat[i] += s[k];
            k++;    // increment 'k' pointer that is used to iterate in string.

            // based on 'i' corner values, we can decide whether we want to go downward or go upward, by chaning the flag.
            if(i == n-1) flag = 0;  // if we are on downward corner, we need to change flag so that next time we can go upward. 
            else if(i == 0) flag = 1;   // if we are at upward corner, we need to change flag so that next time we can go downward.


            // Now based on flag value, we can move 'i', whether to go upward or downward.
            if(flag == 1){  // means go downwards, increment 'i'
                i++;
            }else{          // means go upward, decrement 'i'
                i--;
            }
        }


        // last store result, by taking every string character one-by-one from every row.
        string res = "";
        for(int i=0;i<pat.size();i++){
            for(int j=0;j<pat[i].size();j++){
                res += pat[i][j];
            }
        }

        return res;
    }
};