/*
// Operations in an array Part 1 : 

// Search 
    * if element found then return their index else return -1

// Insert 

    I/p : arr[] = {5, 10, 20, _, _}
    x = 7
    pos = 2

    O/p : arr[] = {5, 7, 10, 20, _}

// insert at the end of dynamic size array : 
    * TC : O(1)

*/


#include<bits/stdc++.h>
using namespace std;

// TC : O(n)
int search(int arr[], int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i] == x) return i;
    }
    return -1;
}

// TC : O(n)
int insert(int arr[], int n, int x, int cap, int pos){
    if(cap == n) return n;
    int idx = pos -1;   // where we want to insert the element.
    for(int i=n-1;i>=idx;i--){
        arr[i+1] = arr[i];  // moving one element to right.
    }
    arr[idx] = x;   // inserting the value at the specific position.
    return n+1; // returning n+1, because we are inserting 1 element.

}

int main(void){
    // Search : 
    // int n, x;
    // cin >> n >> x;
    // int arr[n];
    // for(int i=0;i<n;i++) cin >> arr[i];
    // cout << search(arr, n, x);

    // Insert : 
    int arr[5] = {5, 10, 20};
    int n = 3;
    int cap = 5;
    int x = 7;
    int pos = 2;
    int newSize = insert(arr, n, x, cap, pos);
    for(int i=0;i<newSize;i++) cout << arr[i] << " ";

    return 0;
}