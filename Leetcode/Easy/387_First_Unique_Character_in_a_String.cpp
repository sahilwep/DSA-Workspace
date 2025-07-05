/*

//  387. First Unique Character in a String


//  Problem Statement: 
    -> Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 
// Example: 

    Example 1:
        Input: s = "leetcode"
        Output: 0
        Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

    Example 2:
        Input: s = "loveleetcode"
        Output: 2

    Example 3:
        Input: s = "aabb"
        Output: -1


// Observations: 
    -> Find the first unique character from given string.


    
// BruteForce Approach: 
    -> Implement the solution with nested loop to find the unique character form given string.

    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)


// Efficient Solution: 
    -> Using hashmap we can find the first unique element from given string.

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution: 
class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            bool isOccur = false;
            for(int j = 0; j < n; j++) {
                if(i != j && s[i] == s[j]) {
                    isOccur = true;
                    break;
                }
            }

            if(!isOccur) return i;
        }

        return -1;  // Unique value, not found 
    }
};

// Efficient Solution: 
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        // Hash the given characters:
        unordered_map<char, int> mp;
        for(auto &ch: s) {
            mp[ch]++;
        }

        for(int i = 0; i < n; i++) {
            if(mp[s[i]] == 1) return i;
        }

        return -1;
    }
};