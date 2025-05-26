/*

//  BS-2. Implement Lower Bound and Upper Bound | Search Insert Position | Floor and Ceil


// Lower Bound: 
    -> The smallest index such that the number at that index is grater or equal to the given.
                    arr[index] >= x

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


    -> Example: 
        arr[] = [3, 5, 8, 15, 19], n = 5, x = 16
                 0  1  2  3   4
                              |
        Lower Bound at index '4'
            arr[ind] >= x
        Lower Bound = 4


    -> Example: 
        arr[] = [3, 5, 8, 15, 19], n = 5, x = 20
                 0  1  2  3   4
                                  |
        Lower Bound at index '5' -> Last hypothetical index or the size of the array
            arr[ind] >= x
        Lower Bound = 5


    -> Example: 
        arr[] = [3, 5, 8, 15, 19, 19, 19], n = 7, x = 19
                 0  1  2  3   4
                              |
        Lower Bound at index '4' -> the smallest index or the first index, 
            arr[ind] >= x
        Lower Bound = 4


    -> Example: 
        arr[] = [1, 2, 3, 3, 7, 8, 9, 9, 9, 11], n = 10, x = 1
                 0  1  2  3  4  5  6  7  8  9

                                            
        -> We can do the linear search, but as the array is sorted.
        -> We can use Binary Search

        arr[] = [1, 2, 3, 3, 7, 8, 9, 9, 9, 11]
                 0  1  2  3  4  5  6  7  8  9
                 |                          |
                 low                        high

        Initially, ans = 10 -> size of array, even if there is no element possible, we will always return the hypothetical last index as our answer.

                arr[] = [1, 2, 3, 3, 7, 8, 9, 9, 9, 11]
                         0  1  2  3  4  5  6  7  8  9
                         |           |              |
                         low        mid            high

                    mid = (low + high) / 2 => 4
                    if (arr[mid] >= x)
                        arr[4] = 7
                        7 >= 1      => ans = 4
                        (high = mid - 1) => 3

                    

                arr[] = [1,  2, 3, 3, 7, 8, 9, 9, 9, 11]
                         0   1  2  3  4  5  6  7  8  9
                         |   |     |  
                         low |     high
                            mid

                    mid = 2
                    arr[mid] = 2
                    if (arr[mid] >= x) 
                        arr[1] = 2
                        2 >= 1      => ans = 2
                        (high = mid - 1) => 0
                       

                arr[] = [1, 2, 3, 3, 7, 8, 9, 9, 9, 11]
                         0  1  2  3  4  5  6  7  8  9
                        | |  
                      low high

                    mid = 0
                    arr[mid] = 1
                    if (arr[mid] >= x)
                        arr[1] = 1
                        1 >= 1      => ans = 0
                        (high = mid - 1) => -1

                Next pointer move to -1 => break out:
                
                ans = 0 -> index 0 is our answer.


    -> In lower bound if the target value exist, we return their index
    -> else we return the index, where value is just greater than the target value.


// Upper Bound: 
    -> Same concept, it's just the grater symbol, the number at than index must be grater than 'x', there is no equal symbol
    -> Smallest index such that "arr[index] > x"
    -> In Upper bound we will take the number as our answer, that will must be gater than the given target.

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
        
    -> Example: 
        arr[] = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12],     x = 0
                 0  1  2  3  4  5  6   7   8   9

            u_b = 0
            arr[0] = 2
        

// Search Insert Position:
    -> Problems is equivalent to saying finding the lower_bound.
    -> 35. Search Insert Position: https://github.com/sahilwep/DSA-Workspace/blob/main/Leetcode/Easy/35_Search_Insert_Position.cpp



// Floor and ceil in sorted array:
    // Floor: Largest number in array <= x
        -> floor is upper bound, it's just we will store answer in else case..


    // Ceil: smallest no in array >= x
        -> Ceil is nothing but lower bound

    -> Example: 
        arr[] = [10, 20, 30, 40, 50],   x = 25
                 0   1    2   3   4

            floor = 20
            ceil = 30

            
    -> Example: 
        arr[] = [10, 20, 25 30, 40],   x = 25
                 0   1   2   3   4
                  
            floor = 25
            ceil = 25



// C++ STL Shorthand for upper_bound & lower_bound

    lb = lower_bound(arr.begin(), arr.end(), target)    -> return an iterator pointing to that index, for vector type
    lb = lower_bound(arr, arr + n, target)              -> for array type
    

    lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();     -> return index
    up = upper_bound(arr.begin(), arr.end(), target) - arr.begin();     -> return index
    
// Time Complexity: O(logn)


// Shorthand revision: 
            l_b = arr[ind] >= x
            u_b = arr[ind] > x

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Lower Bound:
int lowerBound(vector<int>& arr, int x) {
    int n = arr.size();
    
    int ans = n;    // in worse case array size will be our answer index
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;

        // If Search Space is grater equal to target: 
        if(arr[mid] >= x) { 
            ans = mid;          // this may be our answer
            high = mid - 1;     // trim down, go to the left 
        } 
        else {  // else mid element is lesser than the target, we need to look on right
            low = mid + 1;
        }
    }
    
    return ans;
}


// Upper bound: 
int upperBound(vector<int>& arr, int x) {
    int n = arr.size();
    
    int low = 0, high = n - 1;
    int ans = n;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        
    }
    
    return ans;
}


// Search insert Position: https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};


// Find floor in sorted array:  https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
int findFloor(vector<int>& arr, int x) {
    int n = arr.size();

    int ans = n;
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(arr[mid] > x) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    
    if(ans == n) return -1;
    return ans;
    
}


// Find Ceil in sorted array:   https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
int findCeil(vector<int>& arr, int x) {
    int n = arr.size();
    
    int ans = n;
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    if(ans == n) return -1;
    return ans;
}