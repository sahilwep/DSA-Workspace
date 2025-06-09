
/*

//  875. Koko Eating Bananas


//  Problem Statement:
    -> Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
    -> Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
    -> If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
    -> Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    -> Return the minimum integer k such that she can eat all the bananas within h hours.


//  Example: 

    Example 1:
        Input: piles = [3,6,7,11], h = 8
        Output: 4

    Example 2:
        Input: piles = [30,11,23,4,20], h = 5
        Output: 30

    Example 3:
        Input: piles = [30,11,23,4,20], h = 6
        Output: 23


// Observations: 
    -> we are given h hours, which is the time frame to finish all the banana
    -> we have to find the minimum speed 'k' for which koko can finish all the banana from the piles.
        -> if piles[i] < k => it will take whole 1 hours
        -> else it will take that much hours to finish

    -> Key Observations: 
        -> minimum value for which we can start is '1'
            -> 1 banana per hours
        -> and maxValue which we can go is up till max_element(piles)
            -> maximum element from piles
        
        -> from this range (1 --- max_element(piles))
            -> We can try checking everytime whether koko can finish all banana or not?
            -> We have to return the first value iteration from (1 to max_element(piles)) for which our koko can return "true" that yes he finishes all the banana.
    
        // Optimization: 
            -> For the linear range (1 --- max_element(piles)) we can use Binary_Search() for the minimum value it can return true.

        
    // Complexity: 
        -> TC: O(N * Log(MaxE​lement(Piles)))
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: Binary Search
class Solution {
private: 
    typedef long long ll;
    // Function to check wether koko can finish eating all banana or not?
    bool canFinish(vector<int>& piles, int h, int perHr) {
        ll ttlHr = 0;   // total hour for every call
        for(auto& it: piles) {
            if(it % perHr != 0) {
                ttlHr += it / perHr + 1;
            } else {
                ttlHr += it / perHr;
            }
        }

        return (ttlHr <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxEl = *max_element(begin(piles), end(piles));  // get the maximum element
        // Try checking per hour from 1 to given max_element(piles)
        
        // Binary Search: 
        int low = 1;
        int high = maxEl;
        int ans;
        while(low <= high) {
            int mid = (low + high) / 2;

            // if we get our answer true: move left for smaller values possible
            if(canFinish(piles, h, mid)) {
                ans = mid;  // set answer
                high = mid - 1; // move left
            } 
            else {  // if answer is false, move right for correct answer
                low = mid + 1;  // move right
            }
        }

        return ans;
    }
};

// BruteForce Solution: Linear Search
class Solution {
private: 
    typedef long long ll;
    // Function to check wether koko can finish eating all banana or not?
    bool canFinish(vector<int>& piles, int h, int perHr) {
        ll ttlHr = 0;
        for(auto& it: piles) {
            if(it % perHr != 0) {
                ttlHr += it / perHr + 1;
            } else {
                ttlHr += it / perHr;
            }
        }

        return (ttlHr <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxEl = *max_element(begin(piles), end(piles));  // get the maximum element

        // Try checking per hour from 1 to given max_element(piles)
        for(int i = 1; i <= maxEl; i++) {
            if(canFinish(piles, h, i)) return i;
        }

        return 0;
    }
};