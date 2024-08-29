/*

// Rabin Karp - Pattern Searching


// Observations: 
    * we are given string s, & pattern p, we have to check whether the pattern exist in string or not?



// Intrusion: 
    // Bruteforce approach: 
        * We are matching the string by comparing each element with pattern..
        * TC: O(n*m)
        * AS: O(1)
    
    // Rabin Karp Algo: 
        * We are calculating the hash of pattern & the hash of string, of size n(n is the pattern size) window which is the.
        * We are using rolling hash function:
            * we can create a hash window of pattern size, & while sliding window, we subtract the last value in window, & add new upcoming value in window.
            * We will use the rolling function that will iterate & find the window size 


*/

#include<bits/stdc++.h>
using namespace std;
#define d 256 // d is the number of characters in the input alphabet 

// Bruteforce: TC: O(n*m)
bool search(string pat, string txt, int q){

    for(int i=0;i<txt.size();i++){
        if(txt[i] == pat[0]){
            int ptr = i;
            bool isFound = 1;
            for(int j=0;j<pat.size();j++){
                if(txt[ptr] != pat[j]){
                    isFound = 0;
                    break;
                }else{
                    ptr++;
                }
            }
            if(isFound){
                return 1;
            }
        }
    }

    return 0;
} 

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 

// } Driver Code Ends