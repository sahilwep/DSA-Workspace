/*

// Bubble Sort


// Observations: 
    * We are given an array arr of size n, we need to sort them by using Bubble sorting.


// Bubble Sorting: 
    * Traverse from left & compare adjacent elements and the higher one's placed at right side.
    * In One way largest element is moved to the rightmost end of first.
    * The processed is then continued to find the second largest and place it and so until the data is stored.

// Note: 
    * In inner loop:
        * (j < n):
            * This will not not ignore the sorted values that sorted at the end of array.
        * (j < n - i - 1):
            * This will ignore the sorted value, that we have stored at the end(max values).
            * Efficient over normal (j < n) logic.

// Example Visualization: 
        arr[] = 4 1 3 9 7

            Initially: 
                        arr[] = 4 1 3 9 7
            i = 0: 
                j = 0
                    if(arr[j] > arr[j+1])
                        swap(4, 1)
                            arr[] = 1 4 3 9 7
                j = 1
                    if(arr[j] > arr[j+1])
                        swap(4, 3)
                            arr[] = 1 3 4 9 7 
                j = 2
                    if(arr[j] > arr[j+1])  -> Ignore
                            arr[] = 1 3 4 9 7 
                            
                j = 3
                    if(arr[j] > arr[j+1]) 
                        swap(9, 7)
                            arr[] = 1 3 4 7 9       (At end of first iteration, max values at last)
                
            i = 1:
                j = 0
                    if(arr[j] > arr[j+1]) -> Ignore
                            arr[] = 1 3 4 7 9
                j = 1
                    if(arr[j] > arr[j+1]) -> Ignore
                            arr[] = 1 3 4 7 9
                ...
            ...

        * This is how the values are compare & largest values moved at the last positions...
        * TC: O(n^2)
                            

// Optimized: 
    * We will use flag that will check either our sorting logic executes or not, if they are not executing we will break out from the loop.


*/
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

class Solution {
public:
    // Normal Bubble Sort:
    void bubbleSort_Normal(int arr[], int n){
        for(int i=0;i<n-1;i++){
            // at every iteration of i, we will move the largest value to the end.
            for(int j=0;j<n-i-1;j++){
                // if two left value is grater than right value, then swap these two.
                if(arr[j] > arr[j+1]){
                    // swap two adjacent values
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    // Optimized Bubble Sort:
    void bubbleSort(int arr[], int n){
        for(int i=0;i<n-1;i++){
            bool isSorted = 1;  // executes when the values are already sorted, We will restrict it to recheck the values if they are already sorted.
            for(int j=0;j<n-i-1;j++){
                if(arr[j] > arr[j+1]){
                    isSorted = 0;
                    swap(arr[j], arr[j+1]);
                }
            }
            if(isSorted) break;
        }
    }
};

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)  printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[1000], n, T, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &arr[i]);

        Solution ob;

        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}