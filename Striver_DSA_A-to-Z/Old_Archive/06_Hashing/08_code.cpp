/*
// find the maximum & minimum frequency : 

// Bruteforce Approach : 
    * using map / unordered_map we can perform this operation.. 

*/
#include <bits/stdc++.h>
using namespace std;

int maxFreq(unordered_map <int,int> mpp){
    int temp = -1;
    int key;
    for(auto i : mpp) {
        if(i.second > temp){
            temp = i.second;
            key = i.first;
        } 
    }
    return key;
}

int minFreq(unordered_map <int,int> mpp){
    int temp = 10e7;  // for min we need to put max value..
    int key;
    for(auto i : mpp) {
        if(i.second < temp){
            temp = i.second;
            key = i.first;
        } 
    }
    return key;
}

int main(void){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            // precalculation : 
            mpp[arr[i]]++;
        }

        // printing the map : 
        // for(auto i : mpp) cout << i.first << "->" << i.second << endl; 

        cout << "max freq of element : " << maxFreq(mpp) << endl;
        cout << "min freq of element : " << minFreq(mpp) << endl;
    }

    return 0;
}
