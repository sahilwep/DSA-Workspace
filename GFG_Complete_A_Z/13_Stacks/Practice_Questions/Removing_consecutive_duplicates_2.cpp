/*
// Removing consecutive duplicates - 2


// Observations: 
    * we are given string s, & we have to remove pair of duplicate character from string s.


// Example: 
    Input: aaabbaaccd
    Output: ad

    Explanation: 
        Remove (aa)abbaaccd =>abbaaccd
        Remove a(bb)aaccd => aaaccd
        Remove (aa)accd => accd
        Remove a(cc)d => ad

// Example: 
    Input: aaaa
    Output: Empty String

    Explanation: 
        Remove (aa)aa => aa
        Again removing pair of duplicates then (aa) 
        will be removed and we will get 'Empty String'.



// Intrusion: 
    * we will insert value into stack...
    * we will check if our stack is not empty & top element of stack is equal to s[i], we will remove that element...
        * by doing this we are sure that, we atleast have one value at the end if they are in odd in numbers..
        * because, we are matching one value from stack & one value from top of stack.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removePair(string str){
        stack<char> s;
        for(int i=0;i<str.size();i++){
            // if stack is not empty & top element of stack is str[i], we will remove that element from stack.
            if(!s.empty() && s.top() == str[i]){
                s.pop();    // it will pop out the value from stack.
            }
            // else we will insert that element into stack.
            else{
                s.push(str[i]); // insert into the stack
            }
        }

        // At last we are storing the string character from stack into the string res.
        string res = "";
        while(!s.empty()){
            res  = s.top() + res;   // storing in this fashion, no need to reverse the string..
            s.pop();
        }

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}