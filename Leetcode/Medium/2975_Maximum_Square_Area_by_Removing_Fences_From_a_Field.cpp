/*

//  2975. Maximum Square Area by Removing Fences From a Field


//  Problem Statement: 
    - There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.
    - Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).
    - Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.
    - Since the answer may be large, return it modulo 109 + 7.
    - Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 
// Example:
    Example 1:
        Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
        Output: 4
        Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.

    Example 2:
        Input: m = 6, n = 7, hFences = [2], vFences = [4]
        Output: -1
        Explanation: It can be proved that there is no way to create a square field by removing fences.


// Observations:
    - Given grid of dimensions (n * m)
    - given list of hFences & vFence
    - Grid can be formed from the given h & v fences, it's not like we will create 1x1 cells..
    - we need to find the maximum square area.
    - Example:
        Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
        Grid: 
                     1   2   3
                      ___ ___
                  1  |   |   |
                  2  |---|---|  <-  h fences
                  3  |---|---|  <-  h fences
                  4  |___|___|
                         ^
                         |
                        v fences

    - Example:
        Input: 
            m = 6, n = 7, hFence = [2], vFences = [4]
            Grid:

                      1   2   3    4    5   6   7
                      __________________________
                  1  |             |            |
                  2  |-------------|------------|  <-  h fences
                  3  |             |            |
                  4  |             |            |
                  5  |             |            |
                  6  |_____________|____________|
                                   ^
                                   |
                                v fences

    - It's not like we can make our grid with every points:
        - Means we have given (1 & n) & (1 & m) fences
        - We can put fences from vFences & hFences.
        - And we can build our grid.
        - Once we build our grid, we need to find maximum area of square by removing fences from vFences or hFences.

    // Approach:
        - From given n & m
        - We can say that we have vertical 1 & nth fence and horizontal 1 & mth fence.
        - Eg: 
            n = 3, m = 5

                    1                 5
                1    _________________
                    |                 |
                    |                 |
                3   |_________________|

            This is something we have given for sure.
        - From the hFences & vFences we can insert fence in our grid.
        - Eg: 
            hFences = [2]
            vFences = [4]

                    1            4    5
                1    _________________
                    |            |    |
                2   |------------|----|
                3   |____________|____|

        - A very simple approach is: 
            - For every two points in hFences:
                - let say (1, 4) dis = 3
                    - We will find wether we can build dis = 3 in vFences or not by removing any fences?
                    - here in this above example we can't.
                - let say (1, 5) dis = 4
                    - we will find wether we can build dis = 4 in vFences or not by removing any fences?
                    - here in this example we can't.
                - Let say (4, 5) dis = 1
                    - we will find wether we can build dis = 1 in vFences or not by removing any fences?
                    - Well, we can build in vFences point(1, 2): 
                        - dis = 2 - 1 = 1
                        - So maximum square is 1 * 1 = '1' area..
                ...
                ...
                ...
            ...
            ...
        - So if we Calculate every possible distance from hFences:
                hFences = [2]
                1 = starting, m = 3 boundary
                hFences = [1, 2, 3]
                All possible distance:
                    (1, 2) = 1
                    (1, 3) = 2
                    (2, 3) = 1
    
            Similarly if we calculate all possible distance from vFences:
                vFences = [4]
                1 = starting, n = 5 ending
                vFences = [1, 4, 5]
                All possible distance:
                    (1, 4) = 3
                    (1, 5) = 4
                    (4, 5) = 1

        - And we simply look what are the matching values in hFences Distance & vFences Distance:
            - it's '1' so area = '1'

        // Solution:
            - First compute all the possible distance from hFences:
                - We can use nested loop to generate all the distance
            - Similarly compute all the possible distance from vFences:
                - We can use nested loop to generate all the distance
            - Once we have the list:
                - We can iterate in any one of them:
                    - & try to look on other list that wether we have that distance present or not?
                    - If yes, store them, & make sure that we should get the maximum matched values..
            - While generating all possible distance from the vFences:
                - it might be possible that we will have duplicates distance, so we will use set.
                - also we need to lookup in this vFences while we fiding same distance in hFences, we need constant time, so we will use "unordered_set"
            - Similarly for hFences:
                - we will generate all the possible distance & store them in unordered map.
            - Lastly when we have list: allPossibleDistanceFromVFence && allPossibleDistanceFromHFence
                - We can iterate any of them and find the maximum distance we can get..
                - last return the area of square from that distance, which is areaSquare = side * side.

        // Complexity:
            - Generating all possible hFences & vFences: 
                1 <= hFences.size(), vFences.size() <= 600  => let say 'k'
                r = maximum generated all possible size
            - TC: O(k^2 + k^2 + k^2) => O(k^2)
            - SC: O(k^2), because in worse case set may contains k^2 elements...
                        
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    unordered_set<int> getWidth(vector<int>& fences, int border) {  // generate all the possible distances
        unordered_set<int> st;
        fences.push_back(1);       // push starting fence
        fences.push_back(border);  // push last fence

        sort(begin(fences), end(fences));   // sort the list:   k * log k
        for(int i = 0; i < fences.size(); i++) {    // k^2
            for(int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }

        return st;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        unordered_set<int> hw = getWidth(hFences, m);   // O(m^2)   => worse say (k^2)
        unordered_set<int> vw = getWidth(vFences, n);   // O(n^2)   => worse say (k^2)
        
        int side = 0;
        for(auto &it: hw) { // O(k^2)
            if(vw.count(it)) {
                side = max(side, it);  // get the maximum width found from both horizontal & vertical.
            }
        }

        if(side == 0) {  // no such square found
            return -1;
        }

        int square = (1ll * side * side) % mod;

        return square;
    }
};