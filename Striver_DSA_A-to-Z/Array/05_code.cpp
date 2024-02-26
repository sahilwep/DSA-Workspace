/*
// check if the array is sorted ? 

    arr[] = { 1 2 2 3 4 4}      Sorted.
    arr[] = { 1 2 1 3 4 5}      Not Sorted.

    return 1, if sorted else return 0

    // TC : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkSorted(int arr[], int n){
        // starting from index 1 & go till n-1
        for(int i=1;i<n;i++){
            if(arr[i] >= arr[i-1]){
                // sorted
            }
            else{
                return false;
            }
        }
        return true;
    }
        // TC : O(n)
};


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        cout << obj.checkSorted(arr, n) << endl;
    }
    return 0;
}