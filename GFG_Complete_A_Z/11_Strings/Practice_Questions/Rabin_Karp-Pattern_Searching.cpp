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
        * 


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