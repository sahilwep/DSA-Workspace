/*

//  Implement Upper Bound



//  Problem Statement: 
    -> Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
    -> The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.
    -> Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

// Examples :

    Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
    Output: 3
    Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.

    Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
    Output: 6
    Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.

    Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
    Output: 7
    Explanation: As no element in arr[] is greater than 100, return the length of array.


// Upper Bound:
    -> Same concept as lower bound, it's just the grater symbol, the number at that index must be grater than 'x', there is no equal symbol.
    -> Smallest index such that "arr[index] > x"
    -> In Upper bound we will take the number as our answer, that will must be grater than the given target.
    -> Example: 
        arr[] = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12],     x = 6
                 0  1  2  3  4  5  6   7   8   9

            u_b = 3
            arr[3] = 7
        
    -> Example: 
        arr[] = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12],     x = 11
                 0  1  2  3  4  5  6   7   8   9

            u_b = 9
            arr[9] = 12
        
    -> Example: 
        arr[] = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12],     x = 12
                 0  1  2  3  4  5  6   7   8   9

            u_b = 10
            arr[10] = nothing
        


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Upper Bound STL:
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        return upper_bound(begin(arr), end(arr), target) - begin(arr);
    }
};


// Upper Bound Impl.
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        
        int low = 0;
        int high = n - 1;
        int ans = n;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
    