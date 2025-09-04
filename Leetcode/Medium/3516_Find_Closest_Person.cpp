/*

//  3516. Find Closest Person


//  Problem Statement: 
    -> You are given three integers x, y, and z, representing the positions of three people on a number line:
        -> x is the position of Person 1.
        -> y is the position of Person 2.
        -> z is the position of Person 3, who does not move.
    -> Both Person 1 and Person 2 move toward Person 3 at the same speed.
    -> Determine which person reaches Person 3 first:
        -> Return 1 if Person 1 arrives first.
        -> Return 2 if Person 2 arrives first.
        -> Return 0 if both arrive at the same time.
    -> Return the result accordingly.

    
// Example:
    Example 1:
        Input: x = 2, y = 7, z = 4
        Output: 1
        Explanation:
            Person 1 is at position 2 and can reach Person 3 (at position 4) in 2 steps.
            Person 2 is at position 7 and can reach Person 3 in 3 steps.
            Since Person 1 reaches Person 3 first, the output is 1.

    Example 2:
        Input: x = 2, y = 5, z = 6
        Output: 2
        Explanation:
            Person 1 is at position 2 and can reach Person 3 (at position 6) in 4 steps.
            Person 2 is at position 5 and can reach Person 3 in 1 step.
            Since Person 2 reaches Person 3 first, the output is 2.

    Example 3:
        Input: x = 1, y = 5, z = 3
        Output: 0
        Explanation:
            Person 1 is at position 1 and can reach Person 3 (at position 3) in 2 steps.
            Person 2 is at position 5 and can reach Person 3 in 2 steps.
            Since both Person 1 and Person 2 reach Person 3 at the same time, the output is 0.


// Observations: 
    -> Given 3 integer x, y, & z
    -> x is the position of person 1
    -> y = 2
    -> z = 3

    -> person x & y move towards person z with same speed
    -> Determine which persion reach person 3 first
    -> Return 1 if person arrive first or 2 if person 2 arrives first
    -> return 0 if both arrive at same time.

    -> Ex: 1

            x      (z)          y
        |---|---|---|---|---|---|---|---|----|
        1   2   3   4   5   6   7   8   9   10

        abs(z - y) =>  3
        abs(z - x) =>  2    -> 1 Wins 

    -> Ex: 2

            x           y  (z)
        |---|---|---|---|---|---|---|---|----|
        1   2   3   4   5   6   7   8   9   10


        abs(z - y) =>  1    -> 2 Wins 
        abs(z - x) =>  3

    -> Ex: 3

        x      (z)      y
        |---|---|---|---|---|---|---|---|----|
        1   2   3   4   5   6   7   8   9   10


        abs(z - y) =>  2
        abs(z - x) =>  2

            No-One wins => Return 0

// Approach: 
    -> the one who has lesser distance to reach 'Z' return that.


    // Complexity: 
        -> TC: O(1)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findClosest(int x, int y, int z) {
        int f = abs(x - z);
        int s = abs(y - z);

        if(f < s) return 1;
        else if (f > s) return 2;
        else return 0;
    }
};