/*

// 136. Single Number

// Observations: 
    * we are given an array, & we have to find the element that appear only once.


// Intrusion: 
    * We will use hashing approach: 
        * We can use any map, or unordered_map to store frequency, & return the value that single frequency.
    * TC: O(n)
    * AS: O(n)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i : nums) mp[i]++;

        int sElement;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second == 1){
                sElement = i->first;
                break;
            }
        }
        return sElement;
    }
};