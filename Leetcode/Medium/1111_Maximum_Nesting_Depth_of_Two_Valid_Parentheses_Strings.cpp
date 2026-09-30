/*

//  1111. Maximum Nesting Depth of Two Valid Parentheses Strings


//  Problem Statement: 
    - A string is a valid parentheses string (denoted VPS) if and only if it consists of "(" and ")" characters only, and:
        - It is the empty string, or
        - It can be written as AB (A concatenated with B), where A and B are VPS's, or
        - It can be written as (A), where A is a VPS.

    - We can similarly define the nesting depth depth(S) of any VPS S as follows:
        - depth("") = 0
        - depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
        - depth("(" + A + ")") = 1 + depth(A), where A is a VPS.

    - For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.
    - Given a VPS seq, split it into two disjoint subsequences A and B, such that A and B are VPS's (and A.length + B.length = seq.length). The subsequences may not necessarily be contiguous.
    - For example, for the sequence 123456789, one possible split is:
        A = {1, 3, 5, 7, 9},
        B = {2, 4, 6, 8}.

    - This corresponds to the output [0, 1, 0, 1, 0, 1, 0, 1, 0]  where 0 indicates membership in A and 1 indicates membership in B.
    - Now choose any such A and B such that max(depth(A), depth(B)) is the minimum possible value.
    - Return an answer array (of length seq.length) that encodes such a choice of A and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that even though multiple answers may exist, you may return any of them.

    
    // Example:
        Example 1:
            Input: seq = "(()())"
            Output: [0,1,1,1,1,0]

        Example 2:
            Input: seq = "()(())()"
            Output: [0,0,0,1,1,0,1,1]
            
    // Constraints:
        1 <= seq.size <= 10000

    

// Observations:
        // In Simple: 
            - VPS is ()
            - Depth:
                    () = 1
                    (()) = 2, inside () is 1 depth, and out side is (A) so total max(insideDepths) + 1

            - We are given VPS string, and we will have to break them into two disjoint subsequence:
                - such that:
                    - A and B both are valid parenthesis
                    - and A.len + B.len = seq.length.
                    - IT IS NOT NECESSARY WE PICK CONTIGIOUS SEQUENCE, WE MAY PICK ""SUBSEQUENCE""

                - 0 => indicate membership of A
                - 1 => indicate membership of B

            - Maximum of max(depth(a), depth(b)) must be minimum possible value.

        Eg: 
            "( ( ) ( ) )"
             0 1 2 3 4 5

                Optimally:

                         G1     |     G2
                        ( )     |   ( ) ( )     
                        0 5     |   1 2 3 4
            depth:      max(A)       max(A, B)
                        1           max(1, 1) = 1

                        Here depth is minimum.

        // Approach:
            - For every parenthesis:
                - we will have to decide where we should place:
                    - if:
                        group 1: depth1
                    - if:
                        group 2: depth2
                    -----------------------
                    we will place where the depth is minimum.

                - and when we have any ')' we will place it into the group, and calculate their depth.

            // Function to calculate the depth:
                - we already solve problem of calculating the depth:
                - we will maintain two variable, open and close:
                    - and count while iterating:
                    - when it's open: increment the count
                    - when it's close: decrement the count.

                            ( ( ) )
                            1 2 1 0
                                            depth = 2

                            ( ) ( ( ) ) ( )
                            1 0 1 2 1 0 1 0

                                            depth = 2

                    - at the end we will check if cnt == 0: means VPS
                        - and we while iterating we will store the max_Cnt, as their depth.

            - Now, our job is to greedily check where should the current '(' should go in first group or in second group?
            - and from wherever we get the minimum-> we will place it there.
            - and accordingly we will build the answer.
            

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        vector<int> ans(n, 0);
        int dep = 0;
        for(int i = 0; i < n; i++) {
            char c = seq[i];

            if(c == '(') {
                dep++;
                ans[i] = dep % 2;
            } else {
                ans[i] = dep % 2;
                dep--;
            }
        }

        return ans;
    }
};