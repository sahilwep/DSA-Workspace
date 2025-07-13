/*

//  765. Couples Holding Hands


//  Problem Statement: 
    -> There are n couples sitting in 2n seats arranged in a row and want to hold hands.
    -> The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. 
    -> The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
    -> Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.


// Example: 
    Example 1:
        Input: row = [0,2,1,3]
        Output: 1
        Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

    Example 2:
        Input: row = [3,2,0,1]
        Output: 0
        Explanation: All couples are already seated side by side.

        
// Observations: 
    -> We are given n couples in 2n seats arranged in row
    -> We need to check wether the couples are in correct order or not?
        -> Order Defined as: 
            (0, 1), (2, 3), (4, 5).....(2*n - 2, 2*n - 1)
        -> We need to find minimum number of swaps, so that we can arrange all in order.


// Approach 1: Hashing & odd-Even logic: 
    -> If we observe the question carefully: 
        (0, 1), (2, 3), (4, 5).....(2*n - 2, 2*n - 1)
    
    -> for any odd number => we required even 
            [3,2,0,1]
             |
             3 => required even which is "2", which is also 1 lesser than the original number.

    -> for any even number => we required odd

            [3,2,0,1]
                 |
                 0 => required odd which is "1", which is also 1 greater than the original number.


    -> from this observations we can track what we need.
    -> Now we only need to know where is the required number or couple & on which index it's located, so that we can swap.
        -> Solution: 
            -> Bruteforce is iterate in all index & find locations & swap.
            -> efficiently: we can Hash all the nums[i] into map with respect to their indexes.
                -> This will help us to query every needed number in O(1) & we can swap their position in map also

    -> Concluding: 
        -> First hash all the nums[i] into map with respect to their index
        -> Iterate in given row: 
            -> fetch (row[i] & row[i+1])
                -> now check the odd-Even conditions for row[i] whether row[i+1] is valid or not?
                -> If they mismatched: 
                    -> Find the values into map, & swap position in map & originally in row.
        
    

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N)

// Approach 2: DSU
    // You might be wondering why DSU & how will it help?
        -> let's observe with Two example: 
        -> NOTE: Remember th odd even conditions for the every pair(

            // Example 1: All the couples sits on correct position.

                row[] = {0, 1, 3, 2, 5, 4, 7, 6}
                         ----  ----  ----  ----
                          G1    G2    G3    G4
            
                -> There are total 4 groups & each group has 2 element.

                    For every two pairs: (number / 2) => gives group number
                    
                        (0, 1)

                            (0/2, 1/2) => (0, 0) => both are from same group   => No merger, because both the element lies within the same group.

                        (3, 2)

                            (3/2, 2/2) => (1, 1) => both are from same group   => No merger, because both the element lies within the same group.

                        (5, 4)

                            (5/2, 4/2) => (2, 2) => both are from same group   => No merger, because both the element lies within the same group.

                        (7, 6)

                            (7/2, 6/2) => (3, 3) => both are from same group   => No merger, because both the element lies within the same group.


            // Example 2: Few elements are not at correct position.

                row[] = {0, 2, 1, 3, 5, 4, 7, 6}
                         ----  ----  ----  ----
                          G1    G2    G3    G4
           
                -> For this problem there should be total 4 groups.                
                -> Now let's check are these group in correct order or not?

                        (0, 2)

                            (0/2, 2/2) => (0, 1) => Both are from different groups  => Group merger happens

                                            [0]
                                              \
                                               \        SwapCnt++;
                                                [1]

                        (1, 3)

                            (1/2, 3/2) => (0, 1) => Both are from different groups => But already merge.
                                        => Nothing happens

                        (5, 4)
                            
                            (5/2, 4/2) => (2, 2) => same groups, nothing will happens

                        (7, 6)

                            (7/2, 6/2) => (3, 3) => Same groups, nothing will happens

        -> From both these example you can see how union help in merger..
        -> and track swap count.

        // Concision: 
            -> get the pairs: 
                -> (divide it by/ 2) => This will give us group number.
                -> once we have group number, we can check are they both belongs to same component or not?
                -> If so, skip that, else we can perfrom Union() operations & count the swaps
                -> Note: for every new unmatched pairs we will perfrom one swap count.


    // Complexity: 
        -> TC: O(n)
        -> SC: O(n)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 2: DSU
class DSU {
private: 
    vector<int> parent, size;
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
    bool Union(int u_, int v_) {    // modified Union to return if nodes are already joint or not?
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return false;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU ds(n);  // at max we can have n components.

        int swapCnt = 0;
        for(int i = 0; i < n; i += 2) { // O(n)
            int u = row[i] / 2, v = row[i + 1] / 2;
            if(ds.Union(u, v)) {    // if union return true:
                swapCnt++;     // merging happened, count swapping...
            }
        }

        return swapCnt;
    }
};


// Approach 1: hashing & index count
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();

        // Hash all the element with their index:
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[row[i]] = i;
        }

        // Step 2: Now fetch the value & if it's not at their correct position => swap it..
        int swapCnt = 0;
        for(int i = 0; i < n; i += 2) {
            int first = row[i];
            int requiredSecond = first ^ 1; // if first is odd it will subtract 1: else add 1

            // Check adjacent element: 
            if(row[i + 1] != requiredSecond) {
                swapCnt++;  // count the swapped value.

                // Swap Position in map:
                int wrongIdx = mp[requiredSecond];
                mp[row[i + 1]] = wrongIdx;  
                mp[requiredSecond] = i + 1; // hash second element with adjacent next index.

                // Now swap the values: 
                swap(row[i + 1], row[wrongIdx]);
            }
        }

        return swapCnt;
    }
};