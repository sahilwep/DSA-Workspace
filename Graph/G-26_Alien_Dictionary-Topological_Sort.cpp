/*

//  G-26. Alien Dictionary - Topological Sort

//  Problem Statement:



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



*/

#include <bits/stdc++.h>
using namespace std;

// Updated Code GFG:
class Solution { 
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        
        // Step 1: Find the unique characters present in the given words
        set<char> st;
        for (auto &word : words) {
            for (auto c : word) 
                st.insert(c); // Store all unique characters
        }
        
        int V = st.size(); // Number of unique characters (Nodes in the graph)
        
        // Step 2: Create adjacency list for the graph
        vector<vector<int>> adj(26);  // Since we only have lowercase letters (a-z)
        vector<int> indegree(26, 0);  // Track the indegree of each character
        
        // Step 3: Build the Graph (Directed Edges)
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            
            bool foundDifference = false;
            int len = min(s1.size(), s2.size());
            
            // Compare character by character to find the first mismatch
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    // Create a directed edge from s1[ptr] to s2[ptr]
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    
                    // Increase indegree of s2[ptr] (it now has a dependency)
                    indegree[s2[ptr] - 'a']++;  
                    
                    foundDifference = true;
                    break; // Stop after finding the first mismatch
                }
            }
            
            // If no mismatch was found but s1 is longer than s2, the order is invalid
            if (s1.size() > s2.size() && !foundDifference) {
                return "";  // Invalid order, return empty string
            }
        }
        
        // Step 4: Topological Sorting using Kahn's Algorithm (BFS)
        queue<int> q;
        
        // Enqueue nodes with 0 indegree (No dependencies)
        for (auto &ch : st) {  // Consider only those characters which are in our set:
            if (indegree[ch - 'a'] == 0) {
                q.push(ch - 'a');  // Convert char to index & push it into queue.
            }
        }
        
        string res = ""; // Store the final order
        
        // Process the nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Convert back to character and append to result
            res += char(node + 'a');
            
            // Reduce indegree of all neighbors
            for (auto &it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it); // If indegree becomes 0, add to queue
                }
            }
        }

        // If all characters are processed, return result, otherwise return ""
        return (res.size() == V) ? res : "";
    }
};


// Old Code GFG:
class Solution {
public:
    string findOrder(vector<string> dict, int k) {
        // Graph Creations:
        vector<int> adj[k];
        for(int i=0;i<dict.size()-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(), s2.size());
            bool foundDifference = false;
            for(int ptr = 0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    // we are saying s1 has directed edge to s2, subtract it with 'a' will give corresponding index value.
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');    // some one before someone, so pushed s1[ptr] appear before s2[ptr], so s1 of ptr pushed back s2 of ptr
                    foundDifference = true;
                    break; // Stop comparing further
                }
            }
            
            
            // Check for invalid input where s2 is a prefix of s1
            if (!foundDifference && s1.size() > s2.size()) {
                return ""; // Invalid input
            }
        }
        
        // Apply TopoSort:
        int V = k;
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        // push indegree with value '0' into queue:
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        

        string topo(k, ' '); // Initialize string with size k
        int idx = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo[idx++] = char(node + 'a');
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        // Check if all nodes are processed (cycle detection)
        if (idx != k) {
            return ""; // Cycle detected, invalid input
        }
        
        return topo;
    }
};



string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl << "~" << endl;
    }
    return 0;
}