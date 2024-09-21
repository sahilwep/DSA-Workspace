/*

//  Median of Two Sorted Arrays

//  Observations: 
    * we are given two sorted array of size n, & m, we need to merge these two array & find the median of the array.
    * Median: median is middle value.
    * NOTE: if the size of the n + m is odd, return the middle element, else return the (middle + next middle)/2 th element.


// Intrusion:
    // Using merge function: 
        * First we will merge both the array into single array.
        * Then we will check the size of merged array:
            // * if the size of merged array is odd, return middle element
            * if the size of merged array is even, return the ((middle + middle_next) / 2)th element.
        * TC: O(n+m)
        * AS: O(n+m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr, vector<int>& brr) {
        
        // Step 1: First merge both the array
        int n = arr.size();
        int m = brr.size();
        vector<int> res(n+m);

        int k = 0;
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < n && ptr2 < m){
            if(arr[ptr1] < brr[ptr2]){
                res[k++] = arr[ptr1++];
            }
            else{
                res[k++] = brr[ptr2++];
            }
        }
        // storing leftover
        while(ptr1 < n){
            res[k++] = arr[ptr1++];
        }
        while(ptr2 < m){
            res[k++] = brr[ptr2++];
        }

        // Returning the middle element:
        int size = res.size();
        // If the size is even, get two values & then return the sum / 2 of it.
        if(size % 2 == 0){
            float mid = (res[size/2] + res[size/2 - 1]) / 2.0;
            return mid;
        }
        // else return the middle element
        else{
            return res[size/2];
        }
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> brr(m);

    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<m;i++) cin >> brr[i];

    Solution obj;
    cout << fixed << setprecision(5)  << obj.findMedianSortedArrays(arr, brr) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}