/*

//  2657. Find the Prefix Common Array of Two Arrays


//  Problem Statement: 
    -> You are given two 0-indexed integer permutations A and B of length n.
    -> A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
    -> Return the prefix common array of A and B.
    -> A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 
// Example:

    Example 1:
        Input: A = [1,3,2,4], B = [3,1,2,4]
        Output: [0,2,3,4]
        Explanation: At i = 0: no number is common, so C[0] = 0.
        At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
        At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
        At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

    Example 2:
        Input: A = [2,3,1], B = [3,1,2]
        Output: [0,1,3]
        Explanation: At i = 0: no number is common, so C[0] = 0.
        At i = 1: only 3 is common in A and B, so C[1] = 1.
        At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3. 


// Constraints:
    1 <= A.length == B.length == n <= 50
    1 <= A[i], B[i] <= n
    It is guaranteed that A and B are both a permutation of n integers.



// Observation:

            Input: A = [1, 3, 2, 4], B = [3, 1, 2, 4]
            Output: [0, 2, 3, 4]
            Explanation: 
            At i = 0: No number is common, so C[0] = 0.
            At i = 1: Numbers 1 and 3 are common in A and B, so C[1] = 2.
            At i = 2: Numbers 1, 2, and 3 are common in A and B, so C[2] = 3.
            At i = 3: Numbers 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

        -> As per the question, we need to find the count of elements that occur in both arrays up to every index.
        -> We can use a set to check whether an element has been processed before.
        -> For each array, we will determine if an element has already been processed:
            -> If the element has been processed before, increment the counter.
            -> Similarly, check for the other array.
        -> At the end of every iteration, update the result array with the total count seen so far.



// Complexity:
    -> Time Complexity (TC): O(n)
    -> Auxiliary Space (AS): O(n)
    



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result;      // Array to store the final result
        unordered_set<int> seen; // Set to keep track of processed elements for O(1) lookup

        int commonCount = 0; // Counter to track the number of common elements seen so far
        for (int i = 0; i < n; i++) {
            // Check if the current element of the first array exists in the set
            if (seen.find(A[i]) != seen.end()) {
                commonCount += 1; // Increment the count as the element is already processed
            } else {
                seen.insert(A[i]); // Add the element to the set
            }

            // Check if the current element of the second array exists in the set
            if (seen.find(B[i]) != seen.end()) {
                commonCount += 1; // Increment the count as the element is already processed
            } else {
                seen.insert(B[i]); // Add the element to the set
            }

            // Update the result array with the current count of common elements
            result.push_back(commonCount);
        }

        return result;
    }
};
