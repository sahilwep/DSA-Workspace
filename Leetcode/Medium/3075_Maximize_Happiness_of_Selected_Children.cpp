/*

//  3075. Maximize Happiness of Selected Children

//  Problem Statement: 
    - You are given an array happiness of length n, and a positive integer k.
    - There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.
    - In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.
    - Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

//  Example:

    Example 1:
        Input: happiness = [1,2,3], k = 2
        Output: 4
        Explanation: We can pick 2 children in the following way:
        - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
        - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
        The sum of the happiness values of the selected children is 3 + 1 = 4.

    Example 2:
=
        Input: happiness = [1,1,1,1], k = 2
        Output: 1
        Explanation: We can pick 2 children in the following way:
        - Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
        - Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
        The sum of the happiness values of the selected children is 1 + 0 = 1.

    Example 3:
        Input: happiness = [2,3,4,5], k = 1
        Output: 5
        Explanation: We can pick 1 child in the following way:
        - Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
        The sum of the happiness values of the selected children is 5.


// Observations:
    - we will have to choose k children, in k turns
        - we will have to select the maximum happiness children at first
        - sums up into our answer.
        - remaining all the childrens decremented by 1
        - for next remaining turn we will do the same as above..
    - at last we will have to return the sum of maximum chosen childrens..


// brute:
    - Implement the given statements:
        - for only 'k' steps:
            - choose maximum & adds up into our answer.
            - remaining will be decremented by 1
        - repeating the turns as we have done above..

    // Complexity:
        - TC: O(k * n)
        - SC: O(1)


// Optimal:
    - sort the given list of childrens.
    - choosing only 'k' childrens starting from maximum
    - maintaining the count of children processed so far, so that in next turn we will decrement it by that count..
    - repeating the steps..

    // Complexity:
        - TC: O(nlogn + k)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimal Solution: 
class Solution {
private:
    int n;
    typedef long long ll;
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        n = happiness.size();

        // Sorting the given happiness in decremented way:
        sort(rbegin(happiness), rend(happiness));

        // Process the logic:
        ll maxSum = 0;
        int cnt = 0;
        int idx = 0;
        while(k--) {
            // Only adding the positive, din't need the neg-additions..
            maxSum += (happiness[idx] - cnt < 0) ? 0 :  happiness[idx] - cnt;

            cnt++;
            idx++;
        }

        return maxSum;
    }
};


// Bruteforce Solution: 
class Solution {
private:
    int n;
    typedef long long ll;
    void decrementRestBy1(vector<int>& happiness, int idxToSkip) {
        for(int i = 0; i < n; i++) {
            if(i == idxToSkip || happiness[i] == 0) continue;
            happiness[i] -= 1;
        }
    }
    int getMaxElementIdx(vector<int>& happiness) {
        int maxIdx = 0;

        for(int i = 1; i < n; i++) {
            if(happiness[i] > happiness[maxIdx]) {
                maxIdx = i;
            }
        }

        return maxIdx;
    }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        n = happiness.size();

        // Process the logic:
        ll maxSum = 0;
        while(k--) {
            // Finding out maxi child:
            int maxId = getMaxElementIdx(happiness);

            // Decrement all without maxId by 1:
            decrementRestBy1(happiness, maxId);

            // Calculating the sum:
            maxSum += (ll)happiness[maxId];

            // reset it with '0', so that we will not consider it for future..
            happiness[maxId] = 0;
        }

        return maxSum;
    }
};