/*

//  Leaders in an Array | Suffix Max |


//  Problem Statement: 
    -> You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:
    Input: arr = [16, 17, 4, 3, 5, 2]
    Output: [17, 5, 2]
    Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.

    Input: arr = [10, 4, 2, 4, 1]
    Output: [10, 4, 4, 1]
    Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side

    Input: arr = [5, 10, 20, 40]
    Output: [40]
    Explanation: When an array is sorted in increasing order, only the rightmost element is leader.

    Input: arr = [30, 10, 10, 5]
    Output: [30, 10, 10, 5]
    Explanation: When an array is sorted in non-increasing order, all elements are leaders.


// BruteForce Approach: 
    -> For every element, find if there's no max element in right side, we will consider that element as leader
    -> Use Nested loop approach to find leaders.

    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)

    
// Efficient Approach: 
    -> Start iterating from right to left
    -> Maintain one maximum array which will hold the leaders informations
    -> move left side & build answer.
    -> Last reverse the answer list to get leaders in order.

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)
    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Approach: 
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            bool isMaxFound = false;

            for(int j = i + 1; j < n; j++) {
                if(arr[j] > arr[i]) {
                    isMaxFound = true;
                    break;
                }
            }
            
            if(!isMaxFound) {
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};

// Efficient Approach: 
class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        
        // Suffix Max:
        vector<int> ans;
        ans.push_back(arr[n-1]);
        int maxEl = arr[n-1];
        
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] >= maxEl) {
                ans.push_back(arr[i]);
                maxEl = arr[i];
            }
        }
        
        reverse(begin(ans), end(ans));  // reverse the build list.
        
        return ans;
    }
};