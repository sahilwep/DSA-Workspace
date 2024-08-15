/*
// Who has the majority?


// Observations: 
    * We are given an array of size n, & we are given two integer x & y, 
    * We have to return which of these variable appears the most.
    * If the frequency is same, return the maximum element among them.

// Intrusion:
    * We can solve this questions with multiple approach:
        * We can use hashing
        * We can use simple counter
    * I will be using both the approach


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Using hashing: 
    int majorityWins_Method_1(int arr[], int n, int x, int y) {
        unordered_map<int, int> mp; // use map to store frequency
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int xOccur = 0, yOccur = 0;     // making frequency counter
        bool flag1 = 0, flag2 =0;   // using this in order to exit from iterations once we found the frequency of both the element. 
        for(unordered_map<int, int>::iterator i=mp.begin();i!=mp.end();i++){
            if(i->first == x){
                xOccur = i->second;
                flag1 = 1;
            }
            else if(i->first == y){
                yOccur = i->second;
                flag2 = 1;
            }
            if(flag1 == 1 && 1 == flag2){
                break;
            }
        }
        // case when one of the element is missing from array:
        if(flag1 == 1 && flag2 == 0){
            return x;
        }else if(flag1 == 0 && flag2 == 1){
            return y;
        }

        // returning the result:
        if(xOccur < yOccur){
            return y;
        }else if(xOccur > yOccur){
            return x;
        }else{
            return min(x, y);
        }
    }
    // Using counter method:
    int majorityWins(int arr[], int n, int x, int y){
        int xCnt = 0;
        int yCnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == x) xCnt++;
            if(arr[i] == y) yCnt++;
        }
        if(xCnt == yCnt) return min(x, y);
        else if(xCnt > yCnt) return x;
        else return y;
    }
};

int main() {

    int t; 
    cin >> t; 
    while (t--){
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n;i++) cin >> arr[i];

        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.majorityWins(arr, n, x, y) << endl;
    }

    return 0;
}