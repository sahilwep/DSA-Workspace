/*

//  8. String to Integer (atoi)


//  Problem Statement: 
    -> Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
    -> The algorithm for myAtoi(string s) is as follows:
        -> Whitespace: Ignore any leading whitespace (" ").
        -> Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
        -> Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
        -> Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
    -> Return the integer as the final result.



// Approach: 
    -> Remove the whitespace from begin & back
    -> Check '+' '-' sign & make track of negative sign.
    -> build num-list & get track of out-of-bound values.
    -> return answer with -ve flag.


    // Complexity:
        -> TC: O(N)
        -> SC: O(1)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    string trim(string s) {

        int n = s.size();
        string res = "";
        int i = 0, j = n - 1;

        while(i < n && s[i] == ' ') i++;
        if(i == n) return "";

        while(j >= 0 && s[j] == ' ') j--;

        return s.substr(i, j - i + 1);
    }
public:
    int myAtoi(string s) {

        s = trim(s);    // trim the given string

        // Find negative or positive sign: 
        int i = 0;
        int n = s.size();
        bool neg = false;
        if(s[0] == '-') {
            i++;
            neg = true;
        } else if(s[0] == '+'){
            i++;
        }

        // Build answer:
        long long res = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            int num = s[i] - '0';

            res = res * 10 + num;

            // Check Out-of range value:
            if(!neg && res > INT_MAX) return INT_MAX;
            if(neg && -res < INT_MIN) return INT_MIN;

            i++;
        }

        if(neg) res *= -1; // check negative number.
        
        return res;
    }
};