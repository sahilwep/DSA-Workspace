/*
// Remove duplicate element in sorted array.

*/

#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int size){
    cout << endl << "array is : ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
}

void remDuplicate(int arr[], int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(i!=j && arr[i] == arr[j]){
                arr[j] = NULL;
            }
        }
    }
}

int main(void){

    int arr[] = {1, 2, 3, 2, 1, 4, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);


    print(arr, size);
    remDuplicate(arr, size);
    print(arr, size);

    return 0;
}