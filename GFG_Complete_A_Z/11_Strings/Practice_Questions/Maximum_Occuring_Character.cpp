/*

// Maximum Occuring Character

// Observations: 
    * We are given string s, we need to find the maximum occurring character in string.
    * We have to print the maximum occurring lexigraphically smallest character.

// Intrusion:
    * We can use map, which sore characters in sorted manner..
    * The we can return the maxFrequency element...

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    char getMaxOccuringChar(string s){
        map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        char maxChar;
        int max = INT_MIN;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second > max){
                max = i->second;
                maxChar = i->first;
            }
        }

        return maxChar;
    }

};

int main(){
   
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}