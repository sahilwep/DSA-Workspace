/*

//  1625. Lexicographically Smallest String After Applying Operations


//  Problem Statement: 
    -> You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.
    -> You can apply either of the following two operations any number of times and in any order on s:
        -> Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
        -> Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
    -> Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.
    -> A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

    
// Example:
    Example 1:
        Input: s = "5525", a = 9, b = 2
        Output: "2050"
        Explanation: We can apply the following operations:
            Start:  "5525"
            Rotate: "2555"
            Add:    "2454"
            Add:    "2353"
            Rotate: "5323"
            Add:    "5222"
            Add:    "5121"
            Rotate: "2151"
            Add:    "2050"​​​​​
            There is no way to obtain a string that is lexicographically smaller than "2050".


    Example 2:
        Input: s = "74", a = 5, b = 1
        Output: "24"
        Explanation: We can apply the following operations:
            Start:  "74"
            Rotate: "47"
            ​​​​​​​Add:    "42"
            ​​​​​​​Rotate: "24"​​​​​​​​​​​​
            There is no way to obtain a string that is lexicographically smaller than "24".

    Example 3:
        Input: s = "0011", a = 4, b = 2
        Output: "0011"
        Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".



// Observations: 
    - Given string 's' of even length, containing 0 to 9
    - Two integer a & b
    - we can apply either of two operations:
        - add a to all odd indices of s, digits post 9 are cycled back to '0'. for example
            s = "3456", a = 5 => s = "3951"
        - Rotate s to be right by b position.
            s = "3456", b = 1 => s = "6345"
    - Return the lexicographically smallest string you can obtain by applying the above operations any number of time on 's'

    // Example: 
        s = "5525", a = 9, b = 2

        
        // Writing function Rotate By 'k'
            Rotate by 2:
                123456        ->        561234

                1234 65 -> reverse(s.size() - k, s.size())
                4321 65 -> reverse(s.begin(), s.size() - k)     // NOTE: last value is excluded..
                432165
                561234  -> reverse(s.begin()), s.end())
                
        // Writing function that add at every odd position in given string...
            - first make that character into integer & then add 'b' & make sure to round it, After everything convert it into character.
    
    // Idea: 
        - Start with given string.
        - Try rotating
            - After that we will get new string -> now apply same procedure.
        - Try adding
            - After that we will get new string -> now apply same procedure.
        - In, Simple we will perfrom two operations every time(adding & rotating) & we will keep doing it until we will not generate all the sequence & from all the sequence we will return the minimum one..
        - It's more like from all the generated string we are exploring all the path & try getting the minimum one..
        - It's sounds like DFS/BFS generally graph type questions...


    // Solution:
        - Start with given string
        - Try rotating:
            - If it's not available, we can make future operations on this newly generated string & try making lexicographically smaller.
        - Try Adding:
            - If it's not available, we can make future operations on this newly generated string & try making lexicographically smaller.
        - At, every time try getting the smaller generated string.


    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n;
    string rightRotateByK(string word, int k) { // Function to right rotate string by 'k',  TC: O(n)
        string s = word;
        k = k % n;  // round the k within 'n', to make it in range..
        reverse(s.end() - k, s.end());
        reverse(s.begin(), s.end() - k);
        reverse(s.begin(), s.end());
        return s;
    }
    string fillOddPlace(string s, int a) {  // Add all odd place of string by given number, TC: O(n)
        for(int i = 0; i < n; i++) {
            if(i % 2 != 0) {
                s[i] = ((s[i] - '0' + a) % 10)+ '0';  // round it by 10 so that it should go after 9 -> 0
            }
        }

        return s;
    }
public:
    string findLexSmallestString(string s, int a, int b) {      // TC: O(n^2)
        n = s.size();

        queue<string> q;    // We will use queue to process all the possibly generated strings.
        unordered_set<string> vis;  // Visited is used to generate only unique string, TC: O(1)

        q.push(s);
        vis.insert(s);

        string minS = s;
        while(!q.empty()) { // TC: O(n * n)
            string curr = q.front();
            q.pop();

            minS = min(minS, curr); // Get the minimum, comparing it with previous ones

            // Try Converting current string into (rotate & add), & check wether it's already available
            string rot = rightRotateByK(curr, b);   // TC: O(n)
            if(!vis.count(rot)) {
                vis.insert(rot);
                q.push(rot);
            }
            
            string add = fillOddPlace(curr, a);     // TC: O(n)
            if(!vis.count(add)) {
                vis.insert(add);
                q.push(add);
            }
        }

        return minS;    // return the minimum string
    }
};