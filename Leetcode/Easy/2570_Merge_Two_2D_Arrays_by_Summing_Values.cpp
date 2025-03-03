/*

//  2570. Merge Two 2D Arrays by Summing Values


//  Problem Statement: 
    -> You are given two 2D integer arrays nums1 and nums2.
        -> nums1[i] = [id[i], val[i]] indicate that the number with the id id[i] has a value equal to val[i].
        -> nums2[i] = [id[i], val[i]] indicate that the number with the id id[i] has a value equal to val[i].

    -> Each array contains unique ids and is sorted in ascending order by id.
    -> Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:
        -> Only ids that appear in at least one of the two arrays should be included in the resulting array.
        -> Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
    -> Return the resulting array. The returned array must be sorted in ascending order by id.


// Example:

    Example 1:

        Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
        Output: [[1,6],[2,3],[3,2],[4,6]]
        Explanation: The resulting array contains the following:
        - id = 1, the value of this id is 2 + 4 = 6.
        - id = 2, the value of this id is 3.
        - id = 3, the value of this id is 2.
        - id = 4, the value of this id is 5 + 1 = 6.

    Example 2:

        Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
        Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
        Explanation: There are no common ids, so we just include each id with its value in the resulting list.


// Observations: 
    -> We are given two 2D array nums1 & nums2, with value nums_X[i] = [id[i], val[id]]
    -> Each array contains unique ids and is sorted in ascending that the number by 'id'
    -> merge the two array into one array that is sorted in ascending order by 'id'.
        -> If the same id exist in both the array, sum the value & add in resulting array.
        -> If the id is unique just normally include.
    

// Map Based Solution: 
    -> Use map to store the key-value pair
    -> When same key occur again sum up in their value.
    // Complexity: 
        -> TC: O(n * log(n) + m * log(m))
        -> SC: O(n + m)


// Array Merge Based Solution:
    -> merge logic with few modification, we need to compare it with id's & store the value accordingly.
    // Complexity: 
        -> TC: O(n + m)
        -> TC: O(n + m)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Merge Logic: O(n)
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> res;
        int i = 0, j = 0;

        while(i < n && j < m) {
            auto p1 = nums1[i];
            auto p2 = nums2[j];

            if(p1[0] == p2[0]) {  // first check both equal case:
                res.push_back({p1[0], (p1[1] + p2[1])});
                i++;
                j++;
            }
            else if(p1[0] < p2[0]) {
                res.push_back({p1[0], p1[1]});
                i++;
            }else{
                res.push_back({p2[0], p2[1]});
                j++;
            }
        }

        // Store leftOver:
        while(i < n) {
            res.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }
        while(j < m) {
            res.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return res;
    }
};


// Map Based Solution: O(n * log(n) + m * log(m))
class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n = nums1.size(), m = nums2.size();
    
            map<int, int> mp;
    
            for(int i = 0; i < n; i++) {
                mp[nums1[i][0]] = nums1[i][1];  // insert first array into the map
            }
    
            for(int j = 0; j < m; j++) {
                mp[nums2[j][0]] += nums2[j][1];
            }
    
            vector<vector<int>> res;
            for(auto i: mp)  {
                cout << i.first << " " << i.second << endl;
                res.push_back({i.first, i.second});
            }
    
            return res;
        }
    };