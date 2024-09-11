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
    void segragate012_Sorting(int arr[], int n){
        sort(arr, arr+n);
    }
    // Using Counter: O(n)
    void segragate012(int arr[], int n){
        int one = 0, two = 0, zero = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) zero++;
            else if(arr[i] == 1) one++;
            else two++;
        }
        int k = 0;
        for(int i=0;i<zero;i++){
            arr[k++] = 0;
        }
        for(int i=0;i<one;i++){
            arr[k++] = 1;
        }
        for(int i=0;i<two;i++){
            arr[k++] = 2;
        }
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