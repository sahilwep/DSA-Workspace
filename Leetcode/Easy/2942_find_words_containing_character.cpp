/*
// Find Words Containing Character https://leetcode.com/problems/find-words-containing-character/

    Example 1:
    Input: words = ["leet","code"], x = "e"
    Output: [0,1]
    Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.

    Example 2:
    Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
    Output: [0,2]
    Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.

    Example 3:
    Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
    Output: []
    Explanation: "z" does not occur in any of the words. Hence, we return an empty array.

// TC : O(n*m)


*/
#include<bits/stdc++.h>
using namespace std;

// Solution: TC : O(n*m)
vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> v;
    for(int i=0;i< words.size();i++){
        string temp = words[i];
        for(int j=0;j<temp.size();j++){
            if(temp[j] == x){
                v.push_back(i);
                break;
            }
        }
    }
    return v;
}


int main(void){
    vector<string> s;
    char x;
    cin >> x;
    
    while(true){
        string temp;
        cin >> temp;
        // if( temp == "\0") break;
        if(temp.empty()) break;
        s.push_back(temp);
    }
    vector<int> res = findWordsContaining(s, x);
    for(auto i : res){
        cout << i << " ";
    }
}