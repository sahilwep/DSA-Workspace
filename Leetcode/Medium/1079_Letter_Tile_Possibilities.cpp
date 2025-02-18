/*

//  1079. Letter Tile Possibilities

//  Problem Statement: 
    -> You have n  tiles, where each tile has one letter tiles[i] printed on it.
    -> Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.


// Example:

    Example 1:

        Input: tiles = "AAB"
        Output: 8
        Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

    Example 2:

        Input: tiles = "AAABBC"
        Output: 188

    Example 3:

        Input: tiles = "V"
        Output: 1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n;
    void solve(string tiles, vector<bool> &used, unordered_set<string> &result,string &curr) {
        result.insert(curr);

        for(int i = 0; i < n; i++) {    // always start from i = 0
            if(used[i]) {   // if that character is already used, skip that.
                continue;
            }

            // Backtracking:
            // Try:
            used[i] = true;
            curr.push_back(tiles[i]);

            // Explore:
            solve(tiles, used, result, curr);

            // undo:
            used[i] = false;
            curr.pop_back();
        }
    }
public:
    int numTilePossibilities(string tiles) {
        n = tiles.size();

        vector<bool> used(n, false);
        unordered_set<string> res;

        string curr = "";

        solve(tiles, used, res, curr);

        return res.size()-1;
    }
};