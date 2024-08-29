/*
// Linear Search :

    arr[] = 1 34 56 4 5 6 2         num = 4

    return 1 if found, & return false if not found.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    bool linearSearch(int arr[], int n, int target){
        for(int i=0;i<n;i++){
            if(arr[i]==target){
                return true;
            }
        }
        return false;
    }
    // TC : O(n)
};


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        int target;
        cin >> target;
        Solution obj;
        int res = obj.linearSearch(arr, n , target);
        (res==0) ? cout << "Not found!" : cout << "Found!";
    }

    return 0;
}