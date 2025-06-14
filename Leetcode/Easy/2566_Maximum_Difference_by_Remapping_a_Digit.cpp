/*

//  2566. Maximum Difference by Remapping a Digit


//  Problem Statement: 
    -> You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
    -> Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

    // Notes:
        -> When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
        -> Bob can remap a digit to itself, in which case num does not change.
        -> Bob can remap different digits for obtaining minimum and maximum values respectively.
        -> The resulting number after remapping can contain leading zeroes.

 
// Example: 

    Example 1:
        Input: num = 11891
        Output: 99009
        Explanation: 
        To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
        To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
        The difference between these two numbers is 99009.

    Example 2:
        Input: num = 90
        Output: 99
        Explanation:
        The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
        Thus, we return 99.

// Observations: 
    -> For maximum, get the first digit which is not equal to '9'
    -> For minimum, get the first digit which is not equal to '0'
    -> change digits & return answer.

    // Complexity: 
        -> TC: O(log10(N) + 1)
            -> N = number
        -> TC: O(n) => n = number_digits.size()
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int maxStr(string &s) { // return maximum string
        int n = s.size();

        // Find changeable digit
        char digit;
        for(int i = 0; i < n; i++) {
            if(s[i] != '9') {
                digit = s[i];
                break;
            }
        }
        // Update s[i] with the digit:
        string maxStr = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == digit) maxStr += '9';
            else maxStr += s[i];
        }

        return stoi(maxStr);
    }
    int minStr(string &s) { // return minium string
        int n = s.size();

        // Find Changeable digit:
        char digit;
        for(int i = 0; i < n; i++) {
            if(s[i] != '0') {   // get the first non-zero digit
                digit = s[i];
                break;
            }
        }

        // update s[i] with that digit
        string minStr = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == digit) {
                minStr += '0';
            } else {
                minStr += s[i];
            }
        }

        return stoi(minStr);
    }
public:
    int minMaxDifference(int num) {

        string s = to_string(num);

        int max = maxStr(s);
        int min = minStr(s);

        return max - min;
    }
};
