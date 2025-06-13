/*

//  BS-17. Aggressive Cows | Binary Search Hard


// Patterns: 
    -> Binary Search on Answer: min of maximum   or  max of minimum


//  Problem Statement: 
    -> You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.



// Examples:

    Input: stalls[] = [1, 2, 4, 8, 9], k = 3
    Output: 3
    Explanation: The first cow can be placed at stalls[0], 
        the second cow can be placed at stalls[2] and 
        the third cow can be placed at stalls[3]. 
        The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

    Input: stalls[] = [10, 1, 2, 7, 5], k = 3
    Output: 4
    Explanation: The first cow can be placed at stalls[0],
        the second cow can be placed at stalls[1] and
        the third cow can be placed at stalls[4].
        The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

    Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
    Output: 1
    Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
        The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.


// Observations: 
    -> Given k cows
    -> given stalls, stalls[i] is distance of every stalls
    -> assign stalls to k cows such that the minimum distance b/w any two of them is the maximum possible
    
    Input: stalls[] = [1, 2, 4, 8, 9], k = 3    => ans = 3
            index:     0  1  2  3  4
    
            We have to place 3 cows
            stalls[i] is the distance of every cows we can place
            We have to place cows in a way so that, the minimum distance b/w two cows is maximum possible
            
            Case 1: 
                if we place cows on index 0, 1, 2
                maximum distance b/w two cows: 
                                (2 - 1) = 1
                                (2 - 4) = 2
                                        ------
                                        min = 1
                
            Case 2:
                if we place cows on index 0, 2, 3
                                (1 - 4) = 3
                                (4 - 8) = 4
                                        ------
                                        min = 3
            
            Case 3:                     
                if we place cows on index 0, 3, 4
                                (8 - 1) = 3
                                (9 - 8) = 1
                                        ------
                                        min = 1
                
            Case ..
            
                There were other possible too,
                but among all the possibility Case 2, gives the maximum minimum value among all..
                        
        
            One thing we can observe is min value which we can get from every case is what we have to minimize
            In worse case minimum value will be: 0
            Maximum case is last_position - first_position => But we can only place 2 cows with that..
            We are sure that we will have atleast 2 cows to process
                
                maxDiff = lastPos - firstPos
                
                    Range: {0, maxDiff}
            
            We got our answer range, it's just we have to find out for what minimum maximum possible answer range, we can place all the cows.
            Now, To place all the cows:
                -> we have our minimum value with us:
                -> From all the combinations, the minimum will happened b/w cows consecutive distance.
                -> We can place the cows in any configurations.
                        
                        stalls = [1, 2, 4, 8, 9],  k = 3    => ans = 3

                        1           2           4           8           9         Min
                        C1<----1--->C2<----2--->C3                           =>     1
                        C1<----1--->C2<---------6---------->C3               =>     1
                        C1<----------3--------->C2<----4--->C3               =>     3
                        C1<----1--->C2<----------------7--------------->C3   =>     1
                                                                                --------
                                                                                max = 3


                -> We can see that we can place cows with any configurations, 
                -> it's just we have to take minimum distance b/w two adjacent cows for that particular configurations.

            In simple, we have to place cows in such a ways that this minimum distance b/w the cows is maximum

                
        // Placing Cows: 

                arr[] = [1, 2, 4, 8, 9], k = 3    => ans = 3

            -> Since we required the minimum distance b/w two cows
            -> we just need minimum distance b/w consecutive stalls distance, no point to compute farthermost stalls, because that will be big
            -> Calculating the consecutive stalls distance make it work.
            -> First sort the stalls, make it sorted

                            [1,  2,  4,  8,  9]

                Let's try out the cows with minimum distance = 1
                    Where should be place first cow:
                        We can place cow 1 at any place, but
                        Ideal scenario to place first cow is at index '0' first stall, because there is no cow before it & we can greedy place next cows afterwords
                                
                                [1,  2,  4,  8,  9]
                                |
                                C1

                        Next cows: 

                                [1,  2,  4,  8,  9]
                                |   |   |  
                                C1  C2   C3
                        
                        With minimum Distance 1 we can place all the cows.
                
                Let's try out the cows with minimum distance = 2

                        First cow: 

                                [1,  2,  4,  8,  9]
                                |
                                C1

                        Other Cows: 

                                [1,  2,  4,  8,  9]
                                |        |   |  
                                C1       C2   C3

                        With minimum Distance 2 we can place all the cows.
            
            
                
                Let's try out the cows with minimum distance = 3

                        First cow: 

                                [1,  2,  4,  8,  9]
                                |
                                C1

                        Other Cows: 

                                [1,  2,  4,  8,  9]
                                |        |   |  
                                C1       C2   C3

                        With minimum Distance 3 we can place all the cows.
            

                
                Let's try out the cows with minimum distance = 4

                        First cow: 

                                [1,  2,  4,  8,  9]
                                |
                                C1

                        Other Cows: 

                                [1,  2,  4,  8,  9]
                                |            | 
                                C1           C2

                        With minimum Distance 4  we can't place our all the cows, So, answer = 3
                     
        // Solution: 
            -> In this pattern we are finding Binary search on answer:
            -> Answer Range will be {0, maxDist}
                -> maxDist = nums[n-1] - nums[0]

            -> We have to write a function which will check whether we can place given 'k' cows
                -> Because we are checking the minimum distance, we only need two consecutive numbers
                -> So, we can write a logic, which check two consecutive distance
                -> and once the distance satisfies the conditions, we will move forward & change the comparision factor for next possible index.
                -> Start placing first cow at index: '0'
                    cowDist = stall[0];     -> Comparision factor
                    cowCnt = 1;
                -> Now place cows by checking the conditions: 
                    if(stalls[i] - cowDist >= dist) {
                        cowsCnt++;              // increment cows count
                        cowDist = stalls[i];    // Move our update cowDistance
                    }


        // NOTE: Placing First Cow
            -> If we place first cow at index[0]
                -> we can iterate from 1 to n - 1 & comare with given difference


                                bool isValid(vector<int> &stalls, int k, int dist) {
                                    
                                    int cowsCnt = 1;
                                    int cowDist = stalls[0]; // C1 is at 0th starting index
                                    
                                    for(int i = 1; i < n; i++) {
                                        if(stalls[i] - cowDist >= dist) {
                                            cowsCnt++;              // increment cows count
                                            cowDist = stalls[i];    // Move our update cowDistance
                                        }
                                    }
                                    
                                    return (cowsCnt >= k);
                                }

            -> If we place first cow at index[n-1]
                -> we can iterate from n - 2 to 0 & compare with given difference

                                bool isValid(vector<int> &stalls, int k, int dist) {
                                    
                                    int cowsCnt = 1;
                                    int cowDist = stalls[n-1]; // C1 is at last ending index index
                                    
                                    for(int i = n-2; i >= 0; i--) {
                                        if(cowDist - stalls[i] >= dist) {
                                            cowsCnt++;              // increment cows count
                                            cowDist = stalls[i];    // Move our update cowDistance
                                        }
                                    }

                                    return (cowsCnt >= k);
                                }

            
// Complexity: 
    -> TC: O((n * log(n)) + (n * log(max_dist)))
        -> max_dist = nums[n-1] - nums[0]
    -> SC: O(1)
            

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Binary Search Optimal Answer: 
class Solution {
private: 
    int n;
    bool isValid(vector<int> &stalls, int k, int dist) {
        
        int cowsCnt = 1;
        int cowDist = stalls[0]; // C1 is at 0th index
        
        for(int i = 1; i < n; i++) {
            if(stalls[i] - cowDist >= dist) {
                cowsCnt++;              // increment cows count
                cowDist = stalls[i];    // Move our update cowDistance
            }
        }
        
        return (cowsCnt >= k);
    }
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        n = stalls.size();
        
        sort(begin(stalls), end(stalls));
        
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        int ans = 0;
        
        while(low <= high) {    // we need maximum:
            int mid = (low + high) / 2;
            
            // If we got true: Try getting maximum value, move right
            if(isValid(stalls, k, mid)) {
                low = mid + 1;
                ans = mid;      // store maximum answer.
            }
            else {  // we got false, try getting minimum value, move left
                high = mid - 1;
            }
        }
        
        return ans;
    }
};


// Binary Search: TLE because of cows placement function
class Solution {
private: 
    int n;
    bool isValid(vector<int> &stalls, int k, int dist) {    // TC: O(n^2)
        
        int cowsCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stalls[j] - stalls[i] >= dist) {
                    cowsCnt++;
                    i = j - 1;  // move ith pointer
                    break;  // break out our job is done for a cow.
                }
            }
        }
        
        return (cowsCnt >= k-1);
    }
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        n = stalls.size();
        
        sort(begin(stalls), end(stalls));
        
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        int ans = 0;
        
        while(low <= high) {    // we need maximum:
            int mid = (low + high) / 2;
            
            // If we got true: Try getting maximum value, move right
            if(isValid(stalls, k, mid)) {
                low = mid + 1;
                ans = mid;      // store maximum answer.
            }
            else {  // we got false, try getting minimum value, move left
                high = mid - 1;
            }
        }
        
        return ans;
    }
};


// Linear Search: TLE
class Solution {
private: 
    int n;
    bool isValid(vector<int> &stalls, int k, int dist) {
        
        int cowsCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stalls[j] - stalls[i] >= dist) {
                    cowsCnt++;
                    i = j - 1;  // move ith pointer
                    break;  // break out our job is done for a cow.
                }
            }
        }
        
        return (cowsCnt >= k-1);
    }
public:
    int aggressiveCows(vector<int> &stalls, int k) {
        n = stalls.size();
        
        sort(begin(stalls), end(stalls));
        
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        
        for(int i = high; i >= low; i--) {
            if(isValid(stalls, k, i)) return i;
        }
        
        return -1;
    }
};