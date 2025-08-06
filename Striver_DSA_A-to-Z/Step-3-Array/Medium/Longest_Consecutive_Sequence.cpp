/*

//  128. Longest Consecutive Sequence

//  Problem Statement: 
    -> Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    -> You must write an algorithm that runs in O(n) time.


//  Example: 

    Example 1:
        Input: nums = [100,4,200,1,3,2]
        Output: 4
        Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

    Example 2:
        Input: nums = [0,3,7,2,5,8,4,6,0,1]
        Output: 9

    Example 3:
        Input: nums = [1,0,1,2]
        Output: 3



// Observations: 
    -> Given nums, We need to find the longest consecutive element in sequence.


    // BruteForce Approach: 
        -> for every element find the longest growing number available in list
        -> return answer.

        // Complexity: 
            -> TC: O(n^2)
            -> SC: O(1)


    // Better Solution: Sorting
        -> Sorting will make all the elements in sequence.
        -> Example: 

                1 1 1 2 3 4 5 5 6 6 7 100 101 101 102
            
            -> We will maintain one lastSmaller number which will hold the informations of lastSmaller number
            -> We will maintain one counter which will count the increasing sequence numbers.
            -> Whenever we get the increasing sequence -> increase the counter & update the lastSmaller
            -> Whenever we got same element => do noting
            -> Whenever we got different sequence: eg. 7 100 101
                -> Change the counter = 1 & update lastSmaller as 100, current_nums[i]

            // Complexity: 
                -> TC: O(n * logn)
                -> SC: O(1)

    // Efficient: 
        -> Put everything into unordered set-data structure -> query will take O(1)
        -> Pick every element & check their previous element
            -> If any element has no previous element, means that number is the starting sequence of our number
            -> Example: 

                        [1] 2 3 4 5       [100] 101 102     [401] 402 403

        -> While Iterating in set, we will only pick the number which has no element before it.
        -> In other words it's the starting number of the sequence.
        -> Whenever we got such element which is starting of sequence, find the longest growing range in set & return answer.

        // Complexity: 
            -> TC: O(n)
            -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Hash the nums[i] into set
        unordered_set<int> st;
        for(auto& it: nums) {
            st.insert(it);
        }

        int longest = 0;
        for(auto& it: st) {
            if(!st.count(it-1)) {   // starting range of number:
                int cnt = 0;
                int num = it;
                while(st.count(num)) {
                    num += 1;
                    cnt++;
                }

                // Store the longest sequence:
                longest = max(longest, cnt);
            }
            // else skip all the numbers 
        }


        return longest;
    }
};


// Better: Sorting: 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // Edge case: 
        if(n == 0) return 0;

        // Sort the given elements: 
        sort(begin(nums), end(nums));

        int cnt = 0;
        int lastSmaller = INT_MIN;
        int longest = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 == lastSmaller) { // if we got sequence number: increment the counter & update last smaller.
                cnt++;
                lastSmaller = nums[i];
            } else if(nums[i] != lastSmaller) {  // when we get the different sequence: change the count & order
                cnt = 1;
                lastSmaller = nums[i];
            } else {
                // do-nothing for same element: (arr[i] == lastSmaller)
            }

            longest = max(longest, cnt);
        }


        return longest;
    }
};


// BruteForce using set: TC: O(n^2)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        

        unordered_set<int> st;
        for(auto& it: nums) {
            st.insert(it);
        }

        int ans = 0;
        for(auto& it: nums) {
            int num = it;
            int cnt = 0;
            while(st.count(num)) {
                cnt++;
                num += 1;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};


// BruteForce: TC: O(n^2)
class Solution {
private: 
    bool isAvl(vector<int>& nums, int target) {
        for(auto& it: nums) if(it == target) return true;
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 0;
        for(auto& it: nums) {
            int num = it;
            int cnt = 0;
            while(isAvl(nums, num)) {
                cnt++;
                num += 1;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};