/*

//  2381. Shifting Letters II


//  Problem Statement:
    -> You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
    -> Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
    -> Return the final string after all such shifts to s are applied.

 
// Example:

    Example 1:
        Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
        Output: "ace"
        Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
        Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
        Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".

    Example 2:
        Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
        Output: "catz"
        Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
        Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Bruteforce Solution:
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();

        string temp = s;
        for(int i=0;i<n;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];

            // Now Shift:
            if(dir == 1){    // forward
                for(int j=start;j<=end;j++){
                    // Decrement characters
                    char ch = temp[j];
                    if(ch == 'z'){
                        temp[j] = 'a';
                    }else{
                        ch++;
                        temp[j] = ch;
                    }

                    // Second Logic:
                    // ch = 'a' + (ch - 'a' + 1) % 26;
                    // temp[j] = ch;
                }
            }
            else{   // backword
                for(int j=start;j<=end;j++){
                    // Decrement characters
                    char ch = temp[j];
                    if(ch == 'a'){
                        temp[j] = 'z';
                    }else{
                        ch--;
                        temp[j] =ch;
                    }

                    // Second Logic:
                    // ch = 'a' + (ch - 'a' - 1 + 26) % 26;
                    // temp[j] = ch;
                }
            }
        }

        return temp;
    }
};


/*
// Explanation of rotating alphabets in bound:

    Forward Shift (dir == 1):
        ch - 'a' converts the character to a number in the range [0, 25].
        Add 1 to shift forward.
        % 26 ensures the result wraps around if it goes beyond 'z'.
        Add 'a' to convert back to a character.

    Backward Shift (dir == 0):
        ch - 'a' converts the character to a number in the range [0, 25].
        Subtract 1 to shift backward.
        Add 26 to handle negative results.
        % 26 ensures the result stays within the range [0, 25].
        Add 'a' to convert back to a character.

*/