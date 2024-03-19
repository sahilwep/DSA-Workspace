/*
// Left rotate an Array by D place
    * Left rotation: counter clockwise rotation

    I/p: arr[] = {1, 2, 3, 4, 5}
    d = 2
    O/p: arr[] = {3, 4, 5, 1, 2}

    I/p: arr[] = {10, 5, 30, 15}
    d = 3
    O/p: arr[] = {15, 10, 5, 30}

* We may assume d <= No of element in the array

// Naive Solution: 
    * We ca (left rotate by one) d times.
    * TC: O(n*d)
    * AS: O(1)

// Better solution: 
    * First we copy the element till d.
    * then we we move the element after the d place to the starting of original array.
    * then we copy dth value from temp array to original array after dth place.
    * TC: O(d+(n-d)+d) => O(n)
    * AS: O(d)

// Optimal Solution: 
    * reverse(arr, 0, d-1);
    * reverse(arr, d, n-1);
    * reverse(arr, 0, n-1);
    
    * Example: {1 2 3 4 5}, d = 2
    reverse(arr, 0, d-1);  {1 2} => {2 1 3 4 5}
    reverse(arr, d, n-1);  {3 4 5} => {2 1 5 4 3}
    reverse(arr, 0, n-1);  {2 1 5 4 3} => {3 4 5 1 2}

    * TC : O(d + (n-d) + n) => O(n)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution: 
void reverse(int arr[], int low, int high){
    while(low < high) {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotateByD(int arr[], int n, int d){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

// Better Solution: 
void leftRotateByD_2(int arr[], int n, int d){
    // create a temp array, that stores d elements.
    int temp[d];
    // insert d element inside the temp array.
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }
    // moving the value after d, to start to an array.
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    // after we insert d, which is in temp after the d'th value.
    for(int i=0;i<d;i++){
        arr[n-d+i] = temp[i];
    }
}



// Naive Solution: 
// left rotation by one place: 
void leftRotateByOne(int arr[], int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
void leftRotateByD_3(int arr[], int n, int d){

    for(int i=0;i<d;i++) {
        leftRotateByOne(arr, n);
    }
}

// 


int main(void){
    int n, d;
    cin >> n >> d;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    leftRotateByD(arr, n, d);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}