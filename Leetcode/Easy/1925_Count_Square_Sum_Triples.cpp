/*

//  1925. Count Square Sum Triples


//  Problem Statement: 
    - A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
    - Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

 
// Example:
    Example 1:
        Input: n = 5
        Output: 2
        Explanation: The square triples are (3,4,5) and (4,3,5).

    Example 2:
        Input: n = 10
        Output: 4
        Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).


// Observations: 
    - Implement the given statement.

    // Complexity: 
        - TC: O(n^3)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    int left = i * i + j * j;
                    int right = k * k;
                    if(left == right) ans++;
                }
            }
        }

        return ans;
    }
};