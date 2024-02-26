/*
// find the frequency of characters that comes into a string
// hash the character : (a-z)

//  eg :  s = "abcdadf"
    a : 2
    b : 1
    c : 1
    d : 2
    f : 1
    x : 0
// observation : 
    * since there are 256 character in ASCII code : 
        * 'a' : 97
        * 'A' : 65
    * we have to work with only the small character : we know that there are 26 letters in alphabets.
    * we can create the hash array of size (hash[26])
    * then we can perform precomputation, and fetching.
    * for each character, we can store, like previous we don in (code_1), but here we will subtracting with the character 'a'
// logic : 
    * eg : "abcdadf"
    * since the character hash array start from 0 to 26 : 
        * we can say to store 'a' at '0th' index, we need to insert by : (ch - 'a')
        * ch is s[i], i.e : for first element of string : a, (s[0] = a), So, ('a' - 'a') (in ascii (97-97)) is 0 (0th index)
        * for third element of string : d, (s[3] = d), So, ('d' - 'a') : (in ascii ( 100 - 97)) : 3(3rd index)
        * for fetching : 
        * if user provide ch = f :  hash[(ch - 'a')]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void findFreq(string s){
        // precomputation : 
        int hash[26] = {0}; // declaring the hash array with each element "0"
        for(int i=0;i<s.size();i++){
            /*
            // as our hash[] array is in int type, so the characters are auto typecasts into int
            // we take the char, and sub from 'a' : will give the index to the hash[] array,
            // and store the element on that place.
            */
            hash[s[i]-'a'] = hash[s[i]-'a'] + 1; 
        }
        int q;
        cin >> q;   // taking the query
        while (q--){
            char ch;
            cin >> ch;
            // fetching : 
            // for getting the index element, i.e our frequency, we fetch it by (ch -'a')
            cout << hash[ch-'a'] << endl;
        }
    }
};


int main(void){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        obj.findFreq(s);
        cout << endl;
    }
    return 0;
}