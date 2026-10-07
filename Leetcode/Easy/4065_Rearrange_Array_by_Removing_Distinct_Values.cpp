/*

//  4065. Rearrange Array by Removing Distinct Values


//  Problem Statement: 
    - You are given an integer array nums.
    - You start with an empty array ans. Repeat the following operation until nums is empty:
        - Identify all distinct values currently present in nums.
        - Remove one occurrence of every distinct value currently in nums, and append those values to ans in ascending order.
    - Return the array ans.

 
// Example:
    Example 1:

        Input: nums = [3,1,3,2,1,3]
        Output: [1,2,3,1,3,3]
        Explanation: 

            Operation	Appended to ans	    nums after	        ans after
            1	        1, 2, 3	            [3, 1, 3]	        [1, 2, 3]
            2	        1, 3	            [3]	                [1, 2, 3, 1, 3]
            3	        3	                []	                [1, 2, 3, 1, 3, 3]

            nums is now empty, so the answer is [1, 2, 3, 1, 3, 3].

    Example 2:

        Input: nums = [7,7,4,4,4]

        Output: [4,7,4,7,4]

        Explanation:
            Operation	    Appended to ans	    nums after	    ans after
            1              	4, 7	            [7, 4, 4]	    [4, 7]
            2              	4, 7	            [4]	            [4, 7, 4, 7]
            3              	4	                []	            [4, 7, 4, 7, 4]

            nums is now empty, so the answer is [4, 7, 4, 7, 4].


// Observations:
    - Form the given nums.
        - we will have to get the frequency of every number.
        - once we have frequency of every number:
            - In one go we will insert all number into our answer, and decreasing frequency of every number..
            - the leftover should be consider to the next turn..
            - we will keep doing this until our frequency is not over..


    // Complexity:
        - TC: O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        // Hash Frequency:
        vector<int> freq(101, 0);
        for(auto &i: nums) {
            freq[i]++;
        }

        // Hash element until mp is not empty:
        vector<int> ans;
        while(true) {
            bool isAvl = false;
            for(int i = 1; i <= 100; i++) {
                if(freq[i] > 0) {
                    isAvl = true;
                    ans.push_back(i);
                    freq[i]--;
                }
            }

            if(!isAvl) break;
        }

        return ans;
    }
};