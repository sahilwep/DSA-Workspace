/*

// Strongest Neighbour

// Observations: 
    * We are given an array of size n, we have to print the maximum adjacent pair.

// Intrusion:
    * for maximum adjacent element, we will have always (n-1) element..
    * We can use max() function..

*/

#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

// function to return the maximum of adjacent pair
void maximumAdjacent(int n, int arr[]){
    vector<int> v;
    for(int i=1;i<n;i++){
        int x = max(arr[i], arr[i-1]);
        v.push_back(x);
    }
    for(auto i : v) cout << i << " ";

}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];

        for(int index = 0; index < n; index++){
            cin >> arr[index];
        }

        maximumAdjacent(n, arr);
        cout << endl;
    }

    return 0;
}