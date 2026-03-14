/*

//  Most Frequent Element in an Array


//  Problem Statement: 
    - You are given an integer array arr[]. You need to return the element which occurs maximum times in arr[].
    - Note: If multiple such elements exists return the maximum element.

// Example: 

    Input: arr[] = [1, 2, 2, 2, 4, 1]
    Output: 2
    Explanation: 2 is most frequent element of this array with 3 occurrences.

    Input: arr[] = [1, -5, 8, 1]
    Output: 1
    Explanation: 1 is most frequent element of this array with 2 occurrences.

    Input: arr[] = [3, 0, 0, 3, 8]
    Output: 3
    Explanation: 0 and 3 are two most frequent elements of this array. 3 is the maximum one.

// Approach:
    - Use Unordered_map & filter out most-frequent element.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        for(auto &it: arr) mp[it]++;
        
        int ans = arr[0];
        int maxFreq = 0;
        for(auto &i: mp) {
            int num = i.first;
            int freq = i.second;
            
            if(freq > maxFreq) {
                ans = num;
                maxFreq = freq;
            }
        }
        
        return ans;
    }
};