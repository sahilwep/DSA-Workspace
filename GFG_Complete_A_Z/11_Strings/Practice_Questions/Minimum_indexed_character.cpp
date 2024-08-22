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
    




*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Bruteforce Solution:
    int minIndexChar(string str, string patt){

        for(int i=0;i<str.size();i++){
            for(int j=0;j<patt.size();j++){
                if(str[i] == patt[j]){
                    return i;
                }
            }
        }
        return -1;
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