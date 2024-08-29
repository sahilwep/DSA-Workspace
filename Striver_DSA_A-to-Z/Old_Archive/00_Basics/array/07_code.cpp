/*
// Reversal of an array.

*/


#include <bits/stdc++.h>
using namespace std;

void revArray(int arr[], int n){
    
    /* Simple method : 
    int start = 0;
    int end = n-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    */
   for(int i=0;i<n/2;i++){
        swap(arr[i], arr[n-1-i]);
   }
}

int main(void){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        revArray(arr, n);
        for(auto i : arr) cout << i << " ";

    }


    return 0;
}