/*

//  3577. Count the Number of Computer Unlocking Permutations


//  Problem Statement: 
    - You are given an array complexity of length n.
    - There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].
    - The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:
        - You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
        - To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].
    - Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.
    - Since the answer may be large, return it modulo 109 + 7.
    - Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.

 
// Example:
    Example 1:
        Input: complexity = [1,2,3]
        Output: 2
        Explanation: The valid permutations are:
            [0, 1, 2]
                Unlock computer 0 first with root password.
                Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
                Unlock computer 2 with password of computer 1 since complexity[1] < complexity[2].
            [0, 2, 1]
                Unlock computer 0 first with root password.
                Unlock computer 2 with password of computer 0 since complexity[0] < complexity[2].
                Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].

    Example 2:
        Input: complexity = [3,3,3,4,4,4]
        Output: 0
        Explanation: There are no possible permutations which can unlock all computers.


// Observations: 
    - Given Conditions: 

                complexity[i] < complexity[j],  i < j   -> then only we can unlock the computer [j]

                computer[0] is already unlocked..
                

    - element at index[0] should be lesser than all the others elements, to satisfies the given conditions to unlock any computer
    - index[0] computer is already unlocked..
    - If index[0] element is smallest among all: 
            - it can easily unlock all the computers, because all of them are greater,
            - first index[0] is reserved we can fill only 1 computer.
            - now all we need to fill is (n - 1) computers..

                    0       1,         2,       3,...
                    1, (n - 1)p, (n - 2)p, (n - 3)p...
            
            - at index[1], we can fill (n - 1) remaining computer & generate the permutations.
            - at index[2], we can fill (n - 2) remaining computer & generate the permutations..
            - similarly we can do for rest..

                    0       1       2       3
                    1 * (n - 1) * (n - 2) * (n - 3),...

                    In simple we can say (n - 1) factorial

            - return (n - 1)! factorial, 

    - else: return 0, as ther's no possible way to unlock.

    
    // Complexity: 
        - TC: O(n)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int mod = 1e9 + 7;
public:
    int countPermutations(vector<int>& complexity) {
        
        int n = complexity.size();

        // Generate factorial:
        int res = 1;
        for(int i  = 1; i < n; i++) {   // compute all the n - 1 elements factorial => TC: O(n)
            if(complexity[i] <= complexity[0]) return 0; // not possible

            res = (1LL * res * i) % mod;
        }
        
        return res; // -> (n - 1)!
    }
};