/*

//  2410. Maximum Matching of Players With Trainers


//  Problem Statement: 
    -> You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
    -> The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
    -> Return the maximum number of matchings between players and trainers that satisfy these conditions.

 
// Example: 
    Example 1:
        Input: players = [4,7,9], trainers = [8,2,5,8]
        Output: 2
        Explanation:
        One of the ways we can form two matchings is as follows:
        - players[0] can be matched with trainers[0] since 4 <= 8.
        - players[1] can be matched with trainers[3] since 7 <= 8.
        It can be proven that 2 is the maximum number of matchings that can be formed.

    Example 2:
        Input: players = [1,1,1], trainers = [10]
        Output: 1
        Explanation:
        The trainer can be matched with any of the 3 players.
        Each player can only be matched with one trainer, so the maximum answer is 1.

// Observations: 
    -> Given a list contains players & trainers
    -> If the ith player can match the jth trainer if the player's ability is less than equal trainer, we can count that match
    -> We have to return the maximum number of matching b/w players and trainers that satisfy these conditions.


    // Approach: 
        -> If we sort both the given list, then we can process every match quite easy.
        -> After sorting, we can use two pointers starting from '0' & move greedy the count if given conditions satisfies..


        // Complexity: 
            -> TC: O(max(nlogn, mlogm))
                -> n = players.size()
                -> m = players.size()
            -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        // Sort both the given list:
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        // Use two pointers:
        int match = 0;
        int i = 0, j = 0;
        while(i < n && j < m) {
            // If players ability is less or equal to the trainer capacity
            if(players[i] <= trainers[j]) {
                match++;    // found new match

                // Move both the pointers
                i++;
                j++;
            } else {
                j++;    // look for bigger trainer capacity.
            }
        }

        return match;
    }
};