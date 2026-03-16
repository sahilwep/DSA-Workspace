/*

//  839. Similar String Groups


//  Problem Statement: 
    - Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
    - For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
    - Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
    - We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 
// Example:
    Example 1:
        Input: strs = ["tars","rats","arts","star"]
        Output: 2

    Example 2:
        Input: strs = ["omv","ovm"]
        Output: 1

 

// Constraints:
    1 <= strs.length <= 300
    1 <= strs[i].length <= 300
    strs[i] consists of lowercase letters only.
    All words in strs have the same length and are anagrams of each other.


// Observations:
    - Given list of strings
    - We are allowed to modify only two index at max:
    - and we can compare it with other string:
    - for every two strings:
        - if they have less or equal two distinct characters, we can swap & make them identical.
        - We After making them identical we can place in that a cluster of same string.
    - last we can return the total number groups/clusters.


    // Visualizations:
            Example 1:
                Input: strs = ["tars","rats","arts","star"]
                Output: 2

                    "tars":
                                t a r s     t a r s     t a r s
                                r a t s     a r t s     s t a r
                                |   |       | | |       | | | |
                                 OK
                                        Matched with "rats"

                                Groups: {{"tars", "rats"}}
                    
                    "rats":
                                r a t s     r a t s
                                a r t s     s t a r
                                | |         | | | |
                                OK
                                        Matched with "arts"

                                Groups: {{"tars", "rats", "arts"}}

                    "arts":     
                                a r t s
                                s t a r
                                | | | |     

                                        Not matched with anyone

                                Groups: {{"tars", "rats", "arts"}, {"arts"}}
                                

                    These 3 {"tars", "rats", "arts"} are in the same group, because they have <= 2 distinct characters

                                t a r s     r a t s
                                r a t x     a r t s
                                |   |       | |

                    {"star"} is in the other group as it's not matched with any one, and it have more than two distinct characters.


    // Union Find/DSU Approach:
        - For connecting two identical string, we can use DSU
        - We will check every string with every other strings, takes O(n^2)
            - Now We will iterate in that both string and find the number distinct characters.
            - If it's <= 2: Connect them.
        - Last we will count total number of connected components.

        // complexity:
            - TC: O(n^2 * m)
            - SC: O(n)
                - n = total number of strings.
                - m = size of each string.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private:
    vector<int> size, parent;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression.
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected

        // Connect smaller group to larger one.
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();        // total number of strings.
        int m = strs[0].size();     // each string size.

        // Step 1: Connect nodes & form connected components:
        DSU ds(n + 1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string s1 = strs[i];
                string s2 = strs[j];

                // if strings are identical:
                if(s1 == s2) {  
                    ds.Union(i, j);     // connect nodes
                    continue;           // skip
                }

                // Check character by characters & get distinct count:
                int distinct = 0;
                for(int k = 0; k < m; k++) {
                    if(s1[k] != s2[k]) {
                        distinct++;
                    }

                    if(distinct > 2) break;
                }

                if(distinct <= 2) { // at most 2 distinct
                    ds.Union(i, j);
                }
            }
        }

        // Step 2: Calculate total number of connected components:
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.ultPar(i) == i) comp++;
        }

        return comp;
    }
};