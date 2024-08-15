/*

// Array Leaders

// Observations: 
    * We are given an array of size n, we have to find the leaders in an array:
    * An element is known as leader if all the element of right to it is smaller.

// Key observations: 
    * last element will always be the leader.
    * We will start iteration from last..
    * We will maintain the leader variable that will compare the array element while iterating to left...
    * if the element is grater than the previous assigned leader then we store that element into the list, & assign new leader as newly found maximum element..

// TC: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> res;    // maintaining the vector that will store the leaders..
        int leader = arr[n-1];  // assigning the last element as leader
        res.push_back(leader);  // pushing the values in vector
        // iteration start to second last till first, as we have already assign the last element into the leaders array
        for(int i=n-2;i>=0;i--){
            // comparing the value with current assign leaders, if it's grater or equal then we store that element as leader.
            if(arr[i] >= leader){
                res.push_back(arr[i]);  // pushing that element into leaders
                leader = arr[i];    // updating new leader
            }
        }
        reverse(res.begin(), res.end());  // at last we reverse the list as we have insert value from last
        return res;
    }
};

int main() {
    long long t;
    cin >> t; 
    while (t--) {
        long long n;
        cin >> n;

        int arr[n];
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> v = obj.leaders(n, arr);

        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}