/*

//  3074. Apple Redistribution into Boxes


//  Problem Statement: 
    - You are given an array apple of size n and an array capacity of size m.
    - There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
    - Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
    - Note that, apples from the same pack can be distributed into different boxes.

 
// Example:
    Example 1:
        Input: apple = [1,3,2], capacity = [4,3,1,5,2]
        Output: 2
        Explanation: We will use boxes with capacities 4 and 5.
        It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.

    Example 2:
        Input: apple = [5,5,5], capacity = [2,4,2,7]
        Output: 4
        Explanation: We will need to use all the boxes.

        
// Observations:
    - as we are allowed to distribute apples from the same pack, means apples[i] -> distributes into multiple capacity box..
    - sums up all the apples
    - sort the given capacity in descending order.
    - iterate, count, & subtract apples, when it's get less equal '0' break


// Complexity:  
    - TC: O(n + m * log m)
        - n = apple.size()
        - m = capacity.size()
    - SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int totalApples = accumulate(begin(apple), end(apple), 0);  // get the sum of all the apple.

        sort(rbegin(capacity), rend(capacity));

        int box = 0;
        for(auto &c: capacity) {
            if(totalApples <= 0) break;

            totalApples -= c;
            box++;
        }

        return box;
    }
};