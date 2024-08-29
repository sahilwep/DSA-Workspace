/*

// Sorted Array Search


// Observations: 
    * We are given an array of size n, & an integer k, we need to find whether k is present or not.
    * If element is present return 1, else return -1


// Intrusion: 
    // Linear Search
        * Iterate over the array & try to find element by comparing with each element.
        * TC: O(n)
        * AS: O(1)

    // Binary Search
        * Spliting the array into half, using greedy approach & finding in that side of array by again spliting into half, until we reach to the position.
        * NOTE: Binary search only works in sorted array.
        * TC: O(logn)
        * AS: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Linear Search:
    int searchInSorted_Linear(int arr[], int n, int k) {
        for(int i=0;i<n;i++){
            if(arr[i] == k) return 1;
        }
        return -1;
    }
    // Binary Search
    int searchInSorted(int arr[], int n, int k){
        int start = 0;
        int end = n-1;
        int mid = (start + end )/ 2;
        while(start <= end){
            if(arr[mid] == k) return 1;
            // if middle element is grater than k, we have to look on left
            else if(arr[mid] > k){
                end = mid - 1;
            }
            // if middle element is lesser than k, we need to look on rights
            else if(arr[mid] < k){
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        return -1;
    }

};

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;
    }

    return 0;
}