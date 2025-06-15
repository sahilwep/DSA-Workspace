/*

//  1432. Max Difference You Can Get From Changing an Integer


//  Problem Statement: 
    -> You are given an integer num. You will apply the following steps to num two separate times:
        -> Pick a digit x (0 <= x <= 9).
        -> Pick another digit y (0 <= y <= 9). Note y can be equal to x.
        -> Replace all the occurrences of x in the decimal representation of num by y.
    -> Let a and b be the two results from applying the operation to num independently.
    -> Return the max difference between a and b.
    -> Note that neither a nor b may have any leading zeros, and must not be 0.

 
// Example: 
    Example 1:
        Input: num = 555
        Output: 888
        Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
        The second time pick x = 5 and y = 1 and store the new integer in b.
        We have now a = 999 and b = 111 and max difference = 888

    Example 2:
        Input: num = 9
        Output: 8
        Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
        The second time pick x = 9 and y = 1 and store the new integer in b.
        We have now a = 9 and b = 1 and max difference = 8

// Observations: 

// Observations: 
    -> from the given nums
    -> we can apply following operations on num two separate times.
        -> we can pick any digit x (0 <= x <= 9)
        -> we can pick another digit y (0 <= y <= 9)
        -> replace all the occurrences of 'x' in the decimal representation of num by 'y'
    -> Let a & b the two result from applying the operations to num independently.
    -> return the maximum difference b/w a & b

    // Approach: 
        -> For 'a': 
            -> pick a starting digit for which we can make maximum value:
                -> For maximum find the first digit != 9
                -> replace all occurrence of that digit with '9'

        -> For 'b': 
            -> pick a starting digit for which we can make minimum value:
                -> find the first dight != (0 & 1)
                    -> '0', because that's the minimum
                    -> '1', because if '1' is found at first digit place, we make leading '0', which is contradicting the given conditions.
                        -> even if we found '1' at some 2nd or 3rd or any forward places, it's better we should ignore that, because the digit before '1' will make overall value lesser.
                
                -> Now check if the found digit is at s[0] at first place, then we can't place '0' on front, then we have to place '1'
                    -> We need to have some short of checking mechanism..
                -> If s[0] != digit we have found, then place '0' at all the place

        -> Last find a - b

        
    // Complexity: 
        -> TC: O(log10(num) + 1), which is the digit count of num
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int n;
    int maxStr(string s) {
        
        // Get the first changeable digit which is not equal to '9'
        char ch;
        for(int i = 0; i < n; i++) {
            if(s[i] != '9') {
                ch = s[i];
                break;
            }
        }
        
        // Update s[i] with the digit:
        string res = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == ch) res += '9';
            else res += s[i];
        }

        cout << res << " ";
        return stoi(res);
    }
    int minStr(string s) {

        // Get the first changeable digit: 
        char ch;
        for(int i = 0; i < n; i++) {
            if(s[i] != '0' && s[i] != '1') {
                ch = s[i];
                break;
            }
        }

        // Check wether the selected digit is the leading ones or not?
        bool flag = false;
        if(s[0] == ch) flag = true;

        // Update s[i] with the digit: 
        string res = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == ch) {
                if(flag == false) res += '0';   // if selected ones is not leading, we can place '0'
                else res += '1';    // else we have to place '1'
            } 
            else res += s[i];
        }

        cout << res << endl;
        return stoi(res);
    }
public:
    int maxDiff(int num) {
        
        string s = to_string(num);
        n = s.size();

        int ans = maxStr(s) - minStr(s);
        
        return ans;
    }
};