/*

//  BS-9. Find Peak Element

//  Problem Statement: 
    -> A peak element is an element that is strictly greater than its neighbors.
    -> Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
    -> You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
    -> You must write an algorithm that runs in O(log n) time.

 

// Example: 
    Example 1:
        Input: nums = [1,2,3,1]
        Output: 2
        Explanation: 3 is a peak element and your function should return the index number 2.

    Example 2:
        Input: nums = [1,2,1,3,5,6,4]
        Output: 5
        Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.


// Observations: 
    -> Given that -1 & nth index has -INT_MAX
    -> peak is when left & right is smaller
    -> from the given nums => nums[i] != nums[i-1]

    // Observe this question with single peak: 

        -> Let's say our given problem has single peak given: 
            [1,2,3,5,6,3,2,1]
                     |
                    peak

        -> If we made the graph from the given numbers:

                          peak
                           /\  
                          /  \ 
                         /    \
                 increasing  Decreasing => slopes


        -> While computing with binary seach we can have our mid, which points on 3 possible locations: 
            
              mid        
              /\                  /\               /\  
             /  \            mid /  \             /  \ mid
            /    \              /    \           /    \
              I                   II               III


            Case I: mid is at peak ->   nums[mid - 1] < nums[mid] > nums[mid + 1]   => directly return the answer.
            

            Case 2: Increasing slope, mid is on the left of peak.

                        By checking this conditions (nums[mid-1] < nums[mid]) => we can depict where we have to move.
                        When we have this case, we should move right side => low = mid + 1, so that we can move right side & find peak.
            
            Case 3: Decreasing slope, mid is on the right of peak.

                        By checking this conditions (nums[mid-1] > nums[mid]) => we have to move left side
                        When we have this case, set (high = mid - 1), so that we can move left side & find peak.


        -> Question might arises that what if we are at index '0' or 'n-1':
            -> There is two options:
                Option 1: handel them saperately & set (low = 1 & high = n -2) scope
                Option 2: handel them with conditions of checking when we are at index '0' & 'n-1', so that we can't get any out-of-bound value.


    // Observe this question with multiple peaks:

        -> Now If we observe this, we have multiple peaks, Well the above logic work here with slight change.

            /\    /\    /\  
           /  \  /  \  /  \ 
          /    \/    \/    \

        -> let say we have peak somewhere: 

                    /\    /\    /\  
                   /  \  /  \@ /  \ 
                  /    \/    \/    \

                -> Peak is on decreasing slope, even if we move towards left, we still find a peak.


                    /\    /\    /\  
                   /  \ @/  \  /  \ 
                  /    \/    \/    \

                -> Peak is on increasing slope, even if we move towards right, we still find a peak.
                


        -> With peaks we can see there are many bottoms.

            /\    /\    /\  
           /  \  /  \  /  \ 
          /    \/    \/    \
               |      |

        -> it's just we have to handel this case rest all the case is fine to work for this multiple peaks..

        -> When we have this case: (nums[mid-1] > nums[mid] < nums[mid+1])
            -> Either we move right or left, we can easily find peak.
        -> NOTE: You might be thinking what happened for the first & last index, well we have handel them saperately and we are string our range with (1, to n-2)


        // Solution: 
            -> Handel starting & ending index separately.
            -> Handel edge case.
            -> Start with range (1 to n - 2)
            -> First check the peak conditions: nums[mid-1] < nums[mid] > nums[mid+1]
            -> Second check wether we are at increasing slope => move right
            -> Or decreasing slope => move left
            -> Or on the bottom => move anywhere

// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge case: 
        if(n == 1) return 0;                  // first index is our peak
        if(nums[0] > nums[1]) return 0;       // first index as peak
        if(nums[n-2] < nums[n-1]) return n-1; // last index as peak

        int low = 1;
        int high = n - 2;

        while(low <= high) {
            int mid = (low + high) / 2;

            // Fall on peak
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            }

            // Increasing Slope: Go on right side
            if(nums[mid - 1] < nums[mid]) {
                low = mid + 1;
            }
            // Decreasing Slope: Go on left side
            else if(nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            }
            // Fall on bottom point: go on right || left, anything will work
            else {
                high = mid - 1;
                // OR: 
                // low = mid + 1;
            }
        }

        return -1;  // invalid input.
    }
};