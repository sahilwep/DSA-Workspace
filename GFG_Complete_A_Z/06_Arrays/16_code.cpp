/*
// Frequency in a sorted Array:

    I/p : arr[] = {10, 10, 10, 25, 30, 30}
    O/p :   10 3
            25 1
            30 2
    
    I/p : arr[] = {10, 10, 10, 10}
    O/p :   10 4

    I/p : arr[] = {10, 20, 30}
    O/p :   10 1
            20 1
            30 1

// Solution: 
    arr[] = {10, 10, 10, 30, 30, 40}

    initially : freq = 1
    i = 1 : freq = 2
    i = 2 : freq = 3
    i = 3 : print(10, 3), freq = 1
    i = 4 : freq = 2
    i = 5 : print(30, 2), freq = 1
    after loops: 
        print(40, 1)

    * we are starting comparing adjacent element, because it's sorted array,
    * we on each iteration of outer loop we set the frequency as 1, & then in inner loop we check the same value & increment freq.
    * at the end of outer loop, we have to check one edge case condition, where last, & second last elements are different, in this case we explicitly have to print the last element.
    * TC : O(n), because it's comparing the adjacent elements.. (also i is incrementing inside the inner loop also).
    * AS : O(1)
    
*/

#include<bits/stdc++.h>
using namespace std;

// Solution: TC : O(N)
void frequency(int arr[], int n){
    int freq = 1;
    int i = 1;
    while(i < n) {
        while( i < n && arr[i] == arr[i-1]) {
            freq++;
            i++;
        }
        cout << arr[i-1] << " + "<< freq << endl;
        i++;
        freq = 1; 
    }
    if( n == 1 || arr[n-1] != arr[n-2]){
        cout << arr[n-1] << " + " << 1;
    }
    
}


int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    frequency(arr, n);

    return 0;
}