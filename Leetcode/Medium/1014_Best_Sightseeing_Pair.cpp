/*

//  1014. Best Sightseeing Pair

//  Problem Statement:
    -> You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
    -> The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
    -> Return the maximum score of a pair of sightseeing spots.


// Example:
    Example 1:
        Input: values = [8,1,5,2,6]
        Output: 11
        Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

    Example 2:
        Input: values = [1,2]
        Output: 2



// Observations:
    given an array values, value[i] represent value of ith sightseeing spot. 
    Two sightseeing spots i & j have a distance "j - i" between them.

    The score of a pair(i < j) of sightseeing spots is 'values[i] + values[j] + i - j' : the sum of the values of the sightseeing spots, minus the distance b/w them.

    return the maximum score of a pair of sightseeing spots.
            values = value[i] + value[j]
            indices = i - j
            distance = values[i] + values[j] + i - j -> This should be nmaximum

            NOTE: (i < j) i should be less than j



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Solution:
class Solution_Brute{
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tempAns = values[i] + values[j] + i - j;
                ans = max(tempAns, ans);
            }
        }

        return ans;
    }
};


