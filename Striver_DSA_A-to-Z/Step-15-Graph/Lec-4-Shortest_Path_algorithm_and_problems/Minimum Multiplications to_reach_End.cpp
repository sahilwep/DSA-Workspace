/*

//  Minimum Multiplications to reach End


//  Problem Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 1: 
class Solution {
private: 
    int mod = 1e5;
    typedef pair<int, int> pr;
public:
    int minimumMultiplications(vector<int>& nums, int start, int end) {
        int n = nums.size();
        
        vector<int> multiple(mod, false);
        queue<pr> q;
        
        q.push({0, start});
        multiple[start] = 0;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int step = it.first, num = it.second;
            
            if(num == end) return step;
            
            for(auto &it: nums) {
                int newNum = (num * it) % mod;
                if(!multiple[newNum]) {
                    multiple[newNum] = true;
                    q.push({step + 1, newNum});
                }
            }
        }
        
        
        return -1;  // not possible
    }
};

// Approach 2: 
class Solution {
private: 
    int mod = 1e5;
    typedef pair<int, int> pr;
public:
    int minimumMultiplications(vector<int>& nums, int start, int end) {
        int n = nums.size();
        
        vector<int> dist(mod, INT_MAX);
        queue<pr> q;
        
        q.push({0, start});
        dist[start] = 0;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int steps = it.first, num = it.second;
            
            if(num == end) return steps;
            
            for(auto &it: nums) {
                int newStep = (num * it) % mod;
                
                if(steps + 1 < dist[newStep]) {
                    dist[newStep] = steps + 1;
                    q.push({steps + 1, newStep});
                }
            }
        }
        
        
        return -1;  // not possible
    }
};