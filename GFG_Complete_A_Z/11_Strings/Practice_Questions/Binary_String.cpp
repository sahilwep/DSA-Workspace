/*

// Binary String

// Observations: 
    * we are given a string s, which we have to find the substring, we can find the substring, which start with '1' & ends with '1'

// Intrusion: 
    // Bruteforce Solution: 
        * Outer loop picks every '1' & the inner loop will searches for ending '1' & increment the counter whenever it finds 1
        * TC: O(n*n), TLE
    
    // Efficient Solution:



*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Bruteforce Solution: 
    long binarySubstring(int n, string a){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i] == '1'){
                for(int j=i+1;j<n;j++){
                    if(a[j] == '1'){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

};

int main(){
    int t,n,count;
    string a;
    cin>>t;
    while(t--){
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}