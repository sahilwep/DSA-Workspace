/*

//  1025. Divisor Game


//  Problem Statement: 
    - Alice and Bob take turns playing a game, with Alice starting first.
    - Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
        - Choosing any integer x with 0 < x < n and n % x == 0.
        - Replacing the number n on the chalkboard with n - x.
    - Also, if a player cannot make a move, they lose the game.
    - Return true if and only if Alice wins the game, assuming both players play optimally.


// Example:
    Example 1:
        Input: n = 2
        Output: true
        Explanation: Alice chooses 1, and Bob has no more moves.

    Example 2:
        Input: n = 3
        Output: false
        Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


// Observations: 
    - If we got 'n' as even, alice can always subtract 1(since 1 is a divisor of every number), leaving an odd number for bob.
    - When bob gets an odd number, whatever divisor he chooses will always be odd, and subtracting an odd number from an odd number result is an even number again - giving the advantage back to alice.


    // Complexity: 
        - TC: O(1)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        if(n % 2 == 0) return 1;
        else return 0;
    }
};