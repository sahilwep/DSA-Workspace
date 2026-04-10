/*

//  2839. Check if Strings Can be Made Equal With Operations I


//  Problem Statement: 
    - You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
    - You can apply the following operation on any of the two strings any number of times:
        - Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
    - Return true if you can make the strings s1 and s2 equal, and false otherwise.

 
// Example:
    Example 1:
        Input: s1 = "abcd", s2 = "cdab"
        Output: true
        Explanation: We can do the following operations on s1:
        - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
        - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.

    Example 2:
        Input: s1 = "abcd", s2 = "dacb"
        Output: false
        Explanation: It is not possible to make the two strings equal.


// Observations:
    - To make swapping at odd & even position in s1, and we have to check wether we can able to make it equal or not, we can simply:
        - Hash every odd position characters in odd_map
        - and similarly hash every even position characters in even_map.
        - We are using map, because map will give us O(1) lookup.
    - At last simply iterate on every odd & even position & match with strings s2 & remove from the map & make swapping possible..
    - If we are able to process every steps successfully, return true, else if any characters is not found while lookup, return false.

    // Complexity:
        -> TC: O(n)
        -> SC: O(n)
            - n = size of string.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();

        // Insert all the characters from s1:
        unordered_map<char, int> odd, even;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                even[s1[i]]++;
            } else {
                odd[s1[i]]++;
            }
        }

        // Iterate in s2 & check the validity of characters:
        for(int i = 0; i < n; i++) {
            int ch = s2[i];
            if(i % 2 == 0) {
                if(even.count(ch)) {
                    even[ch]--;
                    if(even[ch] == 0) {
                        even.erase(ch);
                    }
                } else return false;
            } else {
                if(odd.count(ch)) {
                    odd[ch]--;
                    if(odd[ch] == 0) {
                        odd.erase(ch);
                    }
                } else return false;
            }
        }
        
        return true;    // yes we can swap & make intended string "s2"
    }
};