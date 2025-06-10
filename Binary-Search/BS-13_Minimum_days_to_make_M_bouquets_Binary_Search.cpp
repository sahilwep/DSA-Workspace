/*

//  BS-13. Minimum days to make M bouquets | Binary Search


//  Problem Statement: 
    -> You are given an integer array bloomDay, an integer m and an integer k.
    -> You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
    -> The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
    -> Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 
// Example: 
    Example 1:
        Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
        Output: 3
        Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
        We need 3 bouquets each should contain 1 flower.
        After day 1: [x, _, _, _, _]   // we can only make one bouquet.
        After day 2: [x, _, _, _, x]   // we can only make two bouquets.
        After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

    Example 2:
        Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
        Output: -1
        Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

    Example 3:
        Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
        Output: 12
        Explanation: We need 2 bouquets each should have 3 flowers.
        Here is the garden after the 7 and 12 days:
        After day 7: [x, x, x, x, _, x, x]
        We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
        After day 12: [x, x, x, x, x, x, x]
        It is obvious that we can make two bouquets in different ways.


// Observations: 
    -> We are given an array bloomDay of size n, which contains the bloom day of every flower.
        -> ith flower blooming on bloomDay[i]th day
    -> we are given integer m, means we are required m bouquet
    -> to make each bouquet, we required exactly 'k' flowers.
    
    // Solution: 
        ->  First, we have write a function which will check weather for given day, wether it can able to make required bouquet or not?
            -> n & m, if observe more carefully 
            -> to make a flower we need m flower in adjacent to each other, then only we can make a flower.

        -> range: 
            -> Starting range: 1, that's the day on which we can start
            -> Ending range: max_element(bloomDay[]), which is the last day on which every flower is bloomed in worse case
        -> Now we can start with the range & find the minimum day on which our function can successfully make bouquets.

        
        // Optimizations: 
            -> Binary search can be used to find the minimum blooming day
        

    // Complexity: 
        -> TC: O(log(max_element(bloomDay)) * N)
            -> N = size of bloomDay
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized: Binary Search
class Solution {
private: 
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();

        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= day) cnt++;
            else {
                ans += cnt / k; // add total previous count into our answer
                cnt = 0;        // reset counter
            }
            if(ans >= m) return true;   // early return, if conditions satisfies.
        }
        ans += cnt / k;     // add remaining

        return (ans >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = 1;
        int high = *max_element(begin(bloomDay), end(bloomDay));
        int ans = INT_MAX;

        while(low <= high) {
            int mid = (low + high) / 2;

            // If we get true: try for lower value, move left
            if(isPossible(bloomDay, m, k, mid))  {
                high = mid - 1;
                ans = mid;  // store answer
            } 
            else {  // for the false case: move right side to get higher value
                low = mid + 1;
            }   
        }

        // If Infinity value remains, we won't able to find such day:
        return (ans == INT_MAX) ? -1 :  ans;
    }
};


// BruteForce: Linear Search
class Solution {
private: 
    bool isPossible(vector<int>& bloomDay, int m, int k, int day) {
        int n = bloomDay.size();

        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= day) cnt++;
            else {
                ans += cnt / k; // add total previous count into our answer
                cnt = 0;        // reset counter
            }
            if(ans >= m) return true;   // early return, if conditions satisfies.
        }
        ans += cnt / k;     // add remaining

        return (ans >= m);
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = 1;
        int high = *max_element(begin(bloomDay), end(bloomDay));

        for(int i = low; i <= high; i++) {
            if(isPossible(bloomDay, m, k, i)) return i;
        }

        return -1;
    }
};