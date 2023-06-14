// Linear Search Algorithms.

#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target){
    if(arr[size] == 0){
        return false;
    }
    for(int i = 0 ; i < size; i++ ){
        if(arr[i]== target){
            return true;
        }
    }
    
    return false;
}

void print(int arr[], int size){
    cout << endl << "Array is : ";
    for(int i = 0; i < size ; i++){
        cout <<  arr[i] << " "; 
    }
}

int main(void){
    int arr[] = {1, 23, 34, 324, 12, 53, 11, 58, 18, 19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 18;

    print(arr, size);
    int result = linearSearch(arr, size, target);

    if(result == 1){
        cout << endl << "found";
    }
    else{
        cout << endl << "Not found";
    }

    return 0;
}