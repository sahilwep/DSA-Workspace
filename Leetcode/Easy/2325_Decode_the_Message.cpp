/*
// 2325. Decode the Message


    Example 1:
        Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
        Output: "this is a secret"
        Explanation: The diagram above shows the substitution table.
        It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

    Example 2:
        Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
        Output: "the five boxing wizards jump quickly"
        Explanation: The diagram above shows the substitution table.
        It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".


// ascii difference : A-a : 32
    a = 97      , z = 122
    A = 65      , Z = 90
    0 = 48      , 9 = 57
    

*/

#include<bits/stdc++.h>
using namespace std;

string decodeSecrete(string key, string message){
    map<char, set<char>> mp;
    char ch = char(97);
    for(int i=0;i<key.size();i++){
        if(ch > 122) break;
        if(key[i]!= ' '){
            mp[ch].insert(key[i]);
            ch++;
        }
    }




    return "asdf";
}

int main(void){

    string key, message;
    getline(cin, key);
    getline(cin, message);

    cout << decodeSecrete(key, message);

    return 0;
}
