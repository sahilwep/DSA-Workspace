// reverse the array list.

#include <iostream>
using namespace std;

void print(int arr[], int n){
    cout << endl << "Array list is : ";
    for(int i = 0; i <= n-1 ;i++){
        cout << arr[i] << " ";
    }
}

// reverse using for loop.
void rev(int arr[], int n){
    for(int i = 0 ; i < n/2 ; i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

// Two pointer method, works for odd & even no of array.
// reverse using while loop.
void rev_while(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        // swap(arr, start, end);
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] =  temp;
        start++;
        end--;
    }
}

// Swapping function. 
// void swap(int arr[],int start, int end){
//     int temp = arr[start];
//     arr[start] = arr[end];
//     arr[end] = temp;
// }

int main(void){
    int arr[] = {1,2,3,4,5,6,7,9,10,11,12,13};
    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);
    // rev(arr, n);
    rev_while(arr, n);
    print(arr, n);

    return 0;
}