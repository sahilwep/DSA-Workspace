/*

//  344. Reverse String


//  Problem Statement: 
    -> Write a function that reverses a string. The input string is given as an array of characters s.
    -> You must do this by modifying the input array in-place with O(1) extra memory.


// Example: 
    Example 1:
        Input: s = ["h","e","l","l","o"]
        Output: ["o","l","l","e","h"]

    Example 2:
        Input: s = ["H","a","n","n","a","h"]
        Output: ["h","a","n","n","a","H"]


// Observations: 
    -> Start solving with two pointers, i = 0 & j = s.size() - 1
    -> iterate while (i < j)
    -> Swap these two positions..

// Complexity: 
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;
        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};