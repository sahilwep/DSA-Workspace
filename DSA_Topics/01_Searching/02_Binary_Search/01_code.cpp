// binary search using for loop.

#include <iostream>
using namespace std;


void sort(int list[], int size){
    for(int i = 0; i < size -1 ; i++){
        for(int j = 0; j < size -1; j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void print(int list[], int size){
    cout << endl << "Array list : ";
    for(int i = 0; i < size ;i++){
        cout << list[i] << " " ;
    }
}

bool binarySearch(int list[], int size, int target){
    int start = 0;
    int end = size -1;
    int mid = int( start + end )/ 2;

    for(int i = start; start <= end ; i++){
        if(target == list[mid]){
            return true;
        }
        if(target < list[mid]){
            end = mid - 1;
        }
        if(target > list[mid]){
            start = mid + 1;
        }
        mid = int(start + end) /2;
    }
    return false;
}


int main(void){

    int list[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 1;
    int result;

    sort(list, size);
    print(list, size);

    result = binarySearch(list, size, target);
    (result == 1) ? cout << endl << "Found." : cout << endl << "Not found.";    

    return 0;
}