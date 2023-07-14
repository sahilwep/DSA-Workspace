// Reverse a Array : using recursion
/*
    // using recursion to swap the array :

    * recursion using two pointers
        Swapping using two pointer method :
            |   |   |   |   |   |
            L                   R
                L           R   
                    L   R   
                    L=R (stop)

                * we have to Increase L        
                * & we have to decrease R         
                * Until they meet equal
            
             
*/          

#include <bits/stdc++.h>
using namespace std;


// or we can do this by on variable i.e i & n i.e size.
void rev_tow_p_meth_2(int i, int arr[], int n){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    rev_tow_p_meth_2(i+1,  arr, n);
}


// recursion using two pointer.
// we are doing this using two variable, l & r
void rev_two_p_(int l, int arr[], int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    rev_two_p_(l+1, arr, r-1);
}

// Simple method without recursion 
void rev(int arr[], int n){
    for(int i = 0; i<n/2; i++){
        swap(arr[i], arr[n-i-1]);
    }
}

// print
void print(int arr[], int n){
    cout << "\nArray list is : ";
    for(int i = 0; i<n; i++){
            cout << arr[i] << " ";
    }
}
// Input
void input(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << "Enter the array[" << i << "] : ";
        cin >> arr[i];
    }
}

int main(void){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    input(arr, n);
    print(arr, n);
    // rev(arr, n);         // without recursion.
    // rev_two_p_(0, arr, n-1);     // using two pointer.
    rev_tow_p_meth_2(0, arr, n);     // using one variable & with size
    cout << "\nAfter reverse : ";
    print(arr, n);

    return 0;
}