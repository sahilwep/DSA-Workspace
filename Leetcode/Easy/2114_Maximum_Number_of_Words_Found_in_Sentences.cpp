/*

// 2114. Maximum Number of Words Found in Sentences         https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/


    Example 1:
        Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
        Output: 6
        Explanation: 
        - The first sentence, "alice and bob love leetcode", has 5 words in total.
        - The second sentence, "i think so too", has 4 words in total.
        - The third sentence, "this is great thanks very much", has 6 words in total.
        Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.

    Example 2:
        Input: sentences = ["please wait", "continue to fight", "continue to win"]
        Output: 3
        Explanation: It is possible that multiple sentences contain the same number of words. 
        In this example, the second and third sentences (underlined) have the same number of words.

// TC : O(n*m)

*/

#include<bits/stdc++.h>
using namespace std;

// TC : O(n*m)
int mostWordsFound(vector<string>& s) {
    if(s.size() == 0) return 0;
    int res = 0;
    for(int i=0;i<s.size();i++){
        string temp = s[i];
        int count = 0;
        for(int j=0;j<temp.size();j++){
            if(temp[j] == ' '){
                count++;
                res = max(res, count);
            }
        }
    }
    res++; 
    return res;
}


int main(void){

    vector<string> s;   // vector of string : store an array of string.
    string str; // string to take input of every line
    while(getline(cin, str)){
        if(str.empty()){
            break;
        }
        s.push_back(str);
    }

    // printing the vector string.
    // for(int i=0;i<s.size();i++){
    //     for(int j=0;j<s[i].size();j++){
    //         cout << s[i][j];
    //     }
    //     cout << endl;
    // }

    cout << mostWordsFound(s);

    return 0;
}