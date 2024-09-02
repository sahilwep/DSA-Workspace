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
    // Approach 1: Storing frequency Approach: 
        * first we will store the frequency of all the values(as we are restricted to only 3 values, so it's easy for us to hash them).
        * IF we have multiple values we can hash it by using map data structure.
        * after that we can assign the values in an array by frequency times.
        * TC: O(n)
        * AS: O(1)

    // Approach 2: Using map data structure: 
        * We can use hashmap to store the frequency
        * after that we can overwrite the array by 
        * TC: O(n)
        * AS: O(n)
    
    // Approach 3: Using Sorting:
        * We can simply sort all the values, we can use sort() function.
        * TC: O(nlogn)
        * AS: O(n)


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Approach 1: Storing frequency Approach:
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

    // Approach 2: Using Hashing:
    // function is used to write the values in array
    void write(vector<int> &arr, int x, int start, int end){
        for(int i=start;i<=end;i++){
            arr[i] = x;
        }
    }
    void sortColors_(vector<int>& arr) {
        // hashing the frequency:
        map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        // writing values into the array:
        int j = 0;  // starting index:
        for(auto i : mp){
            // starting index will be j, & ending index will be (i.second + j - 1), (-1 is used to remove extra count at every time.)
            write(arr, i.first, j, (i.second + j - 1));
            j += i.second;
        }
    }

};