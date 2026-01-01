/*

//  403. Frog Jump


//  Problem Statement: 
    - A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
    - Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
    - If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 
// Example:
    Example 1:
        Input: stones = [0,1,3,5,6,8,12,17]
        Output: true
        Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

    Example 2:
        Input: stones = [0,1,2,3,4,8,9,11]
        Output: false
        Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.


// Observations: 
    - we are at index '0' & given 1 unit at the first step.
    - Given the list of stones positions(in unit), in ascending order.
    - we need to cross the river, & in order to cross the river we need to get to the last last stone: stone[stone.size() - 1]
    - Whenever we are at some index idx:
        - the previous steps we have taken let say 'k'
        - Now in this step we can only go to 'k-1', 'k', 'k+1' units.
    - If we are reached to the last stone, means we can cross the river.


    // Approach:
        - we will start from the 0th index & in first step we will have to jump only 1-step
            - At 0th idx: curr = 0 + 1(unit) = 1
            - check if it's in the stones:
                - we can optimize the look from linear_search -> O(1), by simply store it into map
                - map<val, idx> -> this will help us to find the wether the upcoming stone in list or not?
            - NOTE: if 1 is not found in the stones: we can't go further.
        - Now we moved from 0th to 1st:
                currStep = 1
                preStep = 1

                Now we can only go: 'prevStep - 1' | 'prevStep' | 'prevStep + 1'
                    -> We have to check wether (currStep + {'prevStep - 1' || 'prevStep' || 'prevStep + 1'}) found in map : to go to that stones
        - Same we will do the further..
        - At any movement we if we reach to lastElement idx => return true
        - We can write a recursive solution to explore this given approach:
                
        // complexity:
            - TC: O(3^n) => At every step we are exploring 3 branch on 'n' data => This will give TLE

        // Memoization:
            - we will have multiple subproblem computing again & again...
            - DP State:
                curr, prevStep
            - return type boolean
            -> combine "curr@prevStep" => make it as key of string type..

            // Complexity:
                - SC: O(n^2)
                - TC: O(n^2)



*/

#include<bits/stdc++.h>
#include<algorithm>


// Memoization:
class Solution {
private:
    int n;
    unordered_map<int, int> mp;
    unordered_map<string, bool> t;  // memo-table:
    bool solve(int curr, int prevStep) {
        // We have reached the last stone:
        if(mp[curr] == n-1) return true;

        // Check in memo-table:
        string key = to_string(curr) + "@" + to_string(prevStep);
        if(t.count(key)) {
            return t[key];  // return directly.
        }

        // Explorations:
        // Jump k - 1 (only if > 0):
        if(prevStep - 1 > 0) {
            int a = curr + prevStep - 1;
            if(mp.count(a)) {
                if(solve(a, prevStep - 1)) return t[key] = true;
            }
        }
        
        int b = curr + prevStep;
        if(mp.count(b)) {
            if(solve(b, prevStep)) return t[key] = true;
        }

        int c = curr + prevStep + 1;
        if(mp.count(c)) {
            if(solve(c, prevStep + 1)) return t[key] = true;
        }

        return t[key] = false;   // not possible for this current branch.
    }
public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        
        // store the given stones into map:
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        // Edge case: Explicitly check do we have 1's stone or not?
        if(!mp.count(1)) return false;  // no-possible further move..

        // we will start with 1's stone with current prevJump as '1'
        return solve(1, 1);
    }
};


// Recursive Solution:
class Solution {
private:
    int n;
    unordered_map<int, int> mp;
    bool solve(int curr, int prevStep) {
        // We have reached the last stone:
        if(mp[curr] == n-1) return true;

        // Explorations:
        // Jump k - 1 (only if > 0):
        if(prevStep - 1 > 0) {
            int a = curr + prevStep - 1;
            if(mp.count(a)) {
                if(solve(a, prevStep - 1)) return true;
            }
        }
        
        int b = curr + prevStep;
        if(mp.count(b)) {
            if(solve(b, prevStep)) return true;
        }
        
        int c = curr + prevStep + 1;
        if(mp.count(c)) {
            if(solve(c, prevStep + 1)) return true;
        }

        return false;   // not possible for this current branch.
    }
public:
    bool canCross(vector<int>& stones) {
        n = stones.size();
        
        // store the given stones into map:
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        // Edge case: 
        if(!mp.count(1)) return false;  // no-possible further move..

        return solve(1, 1);
    }
};