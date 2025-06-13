/*

//  BS-16. Kth Missing Positive Number | Maths + Binary Search

//  Problem Statement: 
    -> Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
    -> Return the kth positive integer that is missing from this array.
    
// Example: 
    Example 1:
        Input: arr = [2,3,4,7,11], k = 5
        Output: 9
        Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

    Example 2:
        Input: arr = [1,2,3,4], k = 2
        Output: 6
        Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

//  Observations: 
    -> Given increasing array of positive integer
    -> Find out the kth missing number
    
        arr[] = [2 3 4 7 11]
        
        
                arr[] = [2 3 4 7 11], k = 5
                         |
                        (2 < k) This 2 will take 1 place, So find for k = 6

                arr[] = [2 3 4 7 11], k = 6
                           |
                        (3 < k) This 3 will take 1 place, So find for k = 7

                arr[] = [2 3 4 7 11], k = 7
                             |
                        (4 < k) This 4 will take 1 place, So find for k = 8
                        
                arr[] = [2 3 4 7 11], k = 8
                               |
                        (7 < k) This 7 will take 1 place, So find for k = 9

                arr[] = [2 3 4 7 11], k = 9
                                 |
                        (11 > k) This means we 'k' lies before this '11'
                        Stop here: 
                            
                        k = 9 is our answer

                Check: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
                       |           |  |     |  |
                      1st         2nd 3rd  4th 5th  -> missing number


                      '9' is our missing number: 
             
        -> Approach: 
            Iterate in nums: 
                if(nums[i] <= k) k++    // increment kth position
                else break;

            return 'k' as our answer.
    

        // Optimizations: 
            -> we Have sorted array
            -> we can use Binary search with modification to get our answer.
            
            // Approach: 
                -> If somehow we configure out the two nearby indices, we can find kth position.
                -> Example: 

                    arr[] = [2 3 4 7 11], k = 5

                    Check: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
                        |           |  |     |  | 
                        1st         2nd 3rd  4th 5th  -> missing number


                    -> for this range [7, 11] If we somehow we can get these smaller range of indexes, we can figure out our answer.
                    -> Try figure out two nearby indices.

                -> Now how do we figure out these two nearby indices

                    ind ->   0  1  2  3  4
                    arr[] = [2  3  4  7 11]

                        -> Using 'k' we can try find out the smaller range
                        -> Ideally the number should have been in this array if non-of the number is missing out:

                                ind ->   0  1  2  3  4
                                arr[] = [1, 2, 3, 4, 5]


                        -> But we have 
                                ind ->   0  1  2  3  4
                                arr[] = [2  3  4  7 11]
                                ideally  1  2  3  4  5
                                                  |
                                            here we have '7', ideally it should have '4'    =>  7 - 4
                                            So, can we say 3 number is missing

                                    
                                            for '11', ideally it should have '5'        =>  11 - 5
                                            so, we can say 6 number is missing

                                            Missing_Number: nums[i] - idealNumber
                        
                        -> Missing number of for every index: 

                                ind ->   0  1  2  3  4
                                arr[] = [2, 3, 4, 7, 11]
                                         |  |  |  |  |
                                         1  1  1  3  6  -> Missing numbers
                                                     |
                                                     kth lies b/w these

                                So, we can surely say 'k' lies b/w '4' & '6'

                        -> So, we can figure out our smaller range: 
                            
                                ind ->   0  1  2  3  4
                                arr[] = [2, 3, 4, 7, 11]
                                         |  |  |  |  |
                                         1  1  1  3  6  -> Missing numbers
                                         |           |
                                         low        high

                                    
                                    We will try out binary search in this range & try finding out our missing number smaller range


                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |   |   |
                                            1   1  1   3   6  -> Missing numbers
                                            |      |       |
                                            low    |       high
                                                   | 
                                                  mid

                                                   k > mid => move right


                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |   |   |
                                            1   1  1   3   6  -> Missing numbers
                                                       |    |
                                                      low  high
                                                       |
                                                      mid
                                                    
                                                    k > mid => move right


                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |   |   |
                                            1   1  1   3   6  -> Missing numbers
                                                           |
                                                        low high
                                                           |
                                                         mid
                                                    
                                                    k < mid => move left


                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |   |   |
                                            1   1  1   3   6  -> Missing numbers
                                                       |   |
                                                      high low

                                                       break out, as conditions violates: (low <= high)
                                                    
                                                    
                        -> Initially: low = 0 & high = n-1, 

                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |  |   |
                                            1   1  1  3   6  -> Missing numbers
                                            |             |
                                          low            high

                        -> Currently: low = n-1 & high = n-2

                                    arr[] = [2, 3, 4, 7, 11]
                                            |   |  |   |   |
                                            1   1  1   3   6  -> Missing numbers
                                                       |   |
                                                      high low
                
                -> We have found our smaller range:
                -> Now, next job is to find the number.

                        arr[high] = 7       missing = 3         more = 2
                            |
                        next = 8
                            |
                        next = 9, This is our answer, as we have to move more '2'

                        So, 
                                ans = arr[high] + more
                        
                
                -> Edge case: 
                        nums = [4, 7, 9],  k = 3
                        
                                [4, 7, 9]
                            |    |
                          high  low

                          3rd missing number is somewhere before '4'


                -> let's Find out "more"

                                idx ->   0  1  2  3  4
                                arr[] = [2, 3, 4, 7, 11]
                                         |  |  |  |  |
                                         1  1  1  3  6  -> Missing numbers
                                                  |   |
                                                high low
                                                

                        arr[high] = 7       missing = 3         more = 2 
                                                 |
                                        arr[high_idx] - (high_idx + 1)

                                        more = k - missing  => 5 - 3 = 2

                                    ans = arr[high] + more
                                          arr[high] + k - missing
                                          arr[high] + k - (arr[high] - (high + 1))
                                          arr[high] + k - (arr[high] - high - 1)
                                          arr[high] + k - arr[high] + high + 1
                                    ans = k + high + 1


                            Formula: ans = high + 1 + k

                    OR: we also know low = high + 1 => high = low - 1
                                    ans = high + 1 + k
                                    ans = low - 1 + 1 + k
                                    ans = low + k

                            
                        Formula For answer: 
                                            ans = low + k
                                            ans = high + 1 + k


// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Binary Search: 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;        // starting range
        int high = n - 1;   // ending range
        
        while(low <= high) {
            int mid = (low + high) / 2;

            int missing = arr[mid] - (mid + 1);     // this will be our missing number

            // if missing number is less that the given 'k' => move right side
            if(missing < k) {
                low = mid + 1;
            } 
            else {  // move left side
                high = mid - 1;
            }
        }

        // Return ans:
        return k + high + 1;
        // return low + k;  // or return this one.
    }
};

// BruteForce: 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for(auto& num: arr) {
            if(num <= k) k++;
            else break;
        }

        return k;
    }
};

// Super BruteForce Solution: 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int sz = *max_element(begin(arr), end(arr)) + k;    // In worse case, size will be maximum element + K
        vector<bool> check(sz, 0);
        for(auto& i: arr) {
            check[i] = 1;
        }

        for(int i = 1; i <= sz; i++) {
            if(check[i] == 1) continue;
            if(k == 1) return i;
            k--;
        }

        return -1;
    }
};