/*

//  1551. Minimum Operations to Make Array Equal



//  Problem Statement: 
    -> You have an array arr of length n where arr[i] = (2 * i) + 1 for all valid values of i (i.e., 0 <= i < n).
    -> In one operation, you can select two indices x and y where 0 <= x, y < n and subtract 1 from arr[x] and add 1 to arr[y] (i.e., perform arr[x] -=1 and arr[y] += 1). The goal is to make all the elements of the array equal. It is guaranteed that all the elements of the array can be made equal using some operations.
    -> Given an integer n, the length of the array, return the minimum number of operations needed to make all the elements of arr equal.

 

// Example:
    Example 1:
        Input: n = 3
        Output: 2
        Explanation: arr = [1, 3, 5]
        First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
        In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].


// Patterns:
        -> Array can be build with arr[i] = (i * 2) + 1

        n = 3
            Initial Array: 1 3 5
              |
             mid = (n/2)


        n = 4
            Initial Array: 1 3 5 7
            |
            mid = (n/2)

                1 3 5 7
                  |
                2 3 5 6
                3 3 5 5
                3 3 4 4
                3 3 3 3

                    // Observe More:
                        3 1 1 3 -> Total number of steps for every index
                        | | | |
                        1 3 5 7 -> Original Array
                          | | 
                        1 4 4 7     Move - 1
                        2 4 4 6     Move - 2
                        3 4 4 5     Move - 3
                        4 4 4 4     Move - 4

                        => Means => total steps: 1 + 3 = 4


        n = 5
            Initial Array: 1 3 5 7 9

                1 3 5 7 9 -> Initial array:

                4 2   2 4
                2 3 5 7 8
                3 3 5 7 7
                4 3 5 7 6
                5 3 5 7 5
                5 4 5 6 5
                5 5 5 5 5

        n = 6
            Initial Array: 1 3 5 7 9 11
                            5 3 1 1 3 5
                            1 3 5 7 9 11
                                | |
                                6 6
                              4 6 6 8
                              5 6 6 7
                              6 6 6 6
                            2 6 6 6 6 10
                            3 6 6 6 6 9
                            4 6 6 6 6 8
                            5 6 6 6 6 7
                            6 6 6 6 6 6

                if(Even):

                            => elementCnt = n / 2 times
                            => Total Steps: 
                                1 + 3 + 5
                                => Start with 1
                                => Every time increment till 2


        n = 7
            Initial Array: 1 3 5 7 9 11 13

                    6 4 2 0 2 4  6  -> Steps at every idx Value:
                    1 3 5 7 9 11 13 
                          |
                        6 7 8
                        7 7 7
                      4 7 7 7 10
                      ...
                      ...

                if(odd):
                                -> mid element => same element: 
                                7 / 2 = 3 -> left & right count of elements
                                2 + 4 + 6 = 12 -> Steps Required


// Complexity: 
    -> TC: O(n/2), as =>  O(n)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Clean Code:
class Solution {
public:
    int minOperations(int n) {
        int elementCnt = n / 2;
        int steps = 0;
        int incrVal = (n % 2 == 0) ? 1 : 2; // handel odd or even case & assign incremented value accordingly
        for(int i=0;i<elementCnt;i++){
            steps += incrVal;
            incrVal += 2;
        }

        return steps;
    }
};


// Naive Code:
class Solution {
public:
    int minOperations(int n) {
        if(n % 2 != 0){     // odd case:
            int elementCnt = n / 2;
            int steps = 0;
            int incrVal = 2;
            for(int i=0;i<elementCnt;i++){
                steps += incrVal;
                incrVal += 2;
            }
            return steps;
        }
        // even case:
        int elementCnt = n / 2;
        int steps = 0;
        int incrVal = 1;
        for(int i=0;i<elementCnt;i++){
            steps += incrVal;
            incrVal += 2;
        }

        return steps;
    }
};