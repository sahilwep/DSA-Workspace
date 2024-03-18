/*
// check if the array is sorted or not

    I/p : arr[] = {8, 12, 15}
    O/p : Yes

    I/p : arr[] = {8, 10, 10, 12}
    O/p : Yes

    I/p : arr[] = {100}
    O/p : yes

    I/p : arr[] = {100, 200}
    O/p : No


*/

#include<bits/stdc++.h>
using namespace std;

// Solution: TC : O(n)
bool isSorted(int arr[], int n) {

    for(int i=0;i<n-1;i++){
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

// similar approach: 
bool isSorted_1(int arr[], int n) {
    for (int i=1;i<n;i++) {
        if ( arr[i-1] > arr[i]) {
            return false;
        }
    }
    return true;
}



int main(void){

    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    isSorted_1(arr, n) == 1 ? cout << "Yes" : cout << "No";

    return 0;
}