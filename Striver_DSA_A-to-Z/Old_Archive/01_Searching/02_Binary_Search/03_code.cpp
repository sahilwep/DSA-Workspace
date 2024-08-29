// Binary Search using while loop.

#include <iostream>
using namespace std;

void sort(int list[], int size){
    for(int i = 0; i< size -1 ; i++){
        for(int j = 0 ; j < size -1; j++){
            if(list[j] > list[j+1]){
                swap(list[j], list[j+1]);
            }
        }
    }
}

void print(int list[], int size){
    cout << endl << "Array List : ";
    for(int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
}


int binarySearch(int list[], int size, int target){
    int start = 0; 
    int end = size - 1;
    int mid = (start + end )/ 2;

    while(start <= end){
        mid = (start + end )/ 2;
        if(target == list[mid]){
            return mid;
        } 
        if(target > list[mid]){
            start = mid + 1;
        }
        if(target < list[mid]){
            end = mid - 1;
        }
    }    
    return -1;
}

int main(void){

    int list[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 1;

    sort(list, size);
    print(list, size);
    
    int result = binarySearch(list, size, target);
    (result == -1 ) ? cout << endl << "Not Found." : cout << endl << "Found at index : " << result;

    return 0;
}