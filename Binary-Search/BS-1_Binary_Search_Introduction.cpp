/*

//   BS-1. Binary Search Introduction | Real Life Example | Iterative | Recursive | Overflow Cases 



//  Binary Search:
    -> Binary Search works in sorted data.
    -> Searching algorithm used to Search element from a given sorted list.
    -> Binary search works on method of "divide & explore"
        ->  We consider two pointers "low" & "high"
            low = 0
            high = n-1  => last index

        -> Split the size in half (middle point) & check wether the given number is grater or smaller to the middle point, & search on left or right side accordingly...
        -> Example: 

            [3, 4, 6, 7, 9, 12, 16, 17]     -> Sorted data
            |                        |
            low                     high

                Target = 6
            
            -> mid = low + high/2

                [3, 4, 6, 7, 9, 12, 16, 17]     -> Sorted data
                |         |              |
                low       mid           high

                    mid > target    -> Explore left side
                    Set high = mid - 1  


                [3, 4, 6, 7, 9, 12, 16, 17]     -> Sorted data
                |   |   |   
                low |  high
                    |
                new Mid = 4
                    mid < target -> Explore right side
                    set low = mid + 1
                

                [3, 4, 6, 7, 9, 12, 16, 17]     -> Sorted data
                      ||   
                    low high
                   Low & high pointing at same search space

                    mid = low + high / 2
                    mid = 2 + 2 / 2 => 2

                    mid == target => return "True"



    // Pseudo Code:
        // Iterative:

            fun(arr, n, target){
                low = 0,    high = n -1;
                while(low <= high) {
                    mid = (low + high) / 2;
                    if(arr[mid] == target) return mid;
                    else if(target > arr[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }

        // Recursive:
            fun(arr, low, high, target) {
                if(low > high) return -1;   // Base case: 

                int mid = (low + high) / 2;

                if(arr[mid] == target) return mid;
                else if(target > arr[mid]) {
                    return fun(arr, mid + 1, high, target);
                } 
                else {
                    return fun(arr, low, mid - 1, target);
                }
            }



// Integer Overflow:
    -> Integer overflow is the case where our value get round off..
    -> Example: 
        We have value 0...............INT_MAX
                      |                 |
                      low               high

                      target = INT_MAX

                    when we have our pointer low & high at INT_MAX
                            (low + high) => Overflow the integer value.
                    
                    IT's better if we do: 

                            mid = (low + (high - low)) / 2


                    This will help us to maintain pointer with range...



// Complexity: 
    -> TC: O(log(n))
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Iterative Code:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;  // not found.
    }
};


// Recursive Solution:
class Solution {
private: 
    int solve (vector<int>& nums, int low, int high, int target) {
        // Base condition:
        if(low > high) return -1;

        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid; // element found.
        else if(target > nums[mid]) {
            return solve(nums, mid + 1, high, target);
        } else {
            return solve(nums, low, mid - 1, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums, 0, n-1, target);
    }
};