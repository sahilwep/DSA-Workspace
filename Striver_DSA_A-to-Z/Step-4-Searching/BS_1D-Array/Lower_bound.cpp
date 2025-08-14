/*

//  Implement Lower Bound


//  Problem Statement: 
    -> Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.
    -> Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

// Examples:

    Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
    Output: 3
    Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

    Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
    Output: 4
    Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

    Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
    Output: 7
    Explanation: As no element in arr[] is greater than 100, return the length of array.


    -> The smallest index such that the number at that index is grater or equal to the given.
                    arr[index] >= x


// Lower Bound: 
    -> The smallest index such that the number at that index is grater or equal to the given number.
                    => (arr[index] >= x)
                    
    -> Example:
        arr[] = [3, 5, 8, 15, 19], n = 5, x = 8
                 0  1  2  3   4
                       |
        Lower Bound at index '2'
            arr[ind] >= x
        Lower Bound = 2



    -> Example: 
        arr[] = [3, 5, 8, 15, 19], n = 5, x = 9
                 0  1  2  3   4
                          |
        Lower Bound at index '3'
            arr[ind] >= x
        Lower Bound = 3


    // Complexity: 
        -> TC: O(logn)
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// STL:
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        return lower_bound(begin(arr), end(arr), target) - begin(arr);
    }
};


// Lower Bound Implementations:
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= target) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
