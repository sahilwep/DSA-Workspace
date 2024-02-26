// find the maximum item index in array list.

/* 
    arr list : 1,23,4,4234,23,....
    let's assume the max value is : arr[0] = 1;
    in loop we can compare the max value with each index.
    if arr[i] > max 
    then only update the max value else, no need to update.
*/


#include <iostream>
using namespace std;

void max(int arr[], int n){
    int max;
    max = arr[0];
    for(int i = 0;i <= n-1; i++){
        if(arr[i] > max){
            max = arr[i]; 
        }
    }
    cout << endl << "max is : " << max;
}

int main(void){

    int arr[] = {112,343,123,4,23,45};
    int n = sizeof(arr)/sizeof(arr[0]);

    max(arr, n);
    return 0;
}




//  Another Example : 
/*
    loop : i = 0 to (n-1) index
            
    if(arr[i] > arr[i+1]){
        max = arr[i]
    }

*/

/*

#include <iostream>
using namespace std;

void max(int arr[], int n){
    int max = 0,index = 0;
    for(int i = 0; i <= n - 1  ; i++){
        if(arr[i] > arr[i+1]){
            index = i;
            max = arr[i];
        }
    }
    cout << endl << "Max element : " << max;
    cout << endl << "Index Position : " << index;
}


int main(void){

    int arr[] = {1,2,3,4,22,1293,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    max(arr, n);

    return 0;
}

*/
