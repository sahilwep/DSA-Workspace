/*

// Binary String


// Observations: 
    * we are given a string s, which we have to find the substring, we can find the substring, which start with '1' & ends with '1'

// Intrusion:
    // Bruteforce Solution: 
        * Outer loop picks every '1' & the inner loop will searches for ending '1' & increment the counter whenever it finds 1
        * TC: O(n*n), TLE

    // Efficient Solution:
        * We have to get the first & last 1's, out of all the combinations...
        * If we carefully observe if we count the numbers of 1's, & from there we are getting the probability by 2(as starting & ending 1's).
        * If we get the combinations of the string: nCr, 
            * here n will be the size of string, & r is 2, because (starting & ending 1's).
            * we have to find the value of : xC2, x = numbers of 1's
        * If the value of x is 0 or 1, means there is no 1's or only 1 ones, we don't have any substring..
        * In maths the formula for  
                    nC2 = (n * (n-1))/ 2

        * TC: O(n)
        * SC: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Bruteforce Solution: 
    long binarySubstring_(int n, string a){
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
    // Efficient Solution:
    long binarySubstring(int n, string s){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') cnt++;
        }
        if(cnt == 0 || cnt == 1) return 0;
        return (cnt * (cnt - 1))/2;
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