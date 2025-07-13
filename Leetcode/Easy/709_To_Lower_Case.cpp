/*

//  709. To Lower Case


//  Problem Statement: 
    -> Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
 

// Example: 
    Example 1:
        Input: s = "Hello"
        Output: "hello"

    Example 2:
        Input: s = "here"
        Output: "here"

    Example 3:
        Input: s = "LOVELY"
        Output: "lovely"


// Observations: 
    -> Given string, replace every uppercase to lowercase
    -> Uppercase Range: 65-90
    -> Lowercase Range: 97-122
    -> replace the upercase range value with lowercase range value
        -> ch = ch - 'A' + 'a'

    // Complexity: 
        -> TC: O(s.size())
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(auto& ch: s) {
            if(ch >= 65 && ch <= 90) {  // Upper Case Range: (A=65 -- Z=90)
                ch = ch - 'A' + 'a';
            }
        }

        return s;
    }
};