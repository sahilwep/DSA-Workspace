/*

//  3378. Count Connected Components in LCM Graph

//  Problem Statement:
    -> You are given an array of integers nums of size n and a positive integer threshold.
    -> There is a graph consisting of n nodes with the ith node having a value of nums[i]. 
    -> Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
    -> Return the number of connected components in this graph.
    -> A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    -> The term lcm(a, b) denotes the least common multiple of a and b.

 
// Example: 
    Example 1:
        Input: nums = [2,4,8,3,9], threshold = 5
        Output: 4
        Explanation: The four connected components are (2, 4), (3), (8), (9).

    Example 2:
        Input: nums = [2,4,8,3,9,12], threshold = 10
        Output: 2
        Explanation: The two connected components are (2, 3, 4, 8, 9), and (12).


// DSU Approach: 
    // Why DSU? 
        -> We are given graph in multiple components & also to form the graph, we will be needed to join two nodes, & DSU will help us to track the number of components & how many nodes they posses.

    // BruteForce: 
        -> We are given nums & it contains several nodes, which can only be connected if lcm of these two nodes are <= threshold value.
            -> In simple: (lcm(nums[i], nums[j]) <= threshold), then only we can connect two given nodes/elements.
        -> With simple bruteforce, first we can iterate for all possible two nodes groups & check the given constrains, (lcm(nums[i], nums[j]) <= threshold)
            -> If any two nodes/element follows the constrains, we will join them with DSU Union.
            
            // Findin LCM: 
                            LCM = (a * b)/gcd(a,b)

        -> After that we will iterate in nums & trying finding all the ultimate parents of every node, & simply return the total number of components.
        -> Solution is correct, but give TLE (Time limit Exceeds)


    // Time Complexity Optimization:
        -> For every given number if we carefully observe the multiples, we only required till threshold values.
        -> Also, from the given nums list, we only required numbers which are <= threshold value, because above that we won't we needing their multiples anymore..
        // First Optimization: 
            -> Sort the nums value & check nums[i] till threshold value:
            -> Example: 

                    nums = [2, 4, 8, 3, 9], threshold = 5

                    -> In simple, value which are grater than the threshold values we won't be needing...
                    -> So, sort the nums:

                                    |
                    nums = [2, 3, 4,| 8, 9]
                                    |
                                    |
                            Threshold value
                    
                    -> after '4' we won't be needing any number because the first Lowest common multiple start from that number, & that already exceeds the threshold value, which makes no sens to include that..
        
        // Second Optimization: 
            -> Instead of iterating with Complexity O(n^2) in nums to check lcm, we can think in bit more observed way:
            -> Let's understand with an example: 

                        nums = [2, 3, 4, 8, 9], threshold = 5   => nums is sorted

                            multiples before the threshold value, observe them..
                                |
                        2: 2, 4,| 6, 8,.......
                        3: 3, |6, 9, 12,......
                        4: 4, |8, 12, 16,.....
                        8: |8, 16, 24, 32,....
                        9: |9, 18, 27, 36,....
                           |
                           |
                        Threshold value

                    -> we can't include later on multiples of any number which exceeds the threshold value..

            -> As per the question, we need to check the Lowest common multiple from two number which are less than equal to the threshold value:
                    -> Example: 

                        2: 2, 4,| 6, 8,.......
                        4: 4, |8, 12, 16,.....

                    -> For 2 & 4 we have only 1 common multiple which is '4'

                    -> So, we can join [2] & [4] together & from an single graph component.

                            [2]--------[4]

                -> If we check the rest of the nums[i] multiples no one are common withing the threshold bound.
                -> So our final Configuration will be: 
                            
                        [2]-----[4]
                        
                        [3]     [8]

                            [9]

                    -> In total we have 4 components, so that will be our answer.


            -> Let's back to the observations, & think wisely...
            -> Yes, for every nums[i], we will be required their multiples, & also multiples should be less than equal to the threshold bound.

            -> In simple: 

                    -> We Only required the multiples which are less or equal to threshold value
                    
                        multiples before threshold value
                                |
                        2: 2, 4,|
                        3: 3, |
                        4: 4, |
                --------------------- all the bottom numbers we won't be required, because it's exceeds threshold value..
                        8: |
                        9: |

                        
                    -> So, we only need to store the multiples of nums[i] somewhere, 
                    -> and check if it's popping again with another nums[j] multiples, then connect both of them with DSU Union( nums[i], nums[j])
                    -> Yes, Map will help with that...
                                            |  multiples:      nums[i]  |
                                            |---------------------------|
                                    map:    |     2:            2       |
                                            |     4:            2       |-------\_____  These two map keys are same
                                            |     3:            3       |       /
                                            |     4:            4       |------/
                                            |                           |

                            -> Insert multiples as keys and value as nums[i].
                            -> If any multiples already exist -> join these two with union -> (nums[i])

                    -> This will save lot's of time, From O(n^2) => O(n) to connect the valid tow nodes & forming the components..

            -> Concluding: 
                -> Sort the nums
                -> use map to store the multiples till threshold values only.
                -> Connect the nums[i] & nums[j] once we found the multiples already exit..
                -> last check the total number of ultimate parent.


            -> This solution Is Improved, as TC, but still Gives MLE (Memory Limit Exceeded)

        // Final Time & space Optimization:
            -> If We check the constrains: 

                // Constraints:

                        1 <= nums.length <= 10^5
                        1 <= nums[i] <= 10^9
                        All elements of nums are unique.
                        1 <= threshold <= 2 * 10^5

                    -> We are creating DSU of size max_Element of nums[i], which leads to waste of most of the 1e9 size...
                    -> Also we Only processing the union operations limits to threshold value, which is (2 * 1e5)
                    -> Creating (2 * 1e5) size DSU will improve time & space drastically, as we don't need to iterate 1e9 to allocate dsu..

                // Precaution Arises after compressing DSU Size: 
                    -> After we have done everything, when we about to count the total number of components, we need to carefull about two things:
                        -> Make record of how many components are formed during the Union operations
                        -> also filter out those element from nums..

                    // In simple: 
                        -> When we form components, make a record of every connected element/node during Union operations.
                            -> As given elements are unique, we can use unordered set..
                        -> While we are Counting total number of Components:
                            -> First find the total number of components from unordered set which contains the record of Unions.
                            -> Second iterate in nums & filter out those element/node which were processed during the union operations & count rest of them..


// Complexity: 

    // Brute Solution      
        TC = O(n^2 * log(max(nums)))    
        SC = O(max(nums))    	
            Gives  TLE

    // Better Solution
        TC = O((n * log(n)) + (thr * log(thr)))         thr = threshold value
        SC = O(max(nums) + thr)
            Gives MLE

    // Efficient Solution
        TC = O((n * log(n)) + (thr * log(thr))),        thr = threshold value
        SC = O(thr + n)
            Accepted


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_);
        int v = ultPar(v_);

        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

// TIME & SPACE Optimized =>  Accepted
class Solution {
public:
    int countComponents(vector<int>& nums, int thr) {
        int n = nums.size();
        DSU ds(2 * 1e5 + 1);

        sort(begin(nums), end(nums));   // sort the values

        // Connect the Components: 
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(auto &num: nums) {
            if(num > thr) break;
            
            // Find the multiples till threshold point: 
            for(int mul = num; mul <= thr; mul += num) {
                if(mp.count(mul)) {
                    int num2 = mp[mul];
                    ds.Union(num, num2);
                    st.insert(num);
                    st.insert(num2);
                } 
                else {
                    mp[mul] = num;
                }
            }
        }

        // Calculate total number of components:
        int comp = 0;
        for(auto &it: st) {
            cout << it << endl;
            if(ds.ultPar(it) == it) {
                cout << "ultPar: " << it << endl;
                comp++;
            }
        }
        
        for(auto &num: nums) {
            if(!st.count(num)) comp++;
        }

        return comp;
    }
};

// TC Optimized => Gives MLE
class Solution {
public:
    int countComponents(vector<int>& nums, int thr) {
        int n = nums.size();
        // Finding the maximum range for DSU:
        int size = *max_element(begin(nums), end(nums));   // return the address of maximum element from the nums => dereference to get the value.
        DSU ds(size + 1);

        sort(begin(nums), end(nums));   // sorting the nums to compute till threshold value only.

        // Connecting the nodes & forming the components from the given constrains:
        unordered_map<int, int> mp;     // <multiples, nums[i]>
        for(auto &num: nums) {
            if(num > thr) break;    // at any movement element exceeds threshold point -> break out, as there is no use of computing further.
            // Find the multiples till threshold point: 
            for(int mul = num; mul <= thr; mul += num) {
                if(mp.count(mul)) { // Check in map: if it's found connect the components:
                    int num2 = mp[mul];     // get the another element
                    ds.Union(num, num2);    // merge them together
                } 
                else {  // else push that multiple into map.
                    mp[mul] = num;
                }
            }
        }

        // Count total number of components:
        int comp = 0;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) comp++;
        }

        return comp;
    }
};

// BruteForce => Gives TLE
class Solution {
private: 
    typedef long long ll;
    ll lcm(int a, int b) {
        ll res = ll(a) * ll(b);
        res = res / ll(gcd(a, b));
        return res;
    } 
public:
    int countComponents(vector<int>& nums, int thr) {
        int n = nums.size();
        // Finding the maximum range for DSU:
        int size = *max_element(begin(nums), end(nums));   // return the address of maximum element from the nums => dereference to get the value.
        DSU ds(size + 1);

        // Connecting the nodes & forming the components from the given constrains:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = nums[i], b = nums[j];
                if(lcm(a, b) <= ll(thr)) {
                    ds.Union(a, b);
                }
            }
        }

        // Count total number of components:
        int comp = 0;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) comp++;
        }

        return comp;
    }
};