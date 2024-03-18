/*
// Second largest element in an array : 

    I/p : arr[] = {10, 5, 8, 20}
    O/p : 0     // index of 10

    I/p : arr[] = {20, 10, 20, 8, 12 }
    O/p : 4     // index of 12

    I/p : arr[] = {10, 10, 10}
    O/p : -1    // no second largest

// Basic solution: 
    * We can first find the index of the largest element,
    * Then, we can skip that index & find the remaining largest element.

// Better solution: 

*/

#include<bits/stdc++.h>
using namespace std;

// basic solution: TC : O(2n) => O(n)
// gives the index of largest element
int getLargest(int arr[], int n) {
    int largest = 0;
    for(int i=1;i<n;i++){
        if( arr[i] > arr[largest]) {
            largest = i;
        }
    }
    return largest;
}
int second_largest_2(int arr[], int n){
    int largest = getLargest(arr, n);   // gives the index of largest element
    int res = -1;   // when there is no second largest
    for( int i=0;i<n;i++) {
        if ( arr[i] != arr[largest]) {
            if (res == -1){
                res = i;
            }
            else if(arr[i] > arr[res]) {
                res = i;
            }
        }
    }
    return res;
}


// Better solution: O(n)
int second_largest(int arr[], int n) {
    int largest = -1;
    int s_largest = largest;

    for(int i=0;i<n;i++) {
        if( arr[i] > largest) {
            s_largest = largest;
            largest = arr[i];
        }
        if( arr[i] < largest && arr[i] > s_largest) {
            s_largest = arr[i];
        }
    }
    return s_largest;
}


int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << second_largest(arr, n) << endl;

    return 0;
}