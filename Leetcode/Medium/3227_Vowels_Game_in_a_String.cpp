/*

//  3227. Vowels Game in a String


//  Problem Statement: 
    -> Alice and Bob are playing a game on a string.
    -> You are given a string s, Alice and Bob will take turns playing the following game where Alice starts first:
        -> On Alice's turn, she has to remove any non-empty 
    -> from s that contains an odd number of vowels.
    -> On Bob's turn, he has to remove any non-empty
        -> from s that contains an even number of vowels.
    -> The first player who cannot make a move on their turn loses the game. We assume that both Alice and Bob play optimally.
    -> Return true if Alice wins the game, and false otherwise.
    -> The English vowels are: a, e, i, o, and u.

 
    Example 1:
        Input: s = "leetcoder"
        Output: true
        Explanation:
        Alice can win the game as follows:
            Alice plays first, she can delete the underlined substring in s = "leetcoder" which contains 3 vowels. The resulting string is s = "der".
            Bob plays second, he can delete the underlined substring in s = "der" which contains 0 vowels. The resulting string is s = "er".
            Alice plays third, she can delete the whole string s = "er" which contains 1 vowel.
            Bob plays fourth, since the string is empty, there is no valid play for Bob. So Alice wins the game.


    Example 2:
        Input: s = "bbcd"
        Output: false
        Explanation:
        There is no valid play for Alice in her first turn, so Alice loses the game.


// Observations:
    -> The key idea is: Alice always wins if there is at least one vowel in the string.

    -> Here’s why:
        -> Alice’s move (odd vowels rule):
            -> Alice is only allowed to remove substrings containing an odd number of vowels.
                -> If the string contains at least one vowel, Alice can always make a move.
        -> Bob’s move (even vowels rule):
            -> Bob can only remove substrings containing an even number of vowels (including zero).
                -> This means Bob cannot remove the last vowel, because that would always be an odd count.

    -> How Alice secures victory:
        -> On her first move, Alice can choose to remove the entire string if it contains an odd number of vowels.
        -> If the total vowel count is even, Alice can still remove a substring with an odd number of vowels, leaving an odd number behind.
        -> This ensures that after Alice’s turn, there are always vowels left, and their count is odd.

    -> Why Bob can never win:
        Bob is restricted to removing substrings with an even number of vowels.
        Therefore, he can never eliminate the last remaining vowel.
        Alice will always be the one to take the final vowel on her turn.

    -> Final Conclusion:
        -> No vowels in the string → Alice cannot move → Bob wins immediately.
        -> At least one vowel in the string → Alice can always force the game so that she removes the last vowel → Alice wins.


    // Example:
        Example 1: s = "baabbbba"
            Total vowels = 3 (odd).
            Alice can directly take the entire string in her first move, since it contains an odd number of vowels.
            No characters remain, so Alice wins immediately.


        Example 2: s = "babbbabb"

            Initial string: "babbbabb"
                Vowels = 2 (a, a) → even.
                Alice cannot take the whole string, but she can remove a substring with odd vowels.

            Alice’s first move:
                She removes "bab" (contains 1 vowel).
                Remaining string = "bbabb".

            Bob’s turn:
                Bob can only remove substrings with an even number of vowels.
                In "bbabb", he can remove "bbab" (contains 0 vowels).
                Remaining string = "b".

            Alice’s turn:   
                The last character is "b" (no vowels).
                Alice can’t take it, but notice: Bob also can’t take the last vowel because it never existed.
                In earlier moves, Alice already guaranteed that Bob never got the chance to remove a vowel.

                Another sequence also works:
                    Alice first takes "ba" (1 vowel).
                    Remaining string = "bbabb".
                    Bob removes "bb" (0 vowels).
                    Remaining string = "abb".
                    Alice takes "a" (1 vowel).
                    Remaining = "bb".
                    Bob can only take substrings without vowels, leaving no vowels for him to win.

                In every path, Alice is the one who removes the final vowel.


    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)

        
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for(char ch: s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;  // as long as we have any vowel, alice wins.
        }
        
        return false;
    }
};