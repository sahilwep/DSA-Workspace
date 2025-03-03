/*

//  G-26. Alien Dictionary - Topological Sort Using Map: GFG Accepted

//  Problem Statement:
    -> A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.
    -> Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.
    -> However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").
        -> A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.
    -> Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.


// Examples:

    Input: words[] = ["cb", "cba", "a", "bc"]
    Output: true
    Explanation: You need to return "cab" as the correct order of letters in the alien dictionary.

    Input: words[] = ["ab", "aa", "a"]
    Output: ""
    Explanation: You need to return "" because "aa" is lexicographically larger than "a", making the order invalid.

    Input: words[] = ["ab", "cd", "ef", "ad"]
    Output: ""
    Explanation: You need to return "" because "a" appears before "e", but then "e" appears before "a", which contradicts the ordering rules.


// Constraints:

    1 <= words.length <= 500
    1 <= words[i].length <= 100
    words[i] consists only of lowercase English letters.


// Observation:
    
    -> We have to find out the alien order:
    -> Some 'k' word is from alphabet dictionary
        k = 4 => abcd => we know there is some 4 starting alphabet is being used.
    
    Alphabet: Seq: abcd.....xyz
    Ordering Alpha. Dic
        
        abca
        abcd
        baa
        cab
        cad
    
    Given Alien Dic
    
        baa
        abcd
        abca
        cab
        cad
        
            
    From here: 
            
            baa
            abcd
            
                -> 'b' appear before 'a', this is why "baa" is before "abcd" in alien dict
             
            abcd
            abca
                
                -> 'd' appear before 'a', this is why "abcd" is before "abca" in alien dict
            
            abca
            cab
                
                -> 'c' appear before 'a', this is why "abca" is before "cab" in alien dict
            
            cab
            cad
                
                -> 'b' appear before 'd', this is why "cab" is before "cad" in alien dict
            
            
                Final Ordering From alien Dict: b d a c


    // Approach: How to apply Topo-Sort:
        
            we have been given k = 4, means first 4 english alphabet is from english dictonary is being used
                
            // Express all the alphabet in terms of 0 based numbers:
                    
                    a b c d
                    0 1 2 3
                
                -> then we will pick out:
                    
                    baa
                    abcd
                    
                -> and figure out why this "baa" appear before "abcd"
                    
                    Answer is very simple, (b < a)
                    because 'b' appear before 'a'
                    
                    -> Which we can corresponded to a directed graph.
                    -> We say probabilly we can have some edge
                                
                                b ---> a
                        
                -> We don't need to check "baa" for others, because "baa" is appeared before "abcd" & we have figured it out.
                
                -> now we will pick next pair:
                    
                        abcd
                        abca
                
                    -> Now will try to figure out why "abcd" should appear before "abca"
                    
                        Answer is very simple (d < a)
                        d hashave some edge to a
                        
                            d ---> a        => So, we can have edge from 'd' to 'a'
                        
                -> Next pair:
                    
                        abca
                        cab
                        
                        'c' appear before 'a'
                        there is an edge from c to a
                        
                            c ---> a
                
                -> Next Pair
                        
                         cab
                         cbd[a]
                                    
                        'b' appear before 'd'
                        there is an edge from b to d
                        
                            b ---> d
                        
                
                // Final Directed Graph:
                        
                        [b]-------->[a] <-------[c]
                         |          ↗
                         |        /
                         |      /
                         |    /
                         ↓  /
                        [d]
    
                -> Node, if we would have been given k = 5, means we will be having 'e' also, & if there is no description given about 'e'
                        Then we will consider 'e' to be a single node in Directed Graph


            // Conclusion:
                -> Pick up pairs from given dict & find who is appear before whom & make Directed Graph
                -> And once the Directed Graph is created -> We need order -> And this order can be found using TopoSort
                -> And topological sort is used to create order.
                -> If we can figure out every pair who is appear before whom, like who is the differentiating factor -> then the question boils down to find the TopoSort of DG.


        // Find out Differentiating factor b/w two string:
        
        Eg: 
            baa
            abcd

            use iterator to find equal, if equal move pointer forward
            If iterator falls into not-equal, return the smallest one.



// NOTE: GFG has changed the question, They remove the given 'K' from the question, 
    -> Now first we have to find the 'k' how many unique characters in the given words list.
    -> Then only we can work with that number of nodes:


// Solution Using Map: 
    -> Instead of using vectors to store the nodes value, we will store it into map with key-value pairs
        key -> (node)
        value -> (adjNode1, adjNode2, adjNode3,....adjNode4)

    
    -> NOTE: we need to get the record of every unique characters that were used in the graph, because this is important to process Topo-sort.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        
        // First get the valid unique characters Nodes into set: 
        set<char> st;
        for(auto &word: words) {
            for(auto &i: word) st.insert(i);
        }
        
        // Use Map to Store directed graph adj list:
        unordered_map<int, vector<int>> mp;     //  {node, {adjNode1, .... adjNode_n}}
        vector<int> indegree(26, 0);    // at max we can have only 26 unique characters.
        
        for(int i = 0; i < n - 1; i++) {
            string u = words[i];
            string v = words[i+1];
            
            // Get the difference nodes: 
            bool diffFound = false;
            int len = min(u.size(), v.size());

            for(int ptr = 0; ptr < len; ptr++) {
                if(u[ptr] != v[ptr]) {
                    mp[u[ptr] - 'a'].push_back(v[ptr] - 'a');   // store directed edge:
                    indegree[v[ptr] - 'a']++;   // increment the indegree value for 'v'
                    diffFound = true;   // mark as true, that we have found difference values.
                    break;  // no longer need to match for further char..
                }
            }
            
            // For invalid constrains:
            if(u.size() > v.size() && !diffFound) {
                return "";
            }
        }
        
        
        // Process Topo-sort:
        
        queue<int> q;
        // Iterate in set for valid characters node & store indegree = '0' into queue:
        for(auto &ch: st) {
            if(!indegree[ch - 'a']) {
                q.push(ch - 'a');
            }
        }
        
        string res = "";
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            res += char(node + 'a');
            
            // Explore neighbors from map
            for(auto &it: mp[node]) {

                indegree[it]--; // decrement the indegree directed edges for nodes which are processed.
                if(!indegree[it]) q.push(it);   // push into queue, if indegree value is '0' -> Terminal node considered.
            }
        }
        
        return (st.size() == res.size()) ? res : "";
    }
};