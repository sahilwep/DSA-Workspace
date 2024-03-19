/*
// Reverse an array: 

    I/p : arr[] = {10, 5, 7, 30}
    O/p : arr[] = {30, 7, 5, 30}

    I/p : arr[] = {30, 20, 5}
    I/p : arr[] = {5, 20, 30}

*/

#include<bits/stdc++.h>
using namespace std;

// TC : O(n), AS = O(1)
void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n-1;
    while (start < end) {
    int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    reverseArray(arr, n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}