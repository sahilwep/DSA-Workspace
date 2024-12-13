/*

//  2593. Find Score of an Array After Marking All Elements

//  Problem Statement:
    * You are given an array nums consisting of positive integers.
    * Starting with score = 0, apply the following algorithm:
        * Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
        * Add the value of the chosen integer to score.
        * Mark the chosen element and its two adjacent elements if they exist.
        * Repeat until all the array elements are marked.
    * Return the score you get after applying the above algorithm.

// Example:

    Example 1:
        Input: nums = [2,1,3,4,5,2]
        Output: 7
        Explanation: We mark the elements as follows:
        - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
        - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
        - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
        Our score is 1 + 2 + 4 = 7.

    Example 2:
        Input: nums = [2,3,5,1,3,2]
        Output: 5
        Explanation: We mark the elements as follows:
        - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
        - 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
        - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
        Our score is 1 + 2 + 2 = 5.



// Approach:
    // BruteForce Approach:
        -> find smallest element everytime & mark them & their adjacent element as marked.
        -> Mark these element with specific value -> INT_MAX
        -> So that we can ignore them..


    // Efficient Approach:
        -> Whenever we have to choose largest or smallest element -> We usually choose heap, or sorting approach.
        -> But we can't solve this question by normal sorting, because we may loose the index after sorting.
        -> If we maintain the index & then sort the value, then we can preserve index & values will be sorted & easy to compute.
            -> {(element, index), (element, index), (element, index)...(element, index)}
        -> Example:
                    nums = [2,1,3,4,5,2]
                    index   0 1 2 3 4 5

                    vec: {(1, 1), (2, 0), (2, 5), (3, 2), (4, 3), (5, 4)} -> Sorted
                            -       -               -
                            - - -   - -
                    nums = [2,1,3,4,5,2]
                    index   0 1 2 3 4 5


                        -> Get the smallest element & their index:
                            smallest = vec[i].first
                            idx = vec[i].second

                        -> Add that smallest element into score:
                            score += smallest

                        -> We need to mark their adjacent element:
                            adjacent element: (idx - 1) & (idx + 1)
                            NOTE: Their adjacent index should exist, should not be out of bound.
                        
                        -> To check weather these adjacent marked or not?
                            we can maintain an array vis[] -> Which will given us information about the element is marked or not?
                            -> Now, every step we will mark current element if they were not marked
                            -> and we will mark their adjacent of it, if they were not visited yet


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach: Sorting
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();

        // Create a vector vec that hold values & their initial index values:
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i], i});
        }

        sort(begin(vec), end(vec)); // sort the values of vec according to their values.

        for(int i=0;i<n;i++){
            cout << vec[i].first << " " << vec[i].second << endl;
        }
        cout << endl;

        vector<bool> vis(n); // create a visited array of size n

        long long cost = 0;
        for(int i=0;i<n;i++){   
            int smallest = vec[i].first;                // smallest element
            int idx = vec[i].second;                    // smallest index

            // if the element is not visited?
            if(!vis[idx]){
                cost += smallest;       // add value to cost
                vis[idx] = 1;           // mark them as visited
                if(idx - 1 >= 0 && !vis[idx-1]){   // now check their is an adjacent element & if it's not visited yet:
                    vis[idx-1] = 1;     // mark visited the previous adjacent element
                }
                if(idx + 1 <= n-1 && !vis[idx+1]){   // now check their is an adjacent element & if it's not visited yet
                    vis[idx+1] = 1;     // mark visited the next adjacent element
                }
            }
        }

        return cost;
    }
};

// BruteForce Solution:
class Solution_Brute{
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i=0;i<nums.size();i++){
            // find the minimum element:
            int minVal = INT_MAX;
            int idx = -1;
            for(int j=0;j<nums.size();j++){
                if(nums[j] < minVal){
                    minVal = nums[j];
                    idx = j;
                }
            }

            // Update that element & their adjacent once:
            if(minVal != INT_MAX){
                ans += nums[idx];
                nums[idx] = INT_MAX;
                if(idx > 0){
                    nums[idx-1] = INT_MAX;
                }
                if(idx < n-1){
                    nums[idx+1] = INT_MAX;
                }
            }else{
                break;
            }
        }

        return ans;
    }
};