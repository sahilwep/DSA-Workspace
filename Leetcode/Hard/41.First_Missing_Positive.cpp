/* 

// 41. First Missing Positive


// Problem Statement:
    * Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
    * You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example:

    Input: nums = [1,2,0]
    Output: 3
    Explanation: The numbers in the range [1,2] are all in the array.

    Input: nums = [3,4,-1,1]
    Output: 2
    Explanation: 1 is in the array but 2 is missing.

    Input: nums = [7,8,9,11,12]
    Output: 1
    Explanation: The smallest positive integer 1 is missing.


// Observations:
    * iterate in an array & find those value which are not at their index place..
    * Then move those element into their index place.
    * At last return the value, which is not at their index place.

        nums[i] != nums[nums[i] - 1])

        arr = [1 2 0]
        idx =  0 1 2

        Iterations:

                nums[0] != nums[nums[0] - 1]
                1  != 1 => yes it's there

                nums[1] != nums[nums[1] - 1]
                2 != 2  => Yes it's there
                
                nums[2] == 0 & condition should be it should grater than 0, so it will not be included..
                    nums[2] != nums[nums[2] - 1]
                    0 != nums[-1] -> Nothing there...
                        swap(nums[i], nums[nums[i] - 1])
                
                * Iterate & find where we have -1


*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while((nums[i] < n && nums[i] > 0) &&  (nums[i] != nums[nums[i] - 1]) ){
                cout << nums[nums[i] - 1] << " ";
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1; // returning the out of bound element
    }
};