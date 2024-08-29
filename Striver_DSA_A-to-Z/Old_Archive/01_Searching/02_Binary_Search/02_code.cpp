// binary search using for loop explained. 

#include <iostream>
using namespace std;

// Sorting Algorithms, Bubble Sort.
void sort(int list[], int size){
    // to access the elements of list.
    for(int i = 0 ; i < size -1; i++){
        // to compare the items in list.
        for(int j = 0 ; j < size -1 ; j++){
            // compare two consecutive items.
            if(list[j] > list[j+1]){
                // swap(list[j], list[j+1]);
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

// to print the list.
void print(int list[], int size){
    cout << endl << "Array list : ";
    for(int i = 0 ; i < size; i++){
        cout << list[i] << " ";
    }
}

// Binary Search function.
bool binarySearch(int list[], int size, int target){
    int start = 0;
    int end = size - 1;
    // to divide the list in half.
    int mid = int((start + end )/ 2);

    // remember ( start <= end ), because when it's small then this loop will execute and then only one time when it's equal the loop will execute and go to the true condition.
    for(int i = start; start <= end; i++ ){
        if(target == list[mid]){
            return true;
        }
        // if target value is lesser than the mid, then we have to go left so, end will be use as (end = mid -1) 
        if(target < list[mid]){
            end = mid - 1;
        }
        // if target value is greater than the mid, then we have to go right so, start will be use as (start = mid + 1) 
        if(target > list[mid]){
            start = mid + 1;
        }
        // at last we will re again changing the mid value after these condition executes..
        mid = int((start + end)/ 2);
    }
    // this will return if the value is not found.
    return false;
}


int main(void){

    int list[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 7;

    sort(list, size);
    print(list, size);

    int result = binarySearch(list, size, target);
    (result == 1) ? cout << endl << "Found." : cout << endl << "Not Found.";

    return 0;
}