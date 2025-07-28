/*

//  Merge Sort: Divide & Merge || Divide & conquer


//  Problem Statement: 
    -> Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.


// Example:
    Examples:
        Input: arr[] = [4, 1, 3, 9, 7]
        Output: [1, 3, 4, 7, 9]
        Explanation: We get the sorted array after using merge sort

    Example:
        Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        Explanation: We get the sorted array after using merge sort 


// Approach: 
    -> merge Sort follows Divide & merge Approach
    -> To perform mergeSort we will be requiring two things: 
        -> Merge Functions
        -> MergeSort functions
    
    // Merge Functions: 
        -> This will merge the two given array
        -> Use temporary variable & merge two given array
    
    // MergeSort Functions:
        -> This will run recursively & dividing the array until we have single value left in array.
        -> We have given one single array, we need to divide it into two, make a middle point, split in recursive call until we not reach with single element


// Complexity: 
    -> TC: O(n * logn)
    -> SC: O(n)
        -> AS: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Merge Sort:
class Solution {
private: 
    void merge(vector<int>& arr, int low, int mid, int high) {
        
        vector<int> temp;   // create temporary array
        int left = low;     // first array positions start from low idx
        int right = mid + 1;    // second array position start from mid + 1 idx
        
        // Until both the pointers exceeds the limit:
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        
        // Store left-Over array that were left in above iterations:
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        
        // Overwrite original array:
        int k = 0;
        for(int i = low; i <= high; i++) {
            arr[i] = temp[k++]; // subtract 
            // arr[i] = temp[i - low]; // or we can use this logic also
        }
    }
public:
    void mergeSort(vector<int>& arr, int low, int high) {
        
        // Base case: 
        if(low >= high) return; // when the pointers exceeds themselves, return
        
        // Split the array into recursive calls until we have one value left & last merge them:
        int mid = (low + high )/ 2; // get the middle half point from single array to make it two individual array
        
        mergeSort(arr, low, mid);       // first half array
        mergeSort(arr, mid + 1, high);  // second half array
        
        merge(arr, low, mid, high);   // last merge the values
    }
};