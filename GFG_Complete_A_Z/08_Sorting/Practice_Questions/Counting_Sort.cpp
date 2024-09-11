/*

// Counting Sort

// Observations:
    * we are given a string s, containing the string, we have to sort them in lexigraphically order, using counting sort.

// Intrusion:
    * As we are limited with english characters, we can create a hash array, this will store the frequency of every element, & then we can sort them..
    * TC: O(n)


*/

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255

class Solution{
public:
    string countSort(string s){
        vector<int> hash(26, 0);
        for(int i=0;i<s.size();i++){
            hash[int(s[i] -  'a')]++;
        }
        string res = "";
        for(int i=0;i<hash.size();i++){
            int times = hash[i];
            char ch = char(i + 'a');
            for(int j=0;j<times;j++){
                res += ch;
            }
        }
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}