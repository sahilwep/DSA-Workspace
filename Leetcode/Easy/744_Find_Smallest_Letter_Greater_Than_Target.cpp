/*

//  744. Find Smallest Letter Greater Than Target | Binary Search on Answer



//  Problem Statement: 
    -> You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
    -> Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

// Example: 
    Example 1:
        Input: letters = ["c","f","j"], target = "a"
        Output: "c"
        Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.

    Example 2:
        Input: letters = ["c","f","j"], target = "c"
        Output: "f"
        Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.

    Example 3:
        Input: letters = ["x","x","y","y"], target = "z"
        Output: "x"
        Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].


// Observations: 
    -> Given letters & target, we need to return the just grater character.
    -> If theres no such character, return nums[0]
    
    // Binary Search on answer: 
        -> Try finding the value which is just grater character from the target value in whole the array.
        -> Implement Binary Search on answer..


        // Complexity: 
            -> TC: O(logN)
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    bool isGreater(char ch, char target) {  // Function to compute character just grater than the given target
        return ((ch - 'a') > (target - 'a'));
    }
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int low = 0;
        int high = n - 1;
        char ans = letters[0];

        while(low <= high) {
            int mid = low + (high - low) / 2;   // get in range

            if(isGreater(letters[mid], target)) {
                ans = letters[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};