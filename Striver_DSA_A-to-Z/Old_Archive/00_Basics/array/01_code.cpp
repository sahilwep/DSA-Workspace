// Swap the specific index of array.

#include <iostream>
using namespace std;

void swap(int arr[], int _1_index, int _2_index){
        int temp = arr[_1_index];
        arr[_1_index] = arr[_2_index];
        arr[_2_index] = temp;
}

void print(int arr[], int n){
    cout << endl << "Array List is : ";
    for(int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
}

int main(void){

    int arr[] = {1,2,3,4,5,6     };
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << endl << "Before Swap";
    print(arr, n);
    swap(arr, 1, 3);
    cout << endl << "After Swap";
    print(arr, n);

    return 0;
}