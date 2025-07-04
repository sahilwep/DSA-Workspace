/*

//  347. Top K Frequent Elements 

//  Problem Statement: 
    -> Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 

// Example: 

    Example 1:
        Input: nums = [1,1,1,2,2,3], k = 2
        Output: [1,2]

    Example 2:
        Input: nums = [1], k = 1
        Output: [1]



// Observations: 
    -> First store the frequency of every element
    -> Then return top k frequent occurring element.


// BruteForce: 
    -> Hash the given list
    -> for every kth iterations find the maximum element from map:
        -> erase that element from map.
        -> store that element into our answer.

    // Complexity: 
        -> TC: O(n * K)
        -> SC: O(n)


// Better: 
    -> Sort the given array in decreasing order.
    -> Store the frequency in vector in <freq: element> order
    -> sort the frequency in decreasing order.
    -> store the first top k element from frequency list.

    // Complexity: 
        -> TC: O(n * log N)
        -> SC: O(n)



// Better 2: max-heap
    -> Hash the given array.
    -> Push all the <frequency: element> into max heap
    -> return the top k element from heap.

    // Complexity: 
        -> TC: O(n * log N)
        -> SC: O(n)


// Efficient: 
    -> Hash the given array.
    -> Push all the <freq: element> into min heap
    -> if we get over to top 'k' pop-all the element from heap, while heap size is not lesser or equal to 'k'
        -> This way we can pop all the lesser frequency element
        -> We will left with only k-most occurring element into heap.

    
    // Complexity: 
        -> TC: O(n * logK)
        -> SC: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Using min-heap: TC: O(n * logK)
class Solution {
private: 
    typedef pair<int, int> pr;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Hash the values:
        unordered_map<int, int> mp;
        for(auto &num: nums) {  // TC: O(n)
            mp[num]++;
        }

        // Store all the element in min-heap
        priority_queue<pr, vector<pr>, greater<>> pq;
        for(auto &[element, freq]: mp) {    // TC: O(n * log K)
            pq.push({freq, element});
            while(pq.size() > k) {  // only store top k-elements.
                pq.pop();
            }
        }

        // Return the top k-frequent element from heap.
        vector<int> ans;
        while(!pq.empty()) {    // TC: O(k)
            auto [freq, element] = pq.top();
            pq.pop();

            ans.push_back(element);
        }

        return ans;
    }
};


// Better with Heap: TC: O(n * logN)
class Solution {
private: 
    typedef pair<int, int> pr;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Hash the values:
        unordered_map<int, int> mp;
        for(auto &num: nums) {  // TC: O(n)
            mp[num]++;
        }

        // Store all the element in max-heap
        priority_queue<pr> pq;
        for(auto &[element, freq]: mp) {    // TC: O(n * log N)
            pq.push({freq, element});
        }

        // Return the top k-frequent element from heap.
        vector<int> ans;
        while(k--) {    // TC: O(k)
            auto [freq, element] = pq.top();
            pq.pop();

            ans.push_back(element);
        }

        return ans;
    }
};


// Better: Sorting => TC: O(n * log N)
class Solution {
private: 
    typedef pair<int, int> pr;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));   // sort the given array => TC: O(n * log N)

        // Hash all the element into frequency vector:
        vector<pair<int, int>> freq;
        int cnt = 1;
        for(int i = 1; i < n; i++) {    // TC: O(n)
            if(nums[i - 1] == nums[i]) {
                cnt++;
            } else {
                freq.push_back({cnt, nums[i-1]}); // store <freq: element>
                cnt = 1;
            }
        }

        freq.push_back({cnt, nums[n-1]});   // push last frequency count element.
        

        // sort the frequency vector in decreasing order:
        sort(rbegin(freq), rend(freq)); // TC: O(n * log N)


        // Build Result: 
        vector<int> ans;
        int i = 0;
        while(k--) {    // TC: O(k)
            auto [frequency, num] = freq[i++];
            ans.push_back(num);
        }

        return ans;
    }
};


// BruteForce Solution: TC: O(n * k)
class Solution {
private: 
    typedef pair<int, int> pr;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Store frequency of every element => TC: O(n)
        unordered_map<int, int> mp;
        for(auto &num: nums) {
            mp[num]++;
        }

        // Build Result => TC: O(n * k)
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            // Find maximum element in every kth iterations: 
            int maxEle = -1;
            int maxFreq = INT_MIN;
            for(auto &[element, freq]: mp) {
                if(freq > maxFreq) {
                    maxFreq = freq;
                    maxEle = element;
                }
            }

            // Store result & erase that element from map
            ans.push_back(maxEle);
            mp.erase(maxEle);
        }

        return ans;
    }
};