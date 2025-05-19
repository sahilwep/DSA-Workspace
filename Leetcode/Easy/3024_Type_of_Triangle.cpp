/*

//  3024. Type of Triangle


//  Problem Link: https://leetcode.com/problems/type-of-triangle/description/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(begin(nums), end(nums));   // sort them for easier comparision

        // Check Valid triangle: 
        if(nums[0] + nums[1] <= nums[2]) return "none"; // invalid triangle


        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";  // all sides are equal
        if(nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2]) return "isosceles";  // any two sides should be equal

        // All sides are distinct.
        return "scalene";
    }
};