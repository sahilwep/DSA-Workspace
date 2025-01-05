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



// BruteForce Solution: 
    -> Update the query, by getting starting & ending index.
    -> TC: O(n*m), n = s.size(), m = shifts.size()


// Efficient Solution:
    -> We will use Array Difference Technique:
    -> Array Diff Technique:
        -> It Says if we are given some range (low, & high) of array, & we have to perform some changes into array value:
            -> Update that change into array[low]
            -> Update that change compliment to arr[high+1]
            -> Last, Generate Commutative Sum of whole change, we will get the result.


    -> Step 1: Find Diff Array:
        -> diff[l] += x
        -> diff[r+1] += -x;
    
    -> Step 2: Get the Commutative Sum of diff array

    // Step 3: Apply the computed diff array changes to the string
        // Add characters with round Values:
            -> Convert characters into numbers: -> Substract 'a' to the given character
                a - 'a' = 0
                b - 'a' = 1
                c - 'a' = 2
                ...
                ...

                    s[i] - 'a' -> We will get the Corrsponding value.
            
            -> Convert value to characters: -> add 'a' to the given value
                0 + 'a' = a
                1 + 'a' = b
                ...
                ...

                    value + 'a' = s[i] -> We will get the Corrsponding character.
            
            -> Now we need to add commutative array to every characters, but it should be in range, we need value b/w range (0, 25)
                -> We will take modulo 26, with every characters in order to get the correct range value.
                // If commutativeSum[i] = Positive: 
                    take modulo with 26
                
                // If commutativeSum[i] = Negative
                    take modulo with 26 & add 26

        -> TC: O(n)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach:
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        // Step 1: Initialize the difference array to track net shifts
        vector<int> change(n, 0);

        // Step 2: Populate the difference array based on shift queries
        for (auto& query : shifts) {
            int l = query[0]; // Starting index of the range
            int r = query[1]; // Ending index of the range
            int dir = query[2]; // Direction: 0 for decrement, 1 for increment

            // Apply difference array technique:
            if (dir == 0) { // Decrement case: Shift range down by 1
                change[l] += -1;
                if (r + 1 < n) change[r + 1] += 1; // Neutralize after the range
            } 
            else {  // Increment case: Shift range up by 1
                change[l] += 1;
                if (r + 1 < n) change[r + 1] += -1; // Neutralize after the range
            }
        }

        // Step 3: Compute the cumulative sum for net shifts, This transforms the difference array into a cumulative array
        for (int i = 1; i < n; i++) {
            change[i] += change[i - 1];
        }

        // Step 4: Apply the computed shifts to the string
        string result = s; // Create a result string to store the shifted characters
        for (int i = 0; i < n; i++) {
            // Calculate the new character after applying the shift
            int shift = (result[i] - 'a' + change[i]) % 26; // Map to 0-25 range

            if (shift < 0) shift += 26; // Handle negative shifts (wrap around)

            result[i] = shift + 'a'; // Convert back to a character
        }
        
        return result;
    }
};



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