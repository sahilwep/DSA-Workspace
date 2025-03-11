/*

//  1358. Number of Substrings Containing All Three Characters


//  Problem Statement: 
    Given a string s consisting only of characters a, b and c.
    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example:

    Example 1:
        Input: s = "abcabc"
        Output: 10
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

    Example 2:
        Input: s = "aaacb"
        Output: 3
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

    Example 3:
        Input: s = "abc"
        Output: 1


// BruteForce Solution:
    -> using nested loop, try to find all window which has valid given constrains.
    
    // Complexity:
        -> TC: O(n^2)
        -> SC: O(1)
        

// Efficient Solution:

    // Problem Statement:
        -> Given a string 's' consisting of characters 'a', 'b', and 'c'.
        -> We need to find the number of substrings containing at least one occurrence of all three characters.

    // Approach:
        -> Use the two-pointer (Sliding Window) technique to efficiently track valid substrings.
        -> Maintain a hashmap 'mp' to keep track of the character count in the current window.
        -> Use two pointers: 'left' and 'right'.
            - 'right' pointer expands the window by iterating through the string.
            - 'left' pointer shrinks the window whenever all three characters are present in the map.
        -> For every valid window, add (n - right) to the answer.
            - This counts all possible substrings starting from the current 'left' index and ending at all positions from 'right' to 'n-1'.


    // Explanation of Key Logic:
        -> When 'mp.size() >= 3', we have a valid window that includes all required characters.
        -> Since every substring starting from the current 'left' and ending at any position to the right is valid, we add (n - right) to the answer to count all those substrings efficiently.
        
    // Example:
        
        s = abcabc
        n = 6

                ans = (n - j) -> subtracting 'j' from 'n' will give us total number of valid subarray we can form with valid characters..


            j = 0:
                        n-1
                a b c a b c
                ij
                 0
                        hash mp[a]
                        ans += 
                        mp = {a:1, b:0, c:0}
            
            j = 1:
                          n-1
                a b c a b c
                i j
                  1
                        hash mp[b]
                        ans += 
                        mp = {a:1, b:1, c:0}
            
            j = 2: 
                          n-1
                a b c a b c
                i   j
                    2
                        hash mp[c]
                        mp = {a:1, b:1, c:1}
                    -> We get the valid size of map:
                        Store ans += (6 - 2)
            
                    -> move i pointer forward & check:
                        remove 'a' from map
                        i++;

                        mp = {a:0, b:1, c:1}

            j = 3:
                          n-1
                a b c a b c
                  i   j
                      3
                        hash mp[a]
                        mp = {a:1, b:1, c:1}
                    -> We get the valid size of map:
                        Store ans += (6 - 3)
            
                    -> move i pointer forward & check:
                        remove 'b' from map
                        i++;
                        mp = {a:1, b:0, c:1}

            j = 4:
                          n-1
                a b c a b c
                    i   j
                        4
                        hash mp[b]
                        mp = {a:1, b:1, c:1}
                    -> We get the valid size of map:
                        Store ans += (6 - 4)
            
                    -> move i pointer forward & check:
                        remove 'c' from map
                        i++;
                        mp = {a:1, b:1, c:0}

            j = 5:
                          n-1
                a b c a b c
                      i   j
                          5
                        hash mp[c]
                        mp = {a:1, b:1, c:1}
                    -> We get the valid size of map:
                        Store ans += (6 - 5)
            
                    -> move i pointer forward & check:
                        remove 'a' from map
                        i++;
                        mp = {a:0, b:1, c:1}

            
            j = Out Of Bound:
                        Total ans = (6 - 2) + (6 - 3) + (6 - 4) + (6 - 5)
                        ans = 4 + 3 + 2 + 1
                        ans = 10

    // Complexity:
        -> TC: O(n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: Sliding Window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int cnt = 0;   
        int left = 0;
        int right = 0;
        unordered_map<char, int> mp;   // Hash map to track character frequency in the window.


        while(right < n) {
            // Add the current character in the window to the hash map.
            mp[s[right]]++;  

            // If we have all three required characters in our window.
            while(mp.size() >= 3) {
                /*
                    -> For every valid window found:
                        -> Every substring starting from 'left' and ending at positions from 'right' to 'n-1' will be a valid substring that meets the criteria.
                    -> Adding (n - right) accounts for those substrings.
                */
                cnt += n - right;  // Count all valid substrings starting from 'left' with current window.

                
                // Now shrink the window from the left to check if we can form more valid subsets.
                mp[s[left]]--;    // Remove the leftmost character from the window.
                if(mp[s[left]] == 0) {  // If its count becomes zero, erase it from the map.
                    mp.erase(s[left]);
                }
                left++;    // Move the left pointer forward to reduce window size.
            }

            // Expand the window by moving the right pointer forward.
            right++;    
        }

        return cnt;   // Return the total count of valid substrings.
    }
};
    


// BruteForce Solution: 
class Solution {
private:
    bool check(string s, int start, int end) {  // Function to check if substring has all three characters or not?
        vector<bool> word(3, false);
        
        for(int i = start; i <= end; i++) {
            if(s[i] == 'a') word[0] = true;
            else if(s[i] == 'b') word[1] = true;
            else if(s[i] == 'c') word[2] = true;
        }

        return (word[0] && word[1] && word[2]);
    }
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // Check for all possible substring:
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j < n; j++) {    // "j = i + 2", because we are sure that we need atleast 3 characters for valid window.
                if(check(s, i, j)) cnt++;
            }
        }

        return cnt;
    }
};