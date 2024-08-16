/*

// Wave Array

// Observations: 
    * Given a sorted array of distinct integer, we have to sort the array in wave like array(In place).
    * In other words, arrange the element in a sequence such that
                     arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5]

// Example: 
    Input: 
        n = 5, arr[] = {1,2,3,4,5}
    Output: 
        2 1 4 3 5
    Explanation: Array elements after sorting it in the waveform are 2 1 4 3 5.

    Input: 
        n = 6, arr[] = {2,4,7,8,9,10}
    Output: 
        4 2 8 7 10 9
    Explanation: Array elements after sorting it in the waveform are 4 2 8 7 10 9.

// Key observations:
    * We are given sorted array, so making wave like structure is very easy: 
            arr[] = 1 2 3 4 5
            idx =   0 1 2 3 4

            final[] =  2 1 4 3 5
            idx =      0 1 2 3 4

            insert even position elements on odd position from 1 to n
            insert odd position elements on even position from 0 to n


*/

#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        vector<int> res(n);
        int o = 1;  // using odd pointer, that place element in odd place
        int e = 0;  // using even pointer, that place element in even place
        for(int i=0;i<n;i++){
            // if position is odd, place element in odd place
            if(i % 2 == 0){
                res[o] = arr[i];
                o += 2; // increment with two will give odd place again.
            }else{
                res[e] = arr[i];
                e += 2; // increment with two will give even place
            }
        }
        // finally for odd size, array iteration left the last value, so we explicitly assign that..
        if(n % 2 != 0){
            res[n-1] = arr[n-1];
        }

        // finally storing result in result
        for(int i=0;i<n;i++){
            arr[i] = res[i];
        }
        res.clear();    // as we don't need res vector so we clear that vector..
    }
};


int main(){
    int t,n;
    cin >> t;
    while(t--){

        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout << endl;
    }
}