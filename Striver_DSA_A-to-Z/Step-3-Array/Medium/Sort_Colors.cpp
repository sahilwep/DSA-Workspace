/*

// 75. Sort Colors


// Observations: 
    * We are given an array that contains 3 different types of values, '1', '2', & 3'
    * We need to sort them in order so that it should be in ascending order..

// Example:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Input: nums = [2,0,1]
    Output: [0,1,2]

    

// Intrusion: 
    // Storing frequency Approach: 
        * first we will store the frequency of all the values(as we are restricted to only 3 values, so it's easy for us to hash them).
        * IF we have multiple values we can hash it by using map data structure.
        * after that we can assign the values in an array by frequency times.
        * TC: O(n)
        * AS: O(1)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int zero = 0, one  = 0, two = 0;
        for(auto i : arr){
            if(i == 0)  zero++;
            else if(i == 1) one++;
            else two++;
        }
        int i = 0;
        while(zero > 0){
            arr[i++] = 0;
            zero--;
        }
        while(one > 0){
            arr[i++] = 1;
            one--;
        }
        while(two > 0){
            arr[i++] = 2;
            two--;
        }
    }
};