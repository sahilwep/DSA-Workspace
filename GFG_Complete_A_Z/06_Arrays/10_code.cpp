/*
// Remove duplicate from a sorted array

    I/p : arr[] = {10, 20, 20, 30, 30, 30}
        size = 7

    O/p : arr[] = {10, 20, 30,_ ,_ ,_ ,_}
        size = 3

    I/p : arr[] = {10, 10, 10}
        size = 3
    
    O/p : arr[] = {10, _, _}
        size = 1

// bruteforce solution: 
    * we create a temp array, with initializing first element from original array.
    * we match if our last element from temp array is distinct to original array, then we assign that element to our temp array.
    * last, we copy distinct value from temp array to original array, & we return the new size.
    * TC: O(n)
    * AS: O(n)

// Better solution: 
    * Using two pointer approach we can solve this problem.
    * 0th index element of an array is first unique value, so we start from index 1.
    * we are comparing the 1st index array, value with the 0th index of the array value, if the value is not, same then we assign, else we ignore this.
    * next we return new size with unique elements.
    * TC: O(n)
    * AS: O(1)

*/


#include<bits/stdc++.h>
using namespace std;

// Better solution: 
int removeDuplicate_1(int arr[], int n){
    int res = 1;
    for(int i=1;i<n;i++){
        if(arr[i] != arr[res-1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

// bruteforce solution: 
int removeDuplicate(int arr[], int n) {
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for(int i=0;i<n;i++) {
        if(temp[res-1] != arr[i]) {
            temp[res] = arr[i];
            res++;
        }
    }
    for(int i=0;i<res;i++){
        arr[i] = temp[i];
    }
    return res;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    n = removeDuplicate_1(arr, n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
}