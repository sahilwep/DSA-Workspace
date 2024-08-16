/*

// Print Pattern

// Observations: 
    * We are given n = x, & we have to perform (n - 5) until (n <= 0), 
    * if it's become n become 0 or negative, we perform (n + 5), until the n become original number.


// Intrusion: 
    * we can use recursive solution, where we pass the value n = 5, & we recursively call for (n-5), until the n become 0 or negative..
    * Once it's become negative or 0, we can recursively call for (n + 5), until the n becomes original number that it was..


// Complexity: 
    * TC: O(n)
    * SC: O(n), as the recursive calls inside the stack..

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // iterative solution: 
    vector<int> pattern(int n){
        vector<int> res;
        int k = n;
        res.push_back(n);
        while(n > 0){
            n = (n - 5);
            res.push_back(n);
        }
        while(n < k){
            n = (n + 5);
            res.push_back(n);
        }

        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}