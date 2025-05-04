/*

//  1128. Number of Equivalent Domino Pairs


//  Problem Statement: 
    -> Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
    -> Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
 

// Example: 
    Example 1:
        Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
        Output: 1

    Example 2:
        Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
        Output: 3

// Observations: 

    Example: 4 numbers: 1 2 3 4

    pairs: (n * (n - 1)) / 2

        (1 2) (1 3) (1 4)
        (2 3) (2 4)
        (3 4)

        total = 6

// Complexity:
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient: 
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;

        for(auto &it: dominoes) {
            mp[{min(it[0], it[1]), max(it[0], it[1])}]++;
        }

        int ans = 0;
        for(auto &[key, val]: mp) {
            ans += (val * (val - 1)) / 2;
        }

        return ans;        
    }
};


// BruteForce: 
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1] 
                || dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0]) {
                    cnt++;
                }
            }
        }

        return cnt;        
    }
};