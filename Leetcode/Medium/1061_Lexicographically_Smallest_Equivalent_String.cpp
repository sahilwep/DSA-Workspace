/*

//  1061. Lexicographically Smallest Equivalent String


// Problem Statement:
    -> You are given two strings of the same length s1 and s2 and a string baseStr.
    -> We say s1[i] and s2[i] are equivalent characters.
        -> For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
    -> Equivalent characters follow the usual rules of any equivalence relation:
        -> Reflexivity: 'a' == 'a'.
        -> Symmetry: 'a' == 'b' implies 'b' == 'a'.
        -> Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
    -> For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
    -> Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 
// Example: 
    Example 1:

    Input: s1 = "parker", s2 = "morris", baseStr = "parser"
    Output: "makkek"
    Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
    The characters in each group are equivalent and sorted in lexicographical order.
    So the answer is "makkek".

    Example 2:

    Input: s1 = "hello", s2 = "world", baseStr = "hold"
    Output: "hdld"
    Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
    So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".

    Example 3:

    Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
    Output: "aauaaaaada"
    Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".

    
// Observations: 
    -> If Observe the question carefully, This question gives us direct hints of DSU, remember of solving "account merge" from DSU
    -> There are two thing which we have to achieve in order to solve this question.
        -> First make groups of simillar characters || characters that have some sort of dependency, direct or indirect.    
        -> second, when we make groups, we only have to select the smallest character.
    -> Then we will process the baseStr & check each character within the formed groups.

// Complexity: 
    -> TC: O(n + m)
        -> n = s1.size() || s2.size()
    -> SC: O(1)
        -> Because we are only processing 26 character.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
        // Connect smaller to larger size:
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
       
        // Step 1: Connect the components:
        DSU ds(27);
        for(int i = 0; i < n; i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.Union(u, v);
        }

        // Step 2: Get the Ultimate parent: & smallest character
        unordered_map<int, char> mp;    // use to store <ultParent, smallest_Character>
        for(int i = 0; i < n; i++) {
            char ch1 = s1[i];
            char ch2 = s2[i];

            int ultParU = ds.ultPar(ch2 - 'a'); // get the ultimate parent, from any of the charter, because they are connected.
            
            // Check, if we have ultimate parent in our map:
            if(mp.count(ultParU)) {
                char prevCh = mp[ultParU];  // get the smallest character
                // now compare it with previous & store the minimum: 
                mp[ultParU] = min(prevCh, min(ch1, ch2));

            } else {  // we don't have ultimate parent into map:
                // hash it with smaller value
                mp[ultParU] = min(ch1, ch2);
            }
        }

        // Step 3: Build answer from map & DSU: 
        string ans = "";
        for(auto& ch: baseStr) {
            // If character found in map:
            if(mp.count(ds.ultPar(ch - 'a'))) {
                ans += mp[ds.ultPar(ch - 'a')];
            }
            else {  // else not found, simply paste the baseStr character.
                ans += ch;
            }
        }

        return ans;
    }
};