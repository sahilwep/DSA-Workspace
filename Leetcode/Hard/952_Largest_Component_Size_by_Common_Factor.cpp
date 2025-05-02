/*

//  952. Largest Component Size by Common Factor


//  Problem Statement: 
    -> You are given an integer array of unique positive integers nums. Consider the following graph:
        -> There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
        -> There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
    -> Return the size of the largest connected component in the graph.


// Example: 
    Example 1:
        Input: nums = [4,6,15,35]
        Output: 4

    Example 2:
        Input: nums = [20,50,9,63]
        Output: 2

    Example 3:
        Input: nums = [2,3,6,7,4,12,21,39]
        Output: 8


//  Observations: 
    -> we need to return largest component 
    -> Connect the nums[i] whose factors are common with any nums[j]
    -> Last count get the largest sized component.

    // DSU Approach: 
        -> Connectivity of nodes depends upon their factors.
        -> find the largest components formed by nums[i]
        -> Find prime factorization of every number & hash their value in map & whenever it occurred again -> Union them...

        // Complexity: 
            -> TC: O(n * sqrt(maxNum)) + O(n * α(maxNum)) ≈ O(n * sqrt(maxNum))
            -> SC: O(maxElement)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> size, parent;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

// Improved with Prime-factorization: Accepted
class Solution {
private:
    typedef long long ll;
    vector<int> getPrimeFactors(int n) {    // function to find prime factorization:
        vector<int> factors;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);        // i is a prime factor
                while (n % i == 0) n /= i;   // remove all multiples of i
            }
        }
        if (n > 1) factors.push_back(n);     // n itself is prime
        return factors;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(begin(nums), end(nums));  // get the maximum value from the nums.

        DSU ds(maxNum); // declare DSU with maxNum size.
        unordered_map<int, int> mp; // <factor[i], val>
        for(auto &num: nums) {
            vector<int> factor = getPrimeFactors(num);
            // Iterate in factor & store in map:
            for(auto &it: factor) {
                if(mp.count(it)) {   // if already exist:
                    ds.Union(num, mp[it]);  // merge the components:
                } 
                else {  // else not in map:
                    mp[it] = num;   // hash it with the current num
                }
            }
        }

        int compSize = 1;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) {
                compSize = max(compSize, ds.getSize(it));
            }
        }

        return compSize;
    }
};


// Improved BruteForce: TLE
class DSU {
private: 
    vector<int> size, parent;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
private:
    typedef long long ll;
    vector<int> getFactor(int x) {
        vector<int> ans;
        for(int i = 2; i <= x; i++) {
            if(x % i == 0) ans.push_back(i);
        }

        return ans;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(begin(nums), end(nums));  // get the maximum value from the nums.

        DSU ds(maxNum); // declare DSU with maxNum size.
        unordered_map<int, int> mp; // <factor[i], val>
        for(auto &num: nums) {
            vector<int> factor = getFactor(num);
            // Iterate in factor & store in map:
            for(auto &it: factor) {
                if(mp.count(it)) {   // if already exist:
                    ds.Union(num, mp[it]);  // merge the components:
                } 
                else {  // else not in map:
                    mp[it] = num;   // hash it with the current num
                }
            }
        }

        int compSize = 1;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) {
                compSize = max(compSize, ds.getSize(it));
            }
        }

        return compSize;
    }
};



// BruteForce: TLE
class DSU {
private: 
    vector<int> size, parent;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
private:
    typedef long long ll;
public:
    int largestComponentSize(vector<int>&q nums) {
        int n = nums.size();
        DSU ds(1e5);

        // Connectivity: 
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n ;j++) {
                // Check gcd grater than 1:
                if(gcd(nums[i], nums[j]) > 1) {
                    // merge them
                    ds.Union(nums[i], nums[j]);
                }
            }
        }

        int compSize = 1;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) {
                compSize = max(compSize, ds.getSize(it));
            }
        }

        return compSize;
    }
};
