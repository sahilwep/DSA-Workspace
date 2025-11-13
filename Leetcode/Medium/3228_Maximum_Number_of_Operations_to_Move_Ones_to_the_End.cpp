/*

//  3228. Maximum Number of Operations to Move Ones to the End


//  Problem Statement: 
    -> You are given a string s.
    -> You can perform the following operation on the string any number of times:
        -> Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
        -> Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
    -> Return the maximum number of operations that you can perform.

 
// Example: 
    Example 1:
        Input: s = "1001101"
        Output: 4
        Explanation: We can perform the following operations:
            Choose index i = 0. The resulting string is s = "0011101".
            Choose index i = 4. The resulting string is s = "0011011".
            Choose index i = 3. The resulting string is s = "0010111".
            Choose index i = 2. The resulting string is s = "0001111".

    Example 2:
        Input: s = "00111"
        Output: 0

 
// Observations: 
    - choose the index: 
        s[i] = '1' && s[i + 1] == '0'
    - move the character s[i] to right until it reaches the end of the string or another '1'.

    // Bruteforce Approach:
        - Implement the given conditions
        - TLE

    // Optimizations: 
        - We can observe that 1's crosses the 0's if we have '0' on right of '1'
        - from this observations,
            - For every '0' occur, we will have to cross all the 1's from left side to right side of that 0's
            - means we will count the left side of '1' & whenever we have '0' we will include those 1's into our answer.
        - From this approach, we can build our answer..

        // Complexity: 
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimal Solution: O(n)
class Solution {
private: 
    int n;
public:
    int maxOperations(string s) {
        n = s.size();

        int opr = 0;
        int oneCnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') oneCnt++;
            else {  // '0' case:
                if(i == 0 || s[i - 1] == '1') {
                    opr += oneCnt;
                }
            }
        }
        
        return opr;
    }
};


// BruteForce Solution:
class Solution {
private: 
    int n;
    bool isAllGood(string &s) {
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '1' && s[i + 1] == '0') {
                return false;
            }
        }

        return true;
    }
public:
    int maxOperations(string s) {
        n = s.size();

        // Edge case: check if all the given configurations is correct ?
        if(isAllGood(s)) return 0;

        int cnt = 0;
        while(true) {
            // Check & move the element:
            for(int i = 0; i < n - 1; i++) {
                int j = i;
                bool flag = false;
                
                if(j < n - 1 && s[j] == '1' && s[j + 1] == '0') {   // Check the conditions to move
                    while(j < n - 1 && s[j] == '1' && s[j + 1] == '0') {    // move elements
                        swap(s[j], s[j + 1]);
                        j++;
                    }

                    if(j < n - 1 && s[j] == '1' && s[j + 1] == '1') {    // After than, check if we reach any '1', break out
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }

            cnt++;  // increment counter
            // cout << s << endl;   // debugging

            // Last check if needed configurations is done: => exit
            if(isAllGood(s)) break;
        }
        
        return cnt;
    }
};