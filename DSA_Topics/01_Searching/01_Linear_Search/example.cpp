





     













/*

====================================================================================

    Linear Search :  Sequencial search of element on list by comparing each member.
    -> There is no need for sorted list to search the element.
    -> time taken process, because we are comparing each element by the search element.
    -> comparing each element, so not efficient.
*/

/*

#include <iostream>
using namespace std;

int linear(int arr[], int n, int x, int &index){ 
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == x){
            index = i;
            return 1;
        }
    }
    return 0;
}


void print(int arr[], int n){
    cout << endl << "Array list is : ";
    for(int i =0 ;i < n ; i++){
        cout << arr[i] << " ";
    }
}

void input(int &x){
    cout << endl << "Enter the element to find their index : ";
    cin >> x;
}

int main(void){
    
    int arr[]= {1,3,23,534,123,52,35,33,31,45,25,85,56,4,8,293,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    int index;
    int result;
    
    print(arr, n);
    input(x);
    result = linear(arr, n, x, index);

    if(result == 1) {
        cout << endl << "Array is at this position : " << index << "th index." ;
    } 
    else{
        cout << endl << "There is no element found on the list.";
    }

    return 0;
}
*/