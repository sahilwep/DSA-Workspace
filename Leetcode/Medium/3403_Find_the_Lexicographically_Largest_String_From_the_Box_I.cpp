/*

//  3403. Find the Lexicographically Largest String From the Box I


//  Problem Statement: 
    -> You are given a string word, and an integer numFriends.
    -> Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
        -> word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
        -> All the split words are put into a box.
    -> Find the string from the box after all the rounds are finished.

 
// Example: 

    Example 1:
        Input: word = "dbca", numFriends = 2
        Output: "dbc"
        Explanation: 
            All possible splits are:
                "d" and "bca".
                "db" and "ca".
                "dbc" and "a".
            Lexigraphically "dbc" is grater among all

    Example 2:
        Input: word = "gggg", numFriends = 4
        Output: "g"
        Explanation: The only possible split is: "g", "g", "g", and "g".


// Observations: 
    -> We need to perfrom word distribution in numFriends.
    -> And return the largest lexigraphically subString..
    -> Largest substring start from the lexigraphically largest character from "word".

    
    // Key Observations: 
        (numfriends - 1) => Are the total number of friend who are participating in largest substring.
        So, we can simly subtract it from the given word size, which will give us the size of largest subString.
            
            largestStringLen = word.size() - (numFriend - 1)    => This will give us the size of largest substring.

        Now We are aware about the size of largest substring.
        It's just we have to find the largest substring.


        // Solution: 
            -> first find the largest character from given word
            -> Get the largest subString length by {word.size() - (numFriend - 1)}
            -> Now try build answer.
            -> Let's visualize this using few examples: 

                Ex 1: word = "dbca", numFriends = 2

                    Largest character = d
                    largest subString size = word.size() - (numFriends - 1) => 3
                    now try build the substring from the largest character position, which will give us "dbc"


                Ex 2: word = "eabcded", numFriends = 4

                    Largest character = e
                    largest subString size = word.size() - (numFriends - 1) => 4
                    now try build the substring from the largest character position
                    e is at multiple index: 
                            e a b c d e d
                            0 1 2 3 4 5 6
                            |         |

                    we get "eabc" & "ed" two substring => "ed"  is our answer, because it's lexigraphically grater than "eabc".
                    One more observations, it's not necessary that our answer is of largest Substring size.
                    It may be possible it can be have lesser size..


            -> Edge case: if (numFriends == 1) return word itself.


// Complexity: 
    -> TC: O(N)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();

        // Edge case: 
        if(numFriends == 1) return word;

        int largeststringSize = n - (numFriends - 1);   // this is the maximum size which we can take from string as our answer

        string ans = "";
        for(int i = 0; i < n; i++) {
            int canTakeLength = min(largeststringSize, n - i);      // get the largest substring size we can take for each index

            ans = max(ans, word.substr(i, canTakeLength));  // get the substring from every 'i' & compare it with previous finding...
        }

        return ans;
    }
};