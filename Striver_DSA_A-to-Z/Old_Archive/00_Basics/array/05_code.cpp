// Cumulative sum array : 

/*

Initial Array: [1, 2, 3, 4]
Cumulative Sum: [1, 3, 6, 10]

Initial Array: [1, 1, 1, 1, 1]
Cumulative Sum: [1, 2, 3, 4, 5]

Initial Array: [1, 3, 5, 7, 9]
Cumulative Sum: [1, 4, 9, 16, 25]

// Bruteforce approach : 
    * create a new array of same size.
    * assign the 0th index of new array with same value of the old array.
    * then using loop : i = 1 -> n
            Store the second array value = previous value of second array + current value of original array.


// Optimal :
*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach : 
void cumulativeSum(int arr[], int n){
    int arr_1[n];
    arr_1[0] = arr[0];
    // Operation : 
    for(int i=1;i<n;i++){
        arr_1[i] = arr_1[i-1] + arr[i];
    }
    // Printing the array : 
    for(auto i : arr_1) cout << i << " ";
    cout << endl;
}
    // TC : O(n)
    // SC : O(n)


// Optimal Solution : 
void cumulativeSum_1(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }

    // Operations : 
    int temp1 = arr[n-1];
    int temp2 = arr[n-2];
    arr[n-1] = sum;
    for(int i=n-2;i>-1;i--){
        arr[i] = arr[i+1] - temp1;
        temp1 = temp2;
        temp2 = arr[i-1];
    }
}
    // TC : O(2n)
    // SC : O(1)


int main(void){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];

        cumulativeSum_1(arr, n);

        for(auto i : arr) cout << i << " ";
        cout << endl;
    }

    return 0;
}
