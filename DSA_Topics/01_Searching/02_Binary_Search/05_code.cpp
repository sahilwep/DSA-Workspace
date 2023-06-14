// binary Search.

#include <iostream>
using namespace std;

// Bubble sort.
void sort(int list[], int size){
    for(int i = 0; i < size - 1 ;i++){
        for(int j = 0; j < size - 1; j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

// Binary Search.

bool binarySearch(int list[], int size, int target){
    int start = 0;
    int end = size -1;
    int mid = int((start + end)/2);
    for(int i = start; start <= end; i++){
        if(target == list[mid]){
            return true;
        }
        if(target > list[mid]){
            start = mid + 1;
        }
        if(target < list[mid] ){
            end = mid - 1;
        }
        mid = int((start + end)/2);
    }
    return false;
}

// print the array.
void print(int list[], int size){
    cout << endl << "Array list : ";
    for(int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
}

int main(void){

    int list[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 2;

    sort(list, size);
    print(list, size);

    int result  = binarySearch(list, size, target);
    (result == 0) ? cout << endl << "Not Found." : cout << endl << "Found."; 


    return 0;
}

