/*

// 22. Generate Parentheses

// Problem: 
    - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 
// Example: 
    Example 1:
        Input: n = 3
        Output: ["((()))","(()())","(())()","()(())","()()()"]
    
    Example 2:
        Input: n = 1
        Output: ["()"]
 

    Constraints:
        1 <= n <= 8


// observations:
    - while generating parenthesis, we have to make sure open brackets >= closed one..
    - when open == n and closed == n:
        - thats exactly we say we have generated all parenthesis...
    - decision tree:
        - if open >= closed and open <= n:
            - two choices: 
                - add open
                - add closed
                
                for open: 
                   backtrack logic..
                
                for closed:
                   first we have to check string should not be empty:
                   - because, we can't insert closed first....
        
    - implement using recursive and backtracking logic...
    
    // Complexity:
        - TC: O(2^n)
        - SC: O(2^n)
    
    - all testcase passed, as it's recursive solution taking 2^n complexity...


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    vector<string> ans;
    vector<vector<int>> t;
    void solve(int n, int o, int c, string& s) {
        // base case: when open == closed == equal to n
        if(o == n && c == n) {
            ans.push_back(s); // insert that seq to our answer..
            return; // return back.
        }

        // If open count is grater or equal to c, and it's less or equal to n
        if(o >= c && o <= n) {
            // Two choices: '(' or ')'
            
            // Open Insert
            s.push_back('(');
            solve(n, o + 1, c, s);
            s.pop_back();

            // closed insert
            if(!s.empty()) {
                s.push_back(')');
                solve(n, o, c + 1, s);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        
        string s = "";
        solve(n, 0, 0, s);

        return ans;
    }
};