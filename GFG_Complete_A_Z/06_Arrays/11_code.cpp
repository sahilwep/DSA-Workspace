/*
// Move all zeros to End:

    I/p: arr[] = {8, 5, 0, 10, 0, 20}
    O/p: arr[] = {8, 5, 10, 20, 0, 0}

    I/p: arr[] = {0, 0, 0, 10, 0}
    O/p: arr[] = {10, 0, 0, 0, 0}

    I/p: arr[] = {10, 20}
    O/p: arr[] = {10, 20}

// Naive Solution: 
    * iteration (i=0 -> i<n): 
        * we find the zero's element,
        * once we find the first zero element, we will start another iteration to find the next non-zero element.
            * iteration (j = i+1 -> j<n):
                * finding the first non-zero element,
                * then swapping it with previous zero's element.      
    * TC: O(n^2)
    * AC: O(1) 
                

// Better solution: 
    * create a temp array & store unique value inside it.
    * copy those unique value from temp to original & then after that assign 0's to end.
    * TC: O(n)
    * AS: O(n)

// Optimal solution:
    * using two pointer approach: 
        * create a pointer 1 with value 0th
        * check the non-zero value, & then swap with the other pinter, & increase counter.
    * TC: O(n)
    * AS: O(1) 
    



*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: 
void moveZerosToEnd(int arr[], int n){
    int count = 0;
    for(int i=0;i<n;i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

// Better Solution: 
void moveZerosToEnd_1(int arr[], int n) {
    int temp[n];
    int k = 0;
    // assigning unique values inside that array.
    for(int i=0;i<n;i++){
        if(arr[i] != 0) {
            temp[k] = arr[i];
            k++;
        }
    }
    // copying those unique value into original array.
    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }
    // now assigning 0's at end
    for(int i=k;i<n;i++){
        arr[i] = 0;
    }
}

// Naive Solution:
void moveZerosToEnd_2(int arr[], int n) {
    for(int i=0;i<n;i++) {
        // finding the first zero element
        if(arr[i] == 0) {
            // when we find the non-zero element, we iterate again from the next position.
            // iterating from the next element
            for(int j=i+1;j<n;j++) {
                // finding the first non zero element
                if(arr[j] != 0) {
                    // swapping with previous non-zero element
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    moveZerosToEnd(arr, n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}