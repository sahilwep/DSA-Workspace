/*

//  721. Accounts Merge


//  Problem Statement: 
    -> Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
    -> Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
    -> After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 
// Example: 

    Example 1:
        Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
        Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
        Explanation:
            The first and second John's are the same person as they have the common email "johnsmith@mail.com".
            The third John and Mary are different people as none of their email addresses are used by other accounts.
            We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
            ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

    Example 2:
        Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
        Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

        

// Observations:
    -> We are given a list of names & their belonging emails.
    -> If two accounts share at least one common email, they belong to the same person and should be merged.
    -> The final output should contain sorted emails for each person.

    // DSU Approach:
        // Why DSU Approach? 
            -> DSU helps us efficiently group and merge accounts belonging to the same person.
            -> We treat emails as nodes and accounts as sets to be merged using DSU.

        Steps:
            1. Traverse the accounts list and map emails to their corresponding index in the accounts list.
            2. Use DSU to merge indices when a common email is found.
            3. Iterate through the map again to group emails by their ultimate parent.
            4. Sort emails and prepare the final result.

    // Visualization: 
            -> Example: 
                    [["john", "j1@com", "j2@com", "j3@com"],    -> 0
                    [["john", "j4@com"],                        -> 1
                    [["raj", "r1@com", "r2@com"],               -> 2
                    [["john", "j1@com", "j5@com"],              -> 3
                    ["raj","r2@com", "r3@com"],                 -> 4
                    ["marry","m1@com"]]                         -> 5

                -> Every names correspond to the index (0,1,2,3,4,..,n)

                -> Process every email & try to find in map & if not exist -> insert, else if exist take union from current nameIndex & index fround in map:

                    j1@com:
                            -> Not Found:
                                map: {"j1@com": 0}
                            
                    j2@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0}

                    j3@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0}

                    j4@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1}

                    j4@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1}

                    r1@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1, "r1@com": 2}

                    r2@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1, "r1@com": 2, "r2@com": 2}

                    j1@com:
                            -> Found:
                                -> "j1@com" value is '0', means it already found at index '0'.
                                -> We are at index '3'
                                -> merge '0' & '3' -> Denotes emails at index '0' & '3' belongs to same person.
                                Union(0, 3)

                                    [0]
                                    /
                                  [3]
                    
                    j5@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1, "r1@com": 2, "r2@com": 2, "j5@com": 3}

                    r2@com:
                            -> Found:
                                -> "r2@com" value is '2', means it already found at index '2'.
                                -> We are at index '4'
                                -> merge '2' & '4' -> Denotes emails at index '2' & '4' belongs to same person.
                                Union(2, 4)

                                    [0]         [2]
                                    /           /
                                  [3]         [4]
                                
                    r3@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1, "r1@com": 2, "r2@com": 2, "j5@com": 3, "r3@com": 4}
                                
                    m1@com:
                            -> Not Found:
                                map: {"j1@com": 0, "j2@com": 0, "j3@com": 0, "j4@com": 1, "r1@com": 2, "r2@com": 2, "j5@com": 3, "r3@com": 4, "m1@com": 5}

                -> At the End we will have our map & DSU:

                                    [0]         [2]      [1]       [5]
                                    /           /
                                  [3]         [4]

                                map: 
                                    {"j1@com": 0, 
                                     "j2@com": 0, 
                                     "j3@com": 0, 
                                     "j4@com": 1, 
                                     "r1@com": 2, 
                                     "r2@com": 2, 
                                     "j5@com": 3, 
                                     "r3@com": 4, 
                                     "m1@com": 5}

                -> Now Process every emails from map & find every emails ultimate parent & group them together.

                                                                        Corresponding Indexes
                   [["j1@com", "j2@com", "j3@com", "j5@com"],     -->             0/3
                    ["j4@com"],                                   -->             1
                    ["r1@com", "r2@com", "r3@com"],               -->             2/4
                    ["m1@com"]]                                   -->             5
                                

                -> Now, sort them & assign the name to every group:
                    [["john", "j1@com", "j2@com", "j3@com", "j5@com"],
                    ["john", "j4@com"],
                    ["raj", "r1@com", "r2@com", "r3@com"],
                    ["marry", "m1@com"]]



// Complexity: 
    -> TC: O(n * (m * log(m))
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {    // TC: O(n * (m * log(m)))
        int n = accounts.size();

        // Step 1: Map emails to their corresponding account index
        // Every accounts treated as index 'i' and with that we have list of emails & corresponding to that we will assign values into map:
        DSU ds(n);
        unordered_map<string, int> mp;  // <Email : foundAtIndex>

        for(int i = 0; i < n; i++) {    // TC: O(n)
            for(int j = 1; j < accounts[i].size(); j++) {
                // i represent names
                // accounts[j] respreset emails

                string email = accounts[i][j];

                // Find if email already exist in map or not?
                if(mp.find(email) == mp.end()) {      // not exist, then insert it
                    mp[email] = i;
                } else {    // it exist
                    // merge (u & v) them together..
                    int u = i;
                    int v = mp[email];

                    ds.Union(u, v); // merge them
                }
            }
        }

        // Step 2: Group emails by their ultimate parent
        // Now Iterate in map again & form 2D vectors contains merged emails belongs to same persons:
        vector<vector<string>> res(n);
        for(auto &it: mp) { // TC: O(m)
            // Get the value from map, & get their ultimate parent & assign the email to the ultimate parent place
            string email = it.first;
            int value = it.second;

            int ultParent = ds.ultPar(value); // get the ultimate parent from the value

            res[ultParent].push_back(email); // push email to the ultimate parent/person
        }


        // Step 3: Prepare the result with sorted emails:
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {    // TC: O(n * (m * log(m)))
            if(res[i].size() > 0) { // List should not be empty
                sort(res[i].begin(), res[i].end()); // sort the values

                vector<string> tempAns;
                tempAns.push_back(accounts[i][0]);   // get the name

                for(auto &email: res[i]) {  // store the corresponding emails
                    tempAns.push_back(email);
                }

                ans.push_back(tempAns); // last push all the list into our answer.
            }
        }

        return ans;
    }
};