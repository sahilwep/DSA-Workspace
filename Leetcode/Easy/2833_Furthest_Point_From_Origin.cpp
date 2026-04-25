/*

//  2833. Furthest Point From Origin


//  Problem Statement: 
    - You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.
    - In the ith move, you can choose one of the following directions:
        - move to the left if moves[i] = 'L' or moves[i] = '_'
        - move to the right if moves[i] = 'R' or moves[i] = '_'
    - Return the distance from the origin of the furthest point you can get to after n moves.


// Example:
    Example 1:
        Input: moves = "L_RL__R"
        Output: 3
        Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".

    Example 2:
        Input: moves = "_R__LL_"u
        Output: 5
        Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".

    Example 3:  
        Input: moves = "_______"
        Output: 7
        Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".


// Observations:
    - Given moves in length n,
    - We will start from 0 and then move left & right.
    - when we have _, we will move left & right both.
    - we have to return the farthest distance from the origin.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int l = 0;
        int r = 0;

        for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == '_') {
                l++;
                r++;
            } else if(moves[i] == 'L') {
                l++, r--;
            } else {
                l--, r++;
            }
        }

        return max(l, r);
    }
};