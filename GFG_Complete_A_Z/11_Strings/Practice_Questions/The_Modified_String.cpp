/*

//  The Modified String

// Observations: 
    * we are given string s, which we need to modify as per the rules to make valid
        * The string should not have three consecutive same characters.
        * he can add any number of character anywhere in the string.
    * Find minimum number of character which he must insert in order to make string valid


// Example:
    Input:   S = aabbbcc
    Output: 1
        Explanation: In aabbbcc 3 b's occur
        consecutively, we add a 'd',and Hence,
        output will be aabbdbcc.

    Input:
    S = aaaaa
    Output: 2
        Explanation:  In aaaaa 5 a's occur
        consecutively,we need to add 2 'b', and
        Hence, the output will be aababaa.


// Intrusion: 
    * we can use counter approach to count the three consecutive same character..
    * If the counter is equal to 3, we increase the variable name required, that will count the number of character that we have to insert..
    * If the two consecutive character is not equal we will make counter = 1, & count again..


// Complexity: 
    * TC: O(n)
    * AS: O(1)


*/

#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;

class Solution{
public:
    int modified(string a){
        int cnt = 1;
        int req = 0;
        for(int i=1;i<a.size();i++){
            if(a[i] == a[i-1]){
                cnt++;
            }else{
                cnt = 1;
            }
            if(cnt == 3){
                req++;
                cnt = 1;
            }
        }
        return req;
    }
};

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }

    return 0;
}