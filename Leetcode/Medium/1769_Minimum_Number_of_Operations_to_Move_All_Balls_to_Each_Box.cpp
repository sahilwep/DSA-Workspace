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


// Solution 1:
    -> For every index find left side operations & right side operations & count it.
    -> TC: O(n^2)





*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Solution 1:
class Solution {
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