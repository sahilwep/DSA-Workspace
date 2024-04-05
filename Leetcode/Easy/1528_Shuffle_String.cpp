/*

// 1528. Shuffle String             https://leetcode.com/problems/shuffle-string/description/

    Example 1: 
        Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
        Output: "leetcode"
        Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

    Example 2:
        Input: s = "abc", indices = [0,1,2]
        Output: "abc"
        Explanation: After shuffling, each character remains in its position.


            Indices:       4 5 6 7 0 2 1 3
            String:        c o d e l e e t

            * Now we have to change the position of string index with the corrsponding indices
            * Output will be:
            
                        l e e t c o d e
                        0 1 2 3 4 5 6 7

// Complexity: 
    // TC : O(n)
    // AS : O(n)

*/


#include<bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    string temp = s;
    for(int i=0;i<s.size();i++){
        int ind = indices[i];
        temp[ind] = s[i];
    }
    return temp;
}

int main(void){

    string s;
    vector<int> indices;
    getline(cin, s);
    int k;
    // -1 index is invalid, so we are using -1
    while(true){
        cin >> k;
        if(k == -1) break;
        indices.push_back(k);
    }

    cout << restoreString(s, indices);

    return 0;
}