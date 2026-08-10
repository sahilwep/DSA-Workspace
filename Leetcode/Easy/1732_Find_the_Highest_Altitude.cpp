/*

//  1732. Find the Highest Altitude


//  Problem Statement: 
    - There is a biker going on a road trip. The road trip consists of n + 1 points at various altitudes. The biker starts his trip on point 0 with altitude equal 0.
    - You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). 
    - Return the highest altitude of a point.


 
// Example:
    Example 1:
        Input: gain = [-5,1,5,0,-7]
        Output: 1
        Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

    Example 2:
        Input: gain = [-4,-3,-2,-1,4,3,2]
        Output: 0
        Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.


// Observations:
    - From the given altitude, we only need to find out the highest point we can reach...
    - We can maintain on altitude val, and keep changing as per give gains, and we will store the max among all the changes.

    // Complexity:
        - TC: O(n)
        - SC: O(1)

        
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int travel = 0;
        int ans = 0;        
        for(auto &it: gain) {
            travel += it;
            ans = max(ans, travel);
        }

        return max(0, ans);
    }
};