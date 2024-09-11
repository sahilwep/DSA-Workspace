/*

// Closet 0s 1s and 2s

// Observations: 
    * we are given an array that contains, 0's, 1's & 2's, and we need to sort them in non-descending order.


// Intrusion: 
    // Bruteforce Method:
        * Using Sorting 
        * TC: O(nlogn)
    
    // Using counter:
        * use counter for 0, 1, & 2.
        * TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Using Sorting: O(nlogn)
    void segragate012(int arr[], int n){
        sort(arr, arr+n);
    }
};

int main() {

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        Solution ob;
        ob.segragate012(A, N);
        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }
        cout << endl;
    }

    return 0;
}