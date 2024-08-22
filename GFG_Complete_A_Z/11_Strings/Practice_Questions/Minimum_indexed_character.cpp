/*

//  Minimum indexed character

// Observations: 
    * We are given string str, & string patt,
    * we need to find the minimum index of the character in string that has also present in patt.
    * We have to find the minimum index of character in str that is also present in patt.
    * If there is such character found return 1, else return -1


// Example: 
    
    Input:  str = geeksforgeeks
    patt = set
    Output: 1
        Explanation: e is the character which is
        present in given str "geeksforgeeks"
        and is also present in patt "set". Minimum
        index of e is 1. 

    Input:  str = adcffaet
    patt = onkl
    Output: -1
        Explanation: There are none of the
        characters which is common in patt
        and str.


// Intrusion: 
    // Approach 1: Bruteforce Solution: 
        * we can use nested loop, which we can compare the character sequence of both the string..
        * TC: O(n*m)
        * AS: O(1)
    

    // Approach 2: Using Frequency array:
        * We can use frequency array to store the frequency of patt, as we have to look in str, & return their minimum index..
        * We will create 26 size array that will store all the character frequency.
        * We can then iterate into the str, & return the minimum index once we found..
        * TC : O(n)    
        * AS : O(1), because we just store only 26 alphabets in hash array

    // Approach 2: Using Hashmap:
        * We can use map, unordered_map, or set data structure to store frequency of stirng patt.
        * Then we will look over the string str, & return the index if the character from hashmap is found in string str.
        * Else we return -1
        * TC : O(n)    
        * AS : O(1), because we just store only 26 alphabets in hashmap.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Bruteforce Solution:
    int minIndexChar_Brute(string str, string patt){

        for(int i=0;i<str.size();i++){
            for(int j=0;j<patt.size();j++){
                if(str[i] == patt[j]){
                    return i;
                }
            }
        }
        return -1;
    }

    // Frequency Array Approach: 
    int minIndexChar_Freq(string str, string patt){
        // storing the frequency of patt into hash array:
        vector<int> hash(26, 0);            // we have only 26 character in alphabet, so we can hash them in 26 size array..

        for(char c : patt){
            hash[c - 'a']++;    // subtracting 'a' from ascii value wll give the range b/w 0-26
        }

        // checking for minimum index character.

        for(int i=0;i<str.size();i++){
            // if character from string str, is found from hash, we will return the str index
            if(hash[str[i] - 'a']){
                return i;
            }
        }

        return -1;  // else return -1
    }

    // using hashmap: map or set
    int minIndexChar(string str, string patt){
        // Using Unordered map:
        unordered_map<char, bool> mp;
        for(auto i : patt){
            mp[i] = 1;
        }

        // Looking over the string str:
        for(int i=0;i<str.size();i++){
            // if character is found, we will return the index.
            if(mp[str[i]]){
                return i;
            }
        }
        return -1;  // else we will return -1.
    }

};


int main(){
	int t;
    cin>>t;
    while(t--){
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}