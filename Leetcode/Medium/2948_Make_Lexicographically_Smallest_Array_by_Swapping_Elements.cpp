/*

//  2948. Make Lexicographically Smallest Array by Swapping Elements


//  Problem Statement: 
    -> You are given a 0-indexed array of positive integers nums and a positive integer limit.
    -> In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.
    -> Return the lexicographically smallest array that can be obtained by performing the operation any number of times.
    -> An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. 
        -> For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.

 
// Example:

    Example 1:
        Input: nums = [1,5,3,9,8], limit = 2
        Output: [1,3,5,8,9]
        Explanation: Apply the operation 2 times:
        - Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
        - Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
        We cannot obtain a lexicographically smaller array by applying any more operations.
        Note that it may be possible to get the same result by doing different operations.

    Example 2:
        Input: nums = [1,7,6,18,2,1], limit = 3
        Output: [1,6,7,18,1,2]
        Explanation: Apply the operation 3 times:
        - Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
        - Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
        - Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
        We cannot obtain a lexicographically smaller array by applying any more operations.

    Example 3:
        Input: nums = [1,7,28,19,10], limit = 3
        Output: [1,7,28,19,10]
        Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.

    

// Observations:
    -> We are given an array & a integer limit.
    -> We need to make this array lexicographically smaller, following this conditions:
        -> In one operations, we can choose two indices i & j, and swap nums[i] & nums[j], if: abs(nums[i] - nums[j]) <= limit.
        
        // What is lexicographically smaller:

            Given nums = [1, 40, 2, 9], let’s compare the elements lexicographically:

                Compare "1" and "40":
                    As strings, "1" comes before "4", so "1" is lexicographically smaller.

                Compare "1" and "2":
                    As strings, "1" comes before "2", so "1" is still smaller.

                Compare "1" and "9":
                    "1" comes before "9", so "1" is still smaller.

                For "40" vs "2":
                    "4" comes after "2", so "40" is lexicographically larger than "2".

                For "40" vs "9":
                    "4" comes before "9", so "40" is lexicographically smaller.

                For "2" vs "9":
                    "2" comes before "9", so "2" is lexicographically smaller.
            
            Result:
                If sorted lexicographically:
                nums = [1, 2, 40, 9]

        // Constrains Observations: 
            -> lexicographically oder can be decide on given constrains:
                -> if: abs(nums[i] - nums[j]) <= limit.


        // Example Observations: 
                nums[] = {10, 2, 7, 3, 8, 4, 9, 6, 3}, limit = 1
                                 
                                 0   1  2  3  4  5  6  7  8     -> Index
                                {10, 2, 7, 3, 8, 4, 9, 6, 3}    -> nums
                            
                        -> Choose idx '0', nums[0] = 10
                            -> Now check in right side whether we have any smaller value or not?
                            -> And also follow the given constrains that: abs(nums[i] - nums[j]) <= limit
                                    {10, 2, 7, 3, 8, 4, 9, 6, 3}
                                     |----->
                                        if we explore on right side, we have '9', which only satisfied the given constrains, so swap it with '9'
                                    {9, 2, 7, 3, 8, 4, 10, 6, 3}
                                     |----->
                                        again we will explore on right side & find the smallest value which follows the constrains..
                                        
                                    {8, 2, 7, 3, 9, 4, 10, 6, 3}
                                     |----->
                                        again we will explore on right side & find the smallest value which follows the constrains..
                                        
                                    {7, 2, 8, 3, 9, 4, 10, 6, 3}
                                     |----->
                                        again we will explore on right side & find the smallest value which follows the constrains..

                                    {6, 2, 8, 3, 9, 4, 10, 7, 3}
                                     |----->
                                        again we will explore on right side & find the smallest value which follows the constrains..

                                NOW, there is nomore smaller numbers, which satisfied the given constrains.
                                So, we will move forward:

                        -> Choose idx '1', nums[1] = 2

                                    {6, 2, 8, 3, 9, 4, 10, 7, 3}
                                        |-----> again we will explore on right side & find the smallest value which follows the constrains..

                                NOW, there is nomore smaller numbers, which satisfied the given constrains.
                                So, we will move forward:


                        -> Choose idx '2', nums[2] = 8

                                    {6, 2, 8, 3, 9, 4, 10, 7, 3}
                                           |-----> again we will explore on right side & find the smallest value which follows the constrains..

                                    {6, 2, 7, 3, 9, 4, 10, 8, 3}
                                           |-----> again we will explore on right side & find the smallest value which follows the constrains..

                                    {6, 2, 7, 3, 9, 4, 10, 8, 3}
                                           |-----> again we will explore on right side & find the smallest value which follows the constrains..
                                    
                                NOW, there is nomore smaller numbers, which satisfied the given constrains.
                                So, we will move forward:
                                     
                        -> Choose idx '3', nums[3] = 3

                                    {6, 2, 7, 3, 9, 4, 10, 8, 3}
                                              |-----> again we will explore on right side & find the smallest value which follows the constrains..
                                    
                                NOW, there is nomore smaller numbers, which satisfied the given constrains.
                                So, we will move forward:

                        -> Same steps we will perform for every index & swap the smallest ones, which were following the given constrains.
                        -> Final array look something like this:

                                    {6, 2, 7, 3, 8, 3, 9, 10, 4}


// BruteForce Solution:
    -> I think it' quite easy to implement the steps that we were doing in observations..
    -> we need to perfrom swapping in nums[i], until we wont' get the the smallest value till the given constrains follows.
    -> This solution gives TLE, because of TC: O(n^3)
    // Complexity: 
        -> TC: 


// Efficient Solution: 
    -> If we analyze the bruteforce solution, Efficient solution will be build on that only..
    -> Let's observe more BruteForce to get Efficient Solution:

                    -> If we Observe the last result that we get
                    -> The values that were are in limit constrains are sorted in order..

                            nums[] = {10, 2, 7, 3, 8, 4, 9, 6, 3}, limit = 1

                            Output = {6, 2, 7, 3, 8, 3, 9, 10, 4}
                                      -  |  -  |  -  |  -   -  |

                                      {6, 7, 8, 9, 10} -> This is the group of values which were having limit difference '1' & somehow they are in sorted order, but only problem is the position, they were in mixed with some other values..
                                      {2, 3, 3, 4} -> This one is another group of sorted value..
                        
                    -> What if we directly sort the values:
                            nums[] = {10, 2, 7, 3, 8, 4, 9, 6, 3}, limit = 1
                                     {2, 3, 3, 4, 6, 7, 8, 9, 10}
                                      ----------  --------------
                                           G1          G1

                                           G1 = {2, 3, 3, 4}
                                           G2 = {6, 7, 8, 9, 10}

                            -> If we sort the given values, & check two adjacent ones (nums[i] & nums[i+1]) or (nums[i-1] & nums[i])
                            -> IF these two values are following the given constrains then assign them in a single group.
                            -> Once, they were not falling in given constrains, we will form another group...
                            -> And finally we will have the groups which were contains the simllar properties of elements..
                            -> Eg: 
                                            2 -> G1    6 - G2
                                            3 -> G1    7 - G2
                                            3 -> G1    8 - G2
                                            4 -> G1    9 - G2
                                                      10 - G2
                                        
                                    -> We can use map to build this...
                            
                            -> Again we need to build the Group of elements: Group<elements>
                            -> This will contains elements in sorted fashion..

                                            G1 = {2, 3, 3, 4}
                                            G2 = {6, 7, 8, 9, 10}
                            
                            -> At last we will iterate in original array & find the nums[i] falling on which group & get the minimum element from that group & assign it there.
                            -> NOTE: 
                                -> We will be needed shortest element which were found in front, if we get the front element & then pop_front(), then it will take O(n) in worse case, which we dont' want..
                                -> We can do this O(1) operations by using Doubly linked list, which will take O(1) in pop_front() operations..
                    
    // Complexity: 
        -> TC: O(n * log(n))
        -> AS: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Step 1: first sort the array: O(n * log(n))
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        // Step 2: find the number which were falling in which groups & Build the groupList which contains all the given element:
        unordered_map<int, int> numToGroup;     // structure: element: group 
        unordered_map<int, list<int>> groupToList;    // structure: group: {elements..}, NOTE: we are using list, because of O(1) for push_back() & pop_front()

        int group = 0;  // initalized group starting with '0'
        numToGroup[vec[0]] = group;     // first element will always be the part of 0th group.
        groupToList[group].push_back(vec[0]);   // push that element into the particular group.

        for(int i = 1; i < n; i++){ // O(n)
            if(abs(vec[i] - vec[i-1]) > limit){ // if given constrains is not begin followed, then change the group number to assign in different group.
                group++;
            }
            numToGroup[vec[i]] = group; // assign that element as the part of the current group.
            groupToList[group].push_back(vec[i]);    // assign that element in that groupNum.
        }

        // Step 3: Build the answer, by iterating in original group:
        vector<int> ans(n);
        for(int i = 0; i < n; i++){ // O(n)
            int num = nums[i];
            int group = numToGroup[num];

            // Get the smallest possible value for this group: 
            ans[i] = *groupToList[group].begin();   // get the front value & it will return iterator, So, we will de-reference it..

            // pop this item from list:
            groupToList[group].pop_front();
        }

        return ans;
    }
};


// BruteForce Solution:
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        for(int i = 0; i < n; i++){ // for every index:
            // get the smallest value to this 'i' which were following the given constrains:
            while(true){
                int smallestValue = nums[i];    // let's treat smallest value is current as nums[i]
                int idx = -1;   // assume index were '-1', because in case we won't able to find the smallest value, we need to exit out from this loop.
                // Now, Search for smallest value in right side of 'i':
                for(int j = i + 1; j < n; j++){
                    // Checking the given constrains:
                    if(abs(nums[j] - nums[i]) <= limit){    // if we found any number nums[j], which were following the constrains:
                        if(nums[j] < smallestValue){    // now, we need to make sure this number nums[j] is the smallest one.
                            smallestValue = nums[j];    // update the smallest number.
                            idx = j;    // update the index also.
                        }
                    }
                }

                // At last, we need to check, are we able to find the smallest value or not?
                if(idx != -1){  // if index is updated, means we found the smallest value:
                    swap(nums[i], nums[idx]);   // swap these two numbers.
                }else{  // else if not found, break out.
                    break;
                }
            }   // NOTE: After we found the smallest number this iteration won't stop, because nums[i] has changed & we need to perform comparision, again & again Until we get the least value at this index which follows the given constrains.
        }


        return nums;    // last return the nums
    }
};