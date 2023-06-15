// Binary Search :
/*
    For Binary Search We need a sorted array list.
    -> How Binary Search Works ?
    -> suppose a list contain sequence ordered no from 1 to 100, we need to find the no 62
    -> we can divide the list into half again-&-again and compare the mid with expected number until we find it.
*/

#include <iostream>
using namespace std;

void sort(int list[], int size){
    for(int i = 0 ; i < size - 1; i++){
        for(int j = 0 ; j < size -1; j++)
        if(list[j] > list[j+1]){
            int temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
        }
    }
}

void print(int list[], int size){
    cout << endl << "Array is : ";
    for(int i = 0; i < size; i++){
        cout << list[i] << " ";
    }
}

bool binarySearch(int list[], int start, int last, int target){

    while (start <= last){
        int mid = start + (last - start) / 2;
        
        if(list[mid] == target){
            return true;
        }
        if(list[mid] < target){
            start = mid + 1;
        }
        else{
            last = mid - 1;
        }
    }
    return false;
}

int main(void){

    int list[] = {10, 8, 9, 7, 5, 6, 4, 3, 2, 1, 11};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 1;
    int result;

    sort(list, size);
    print(list, size);
    
    result = binarySearch(list, 0, (size - 1), target);
    (result == 1) ? cout << endl <<  "Found." : cout << endl <<  "Not Found";

    return 0;
}