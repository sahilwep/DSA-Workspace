/*
// Left rotate the array by one place : 

    arr[] { 1 2 3 4 5 }
          { 2 3 4 5 1 } final array : 

// Optimal Solution : 
    * store the first element in temp
    * we can use the loop & from index 1 we can place the each element one place before.
    * after the loop finish, we will place the temp element in (n-1) place.
    
// TC : O(n)
// SC : O(1)
    // but if we ask the space use to solve a problem is O(n), because we are using an array to solve the problem.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void leftRotateOne(int arr[], int n){
        int temp = arr[0];  // store the first element in temp.
        for(int i=1;i<n;i++){
            arr[i-1] = arr[i];  // place element one place before.
        }    
        arr[n-1] = temp;    // store the first element in last.
    }
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
        obj.leftRotateOne(arr, n);
        for(auto i : arr) cout << i << " ";
        cout << endl;
    }
    return 0;
}