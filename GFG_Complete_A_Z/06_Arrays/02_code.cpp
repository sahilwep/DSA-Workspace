/*
// Types of array :
    * Fixed size array 
    * Dynamic size array 

// Fixed size array :
    // Size is initialized during initialization

// Dynamic size array : 
    // Resize automatically when it's gets full.
    // vectors are known as dynamic size array.
    // Example : 

            Inital : [ | |........| | ]
                       0            99
            when it's gets full, it's double or triple it's size.
            
            After  : [ | |.......................| | ]
                       0                          199

            when it's gets full, it's double or triple it's size.

            After  : [ | |.......................................| | ]
                       0                                          399

        * When it's get's full, it's simply create another array of double or triple size, & copy all the item from firs array, and delete the previous array.


*/

#include<bits/stdc++.h>
using namespace std;



int main(void){

    // Fixed size array : 
    int arr[100];   // stack allocated array
    int n = 200;    // stack allocated array
    int arr2[n];    // stack allocated array
    int arr4[] = {10, 20, 30, 40};  // stack allocated array

    int * arr3 = new int[n];    // Heap allocated array 

    // Dynamic Size array : 
    vector<int> v;


    return 0;
}