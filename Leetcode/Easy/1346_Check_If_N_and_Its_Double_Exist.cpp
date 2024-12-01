/*

// 1346. Check If N and Its Double Exist


// Problem Statement:
    * Given an array arr of integers, check if there exist two indices i and j such that:
        i != j
        0 <= i, j < arr.length
        arr[i] == 2 * arr[j]

 
// Example:

    Example 1:
        Input: arr = [10,2,5,3]
        Output: true
        Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

    Example 2:
        Input: arr = [3,1,7,11]
        Output: false
        Explanation: There is no i and j that satisfy the conditions.



// Observation: 
    -> Simple but tricky question: 
        -> Constrains:
            -> i != j
            -> 0 <= i, j <= arr.size()
            -> arr[i] == 2 * arr[j]

    -> To solve this question in O(n)
        -> Use map to store every element with their index, we need index because we need to compare (i != j)
        -> After that iterate in given array, & find in map for every required element:
            -> If found any, check constrains: 
                if(i != mp[2*arr[i]]){  // comparing both the element index
                    return true;
                }   // this check will make sure we are not accessing same element, ex: '0', if there is '0' = 2*0 = 0, which will return true..

// Complexity: 
    * TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Efficient Solution: O(n)
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
        }

        for(int i=0;i<arr.size();i++){
            int req = 2 * arr[i];
            if(mp.find(req) != mp.end()){
                if(i != mp[req]) return true;
            }
        }

        return false;   // else return false
    }
    // Brute Force Solution: O(n^2)
    bool checkIfExist_Brute(vector<int>& arr) {
        int n = arr.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && arr[i] == 2*arr[j]){
                    return true;
                }
            }
        }

        return false;
    }
};