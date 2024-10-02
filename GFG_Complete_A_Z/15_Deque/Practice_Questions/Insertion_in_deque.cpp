/*

//  Insertion in deque


//  Observations: 
    * We are given an array arr[] of size n, we need to insert all the element into queue:


// Deque:
    * Insertion & deletion can be done from both the ends.

                Insertion -> |   |   |   |   |   |   |   <- Insertion
                Deletions <- |   |   |   |   |   |   |   -> Deletions


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to insert all elements of the array in deque.
    deque<int> deque_Init(int arr[], int n) {
        deque<int> dq;
        for(int i=0;i<n;i++){
            dq.push_back(arr[i]);
        }

        return dq;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        deque<int> res = ob.deque_Init(arr, n);
        for (auto x : res) cout << x << " ";

        cout << endl;
    }
}