/*

//  756. Pyramid Transition Matrix


//  Problem Statement: 
    - You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
    - To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
        - For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
    - You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
    - Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

 
// Example;
    Example 1:
        Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
        Output: true
        Explanation: The allowed triangular patterns are shown on the right.
        Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
        There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.

    Example 2:
        Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
        Output: false
        Explanation: The allowed triangular patterns are shown on the right.
        Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilities, you will get always stuck before building level 1.


// Observations: 
    - This problems is more of implementations side, where from bottom, try choosing the matching pattern & apply further, if it's not working backtrack to the other one...
    - Try finding wether we are reachable to top or not?

    // BruteForce Solution:
        - Idea is to recursively solve this problem statement.
        - We will start from index '0' of the current Bottom.
        - We will have to start looking into the given allowed
            - we are only mathing the first two characters, and last character will be added inot our above..
            - What we can do to improve the query time in O(1), is we can use something like map:
                - map<string, vector<char>> 
                - there can be possibility that we have some strings like: {"ADC", "ADA",.. etc}, So we will have to store all the "AD" matched string characters.
                - This is why we are using the vector<char>
        - Functions structure looks something like:
            bool solve(bottom, idx, above){...} -> it should return us into T/F so that we can check wether we are able to build the parmid or not.
            - Return Values:
                -> We will return True if the bottom length is '1', means we reach to top.
                -> We will return the next level to look only if:
                Means our index is reached to the last position, now we don't need to check on the current level because we are finished with that, as we need to move above.
                (idx == bottom.length() - 1) {
                    return solve(above, 0, "")  -> we are changing the current above as new level above as bottom, started with idx=1, & above will be "" empty string..
                }

            - Core Logic:
                - Get the matched pattern part from bottom:
                    string pattern = substr(idx, 2);  // this will gives us the patter which we need to match, e.g "AB" from the bottom current index.
                    if(!mp.count(pattern)) {
                        return false;   // we don't have any match sequence in our list..
                    }

                    // Else:
                    for(auto &ch: mp[pattern]) {  // iterate on every store character in that pattern 
                        // Include that character into the above:
                        above.push_back(ch);

                        // Explore the building possibilities in future, like can we build pyramid?:
                        if(solve(bottom, idx + 1, above)) return true;

                        // Revert back above so that we can try with other possibility.
                        above.pop_back();
                    }

                    // After all the check, we are not able to build anything, then also return false:
                    return false;
        - This will be the recursive logic upon which we will build our solutions.

    // Memoization:
        - variable values:
            - curr, idx, above
            - make a key of string (curr + to_string(idx) + above)
        - we need our answer in bool, so boolean will be returned
        - Making a dp table of <string, bool> type
        - we can use u_map<string, bool> 


    // Complexity:
        - TC: O(L^n)    
            - Exponential Growth, This is why we have very short constrains: (A-F) characters only.
            - Also the bottom length is (2 <= n <= 6)
            - This grows explontially: 7^n
            - Total blocks: n^2
            -> More Precise, TC: O(7^(2^n))
        - SC: O(L^n) => This also grows exponentially



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution:
class Solution {
private:
    unordered_map<string, bool> t;
    unordered_map<string, vector<char>> mp;
    bool solve(string curr, int idx, string above) {
        if(curr.size() == 1) return true;   // reached to top.

        string key = curr + "_" + to_string(idx) + "_" + above; // make a key for memo-table

        // Check in memo-table:
        if(t.count(key)) {
            return t[key];
        }

        if(idx == curr.size() - 1) {    // time to move to next row, i.e above row.
            return t[key] = solve(above, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()) { // if pair is not available, then return false
            return t[key] = false;
        }

        // else check:
        for(auto &ch: mp[pair]) {
            above.push_back(ch);    // do the task

            // Explore
            if(solve(curr, idx + 1, above) == true) return t[key] = true;

            // Revert the task:
            above.pop_back();
        }

        return t[key] = false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(auto &s: allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        
        return solve(bottom, 0, "");
    }
};

// BruteForce: TLE
class Solution {
private:
    unordered_map<string, vector<char>> mp;
    bool solve(string curr, int idx, string above) {
        if(curr.size() == 1) return true;   // reached to top.


        if(idx == curr.size() - 1) {    // time to move to next row, i.e above row.
            return solve(above, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()) { // if pair is not available, then return false
            return false;
        }

        // else check:
        for(auto &ch: mp[pair]) {
            above.push_back(ch);    // do the task

            // Explore
            if(solve(curr, idx + 1, above) == true) return true;

            // Revert the task:
            above.pop_back();
        }

        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(auto &s: allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        
        return solve(bottom, 0, "");
    }
};