/*

//  Reverse an Array

//  Problem Statement: 
    - You are given an array of integers arr[]. You have to reverse the given array.
    - Note: Modify the array in place.

// Examples:

    Input: arr = [1, 4, 3, 2, 6, 5]
    Output: [5, 6, 2, 3, 4, 1]
    Explanation: The elements of the array are [1, 4, 3, 2, 6, 5]. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is [5, 6, 2, 3, 4, 1].

    Input: arr = [4, 5, 2]
    Output: [2, 5, 4]
    Explanation: The elements of the array are [4, 5, 2]. The reversed array will be [2, 5, 4].

    Input: arr = [1]
    Output: [1]
    Explanation: The array has only single element, hence the reversed array is same as the original.

// Approach:
    - Maintain two pointers start & end
    - as move start forward & end backwords & make swaps..


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    void solve(int left, int right, vector<int>& arr) {
        if(left >= right) {
            return;
        }
        swap(arr[left], arr[right]);
        solve(left + 1, right - 1, arr);
    }
public:
    void reverseArray(vector<int> &arr) {
        
        int left = 0;
        int right = arr.size() - 1;
        
        return solve(left, right, arr);
    }
};