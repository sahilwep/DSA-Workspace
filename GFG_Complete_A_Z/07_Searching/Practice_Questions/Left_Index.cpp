/*

// Left Index

// Observations: 
    * We are given sorted array, & a element x. Task is to find the leftmost index of that element.



*/

#include <iostream>
using namespace std;

int leftIndex(int n, int arr[], int x){
	for(int i=0;i<n;i++){
		if(arr[i] == x){
			return i;
		}
	}
	return -1;
}

int main() {
	int testcases;
	cin >> testcases;
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    int elemntToSearch;
	    cin >> elemntToSearch;
	    
	    cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
	}
	
	return 0;
}