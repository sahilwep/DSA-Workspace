// find the max value inside the array list b/w range.

#include<iostream>
using namespace std;

void max(int arr[], int n, int _1_index, int _2_index){
    int max = arr[0];
    for(int i = _1_index; i <= _2_index; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << endl << "Max no is : " << max;
}

int main(void){

    int arr[] = {1, 2, 45, 232, 23, 1212, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    max(arr, n, 2, 4);

    return 0;
}