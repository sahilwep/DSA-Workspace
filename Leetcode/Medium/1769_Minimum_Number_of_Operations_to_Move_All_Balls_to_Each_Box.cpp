/*

//  1769. Minimum Number of Operations to Move All Balls to Each Box


//  Problem Statement:
    -> You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
    -> In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
    -> Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
    -> Each answer[i] is calculated considering the initial state of the boxes.

 

// Example:

    Example 1:
        Input: boxes = "110"
        Output: [1,1,3]
        Explanation: The answer for each box is as follows:
        1) First box: you will have to move one ball from the second box to the first box in one operation.
        2) Second box: you will have to move one ball from the first box to the second box in one operation.
        3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

    Example 2:
        Input: boxes = "001011"
        Output: [11,8,5,4,3,4]


// BruteForce Solution:
    -> For every index find left side operations & right side operations & count it.
    -> TC: O(n^2)



// Efficient Solution:

        // Example:
            
                Input: boxes = "001011"
                Output: [11,8,5,4,3,4]

            // Observe the pattern: 

                    "0 0 1 0 1 1"
                     
                    for i = 0: 
                        minimum number of operations: 2 + 4 + 5 = 11
                    
                    for i = 1: 
                        minimum number of operations: 1 + 3 + 4 = 8
                    
                    for i = 2:
                        minimum number of operations: 2 + 3 = 5
                    
                    ... 
                        so on..
            
                If we take Commutative Count of 1's, because we need only 1's count as per the questions:
                    
                    Generate Commutative Count from right to left:
                        "0 0 1 0 1 1"   -> String
                         3 3 3 2 2 1    -> Commutative Count from right to left
                         | 
                         i = 0
                                -> For this index i = 0, if we count all the Commutative count of right side:
                                -> For i = 0: (3 + 3 + 2 + 2 + 1) = 11 -> Same as we get.


                        "0 0 1 0 1 1"   -> String
                         3 3 3 2 2 1    -> Commutative Count from right to left
                           | 
                           i = 1
                                -> For this index i = 1, if we count all the Commutative count of right side:
                                -> For i = 1: (3 + 2 + 2 + 1) = 8

                        "0 0 1 0 1 1"   -> String
                         3 3 3 2 2 1    -> Commutative Count from right to left
                             | 
                            i = 2
                                -> For this index i = 2, if we count all the Commutative count of right side:
                                -> For i = 2: (2 + 2 + 1) = 5

                        "0 0 1 0 1 1"   -> String
                         3 3 3 2 2 1    -> Commutative Count from right to left
                               | 
                               i = 3
                                -> For this index i = 3, if we count all the Commutative count of right side:
                                -> For i = 3: (2 + 1) = 3
                                -> But we also need the Commutative Count from left to right
                                -> If we generate Commutative Count from left to right then:
                                    "0 0 1 0 1 1"   -> String
                                     0 0 1 1 2 3    -> Commutative Count from left to right
                                           |
                                           i = 3
                                -> Now add Commutative Count from left to right also:
                                -> For i = 3: (1) = 1
                                -> Total Sum = (1) + (2 + 1) = 4 -> this much we need...

                        Similarly, we will compute for all indices

                        // Observing the pattern:
                            -> We need to generate Prefix Count & Suffix Count..
                            -> then we need to generate sum of prefix Count & suffix Count
                            -> and last for every answer of 'i' take prefixSum[i-1] + suffixSum[i+1]                     

            -> If we build Commutative count of 1's from left to right & from right to left.
            -> Then we will Build Commutative Sum of Commutative count array for left to right & for right to left.
            -> At end for every ans[i], we will take CommutativeLeftTORight[0 to i-1] + CommutativeRightToLeft[i+1 to n]

// Approach Overview:
    -> The core idea is to calculate the cumulative cost of moving all '1's to each index using two arrays:
        -> Prefix Array: Tracks the cumulative number of '1's from the start of the string to each index.
        -> Suffix Array: Tracks the cumulative number of '1's from the end of the string to each index.

    -> Using these, we derive:
        -> Prefix Sum Array: The total cost of moving all '1's from the left to a particular index.
        -> Suffix Sum Array: The total cost of moving all '1's from the right to a particular index.

    -> Finally, for each index ii, the result is calculated as:
                
                result[i] = PrefixSum[i−1] + SuffixSum[i+1]

    -> This efficiently combines the costs from the left and right of index i.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution_Eff {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        if(n == 1) return {0};  // Edge case: If there is only one box, no moves are required.

        // Step 1: Generate the Prefix array to count cumulative 1's from the left.
        vector<int> pref(n, 0);
        for(int i=0;i<n;i++){
            if(boxes[i] == '1'){
                if(i == 0){
                    pref[i] = 1;
                }else{
                    pref[i] += pref[i-1] + 1;
                }
            }else{
                pref[i] = (i > 0) ?  pref[i-1] : 0;
            }
        }

        // Step 2: Generate the Suffix array to count cumulative 1's from the right.
        vector<int> suff(n, 0);
        for(int i=n-1;i>=0;i--){
            if(boxes[i] == '1'){
                if(i == n-1){
                    suff[i] = 1;
                }else{
                    suff[i] += suff[i+1] + 1;
                }
            }else{
                suff[i] = (i < n-1) ? suff[i+1] : 0;
            }
        }

        // Step 3: Generate Prefix Sum and Suffix Sum arrays. Prefix Sum stores the cumulative cost to move all '1's from the left.
        vector<int> prefSum(n, 0);
        prefSum[0] = pref[0];
        for(int i=1;i<n;i++){
            prefSum[i] = prefSum[i-1] + pref[i];
        }

        vector<int> suffSum(n, 0);
        suffSum[n-1] = suff[n-1];
        for(int i=n-2;i>=0;i--){
            suffSum[i] = suffSum[i+1] + suff[i];
        }


        // Step 4: Compute the result array. `res[i]` will store the total moves needed for box `i`.
        // For every i, get the prefsum[0 to i-1] & suffSum[i+1 to n]
        vector<int> res(n, 0);

        for(int i=0;i<n;i++){
            if(i == 0){
                res[0] = suffSum[1];
            }
            else if(i == n-1){
                res[n-1] = prefSum[n-2];
            }else{
                res[i] = prefSum[i-1] + suffSum[i+1];
            }
        }

        return res;
    }
};


// BruteForce Solution:
class Solution_Brute {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            // Calculate move for every box:
            int cnt = 0;
            for(int j=0;j<i;j++){   // computing left side:
                if(boxes[j] == '1'){
                    int steps = i - j;
                    cnt += steps;
                }
            }

            for(int j=i+1;j<n;j++){ // computing right side:
                if(boxes[j] == '1'){
                    int steps = j - i;
                    cnt += steps;
                }
            }
            res[i] = cnt;
        }
        
        return res;
    }
};