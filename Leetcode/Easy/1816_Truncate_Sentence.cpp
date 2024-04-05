/*
// 1816. Truncate Sentence      https://leetcode.com/problems/truncate-sentence/description/


    Example 1:
        Input: s = "Hello how are you Contestant", k = 4
        Output: "Hello how are you"
        Explanation:
        The words in s are ["Hello", "how" "are", "you", "Contestant"].
        The first 4 words are ["Hello", "how", "are", "you"].
        Hence, you should return "Hello how are you".

    Example 2:
        Input: s = "What is the solution to this problem", k = 4
        Output: "What is the solution"
        Explanation:
        The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
        The first 4 words are ["What", "is", "the", "solution"].
        Hence, you should return "What is the solution".

    Example 3:
        Input: s = "chopper is not a tanuki", k = 5
        Output: "chopper is not a tanuki"


// TC: O(n)
// AS: O(1)


*/
#include<bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k) {
    string res;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            cnt++;
        }
        if(cnt < k){
            res += s[i];
        }
    }
    return res;

}

int main(void){

    string s;
    getline(cin , s);
    int k;
    cin >> k;

    cout << truncateSentence(s, k);

    return 0;
}