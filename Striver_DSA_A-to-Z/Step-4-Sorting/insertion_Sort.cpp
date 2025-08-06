/*

//  Insertion Sort | Sorting

//  Problem Statement: 
    -> Given an array arr[] of positive integers.The task is to complete the insertsort() function which is used to implement Insertion Sort.

// Examples:
    Input: arr[] = [4, 1, 3, 9, 7]
    Output: [1, 3, 4, 7, 9]
    Explanation: The sorted array will be [1, 3, 4, 7, 9].

    Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    Explanation: The sorted array will be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].

    Input: arr[] = [4, 1, 9]
    Output: [1, 4, 9]
    Explanation: The sorted array will be [1, 4, 9].


// Insertion Sort: 
    -> Select every element
    -> Place it their correct position
    

    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int j = i;  // for every element:

            while(j > 0 && arr[j-1] > arr[j]) { // place it to their correct position
                swap(arr[j-1], arr[j]);
                j--;
            }
        }
        
    }
};