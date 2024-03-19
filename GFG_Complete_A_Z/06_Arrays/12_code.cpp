/*
// Left Rotate an Array by One:

    I/p: arr[] = {1, 2, 3, 4, 5}
    O/p: arr[] = {2, 3, 4, 5, 1}


    I/p: arr[] = {30, 5, 20}
    O/p: arr[] = {5, 20, 30}

*/

#include<bits/stdc++.h>
using namespace std;

// bruteforce solution: TC: O(n), AS: O(1)
void leftRotateOne(int arr[], int n){
    int first = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = first;
}

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    leftRotateOne(arr, n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}