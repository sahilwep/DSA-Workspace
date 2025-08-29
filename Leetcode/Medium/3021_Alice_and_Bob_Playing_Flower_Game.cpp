/*

//  3021. Alice and Bob Playing Flower Game


//  Problem Statement: 
    -> Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.
    -> The game proceeds as follows:
        -> Alice takes the first turn.
        -> In each turn, a player must choose either one of the lane and pick one flower from that side.
        -> At the end of the turn, if there are no flowers left at all, the current player captures their opponent and wins the game.
    -> Given two integers, n and m, the task is to compute the number of possible pairs (x, y) that satisfy the conditions:
        -> Alice must win the game according to the described rules.
        -> The number of flowers x in the first lane must be in the range [1,n].
        -> The number of flowers y in the second lane must be in the range [1,m].
    -> Return the number of possible pairs (x, y) that satisfy the conditions mentioned in the statement.

 
// Example: 
    Example 1:
        Input: n = 3, m = 2
        Output: 3
        Explanation: The following pairs satisfy conditions described in the statement: (1,2), (3,2), (2,1).

    Example 2:
        Input: n = 1, m = 1
        Output: 0
        Explanation: No pairs satisfy the conditions described in the statement.

//  Observations: 
        -> The one who won, whose turns is last.
    -> First turn is alice, & alice want's to win,
    -> On Every odd position Alice has their chance
    -> In Simple Alice won if ending range of flower is odd

    // Odd Case:
        -> Odd + even = odd
        -> even + odd = odd
        -> rest will be even

    // If we have to find total number of odd/even in range 1 to n:
        n = 5
            1 2 3 4 5
                n/2 -> take ceil => we will get total number of odd numbers
                n/2 -> take floor => we will get total number of even numbers

                Ceil: (n + 1)
                floor (n)

                        odd (ceil)     even (floor)
        x -> [1, n] ->      n/2             n/2
        y -> [1, m] ->      m/2             m/2

        -> The probability to win alice:
            -> Take even flower from x & odd flower in y
            -> OR take odd flower in x & even flower in y

        -> In simple:
                    Alice win: 
                                odd   * even
                                (n/2) * (m/2)
                                (n+1/2) + (m/2)
                                    
                                      +
                                      
                                even *   odd
                                (n/2) * (m/2)
                                (n/2) + (m+1/2)
            
            return (((n + 1) / 2) * (m / 2)) + ((n/2) * ((m + 1)/2));




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    typedef long long ll;
public:
    long long flowerGame(int n, int m) {
        
        ll x = (((ll)n + 1)/2) * ((ll)m/2);
        ll y = ((ll)n / 2) * (((ll)m + 1)/2);
        ll ans = x + y;

        return ans;
    }
};