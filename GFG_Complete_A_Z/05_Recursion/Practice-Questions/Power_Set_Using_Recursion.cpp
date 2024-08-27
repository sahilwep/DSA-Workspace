/*

// Power Set Using Recursion


// Observations: 
    * You are given string s, you need to return the power-set in any order of the string.

// Power set: 
    * Power set: power set include all the subset of given set include empty set.
    * Example: 
        set = {1, 2, 3}
        PowerSet = {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}


// Example:
    Input:  s = a
    Output: a
        Explanation: empty string and a 
        are only sets.

    Input:  s = abc
    Output: a ab abc ac b bc c
        Explanation: empty string, 
        a, ab, abc, ac, b, bc, c 
        are the sets.


*/

#include <bits/stdc++.h>
using namespace std;

void solution(string input, string output, vector<string> &v){
    if(input.length() == 0){
        v.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;
    output2.push_back(input[0]);
    input.erase(input.begin() + 0);
    solution(input, output1, v);
    solution(input, output2, v);
    return;
}


vector <string> powerSet(string s){
    string input = s;
    string output = "";
    vector<string> v;
    solution(input, output, v);
    return v;

}


int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        
        sort(ans.begin(),ans.end());
        
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

    return 0;
} 