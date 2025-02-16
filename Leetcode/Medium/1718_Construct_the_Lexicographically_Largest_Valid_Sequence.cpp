/*

//  1718. Construct the Lexicographically Largest Valid Sequence


//  Problem Statement: 
    -> Given an integer n, find a sequence that satisfies all of the following:
        -> The integer 1 occurs once in the sequence.
        -> Each integer between 2 and n occurs twice in the sequence.
        -> For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
    -> The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
    -> Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
    -> A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 
// Example:
    Example 1:

        Input: n = 3
        Output: [3,1,2,3,2]
        Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.

    Example 2:

        Input: n = 5
        Output: [5,3,1,4,3,5,2,4,2]



// Observations:
    -> We need to construct an array following the given constraints while ensuring it is lexicographically largest.
    -> The number '1' appears exactly once.
    -> Numbers from '2' to 'n' appear exactly twice, maintaining a distance of 'num' between occurrences.
    -> The sequence must have a total length of (2 * n - 1).
    -> To ensure the lexicographically largest sequence, we start filling from the largest number.
    -> We must carefully track the placement of numbers and maintain valid distances.
    -> For each number 'num' at index 'i', its second occurrence should be placed at index 'j = i + num'.
    -> A boolean vector 'used' (size n+1) is maintained to track which numbers are placed.
    -> If placing a number at index 'i' is not possible, we try the next largest available number.
    -> Backtracking is used to explore different possibilities efficiently.

// Complexity:
    -> TC: O(n!)
    -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool solve(int i, int n, vector<int> &result, vector<int> &used) {
        if (i >= result.size()) {
            return true; // Successfully filled the sequence.
        }
        if (result[i] != -1) { // Skip already populated indices.
            return solve(i + 1, n, result, used);
        }

        // Try placing numbers from largest to smallest.
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue; // Skip if the number is already used.

            // Place the first occurrence of 'num'.
            used[num] = true;
            result[i] = num;

            if (num == 1) { // '1' appears only once.
                if (solve(i + 1, n, result, used)) return true;
            } else {
                int j = i + num; // Compute second occurrence index.

                // Ensure 'j' is within bounds and unoccupied.
                if (j < result.size() && result[j] == -1) {
                    result[j] = num;
                    if (solve(i + 1, n, result, used)) return true;
                    result[j] = -1; // Backtrack if unsuccessful.
                }
            }

            // Undo placement (backtracking).
            used[num] = false;
            result[i] = -1;
        }

        return false; // No valid sequence found from this state.
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, -1); // Initialize result array with -1.
        vector<int> used(n + 1, false);    // Track used numbers.
        solve(0, n, result, used);

        return result;
    }
};
    