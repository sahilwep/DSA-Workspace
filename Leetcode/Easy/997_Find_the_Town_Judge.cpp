/*

//  997. Find the Town Judge


//  Problem Statement: 
    - In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
    - If the town judge exists, then:
        - The town judge trusts nobody.
        - Everybody (except for the town judge) trusts the town judge.
        - There is exactly one person that satisfies properties 1 and 2.
    - You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
    - Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 
// Example:
    Example 1:
        Input: n = 2, trust = [[1,2]]
        Output: 2

    Example 2:
        Input: n = 3, trust = [[1,3],[2,3]]
        Output: 3

    Example 3:
        Input: n = 3, trust = [[1,3],[2,3],[3,1]]
        Output: -1



// Observations:
    - given trust[i, j] says: i trust j
    - and judge trust no-body
    - and everyone trust the town-judge
    - if these two conditions meet, return that as answer.
    - else -1

    // Approach:
        - Given n person/nodes
        - Everyone trust judge, means judge should have exactly n - 1 people who trust them.
        - also, judge trust no-body, means judge should never be "visited"/
        - We can maintain two vector:
            - vis[x] says which node is being trusted: trust[i, j] => vis[i] = 1
            - and cnt[x] says the total number of people trust them: trust[i, j] => cnt[j]++;
        - If any node, has not yet visited, means hey not trust anyone, and have cnt = n - 1, means that's the judge, else return "-1"


        // Complexity:
            - TC: O(n)
            - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> cnt(n + 1, 0);
        vector<int> vis(n + 1, 0);
        for(auto &i: trust) { // => [i[0], i[1]]
            vis[i[0]] = 1;
            cnt[i[1]]++;
        }

        for(int i = 1; i <= n; i++) if(vis[i] == 0 && cnt[i] == n - 1) return i;
        
        return -1;  // case violated
    }
};