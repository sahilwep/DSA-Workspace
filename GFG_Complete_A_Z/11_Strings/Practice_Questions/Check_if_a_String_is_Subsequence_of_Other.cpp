/*
// Check if a String is Subsequence of Other

// Observations: 
    * we are given string a, & b, and we have to find the a is subsequence of b or not?
    * Subsequence: a sequence that can be derived from another sequence by deleting some element without changing the order of the remaining elements.

// Intrusion: 
    * We use two pointer approach
        * first pointer will be on the subsequence, & second on the original string.
        * if character on subsequence string match with original string we will keep moving the pointer & try to match the string..
    * TC: O(n*m)
    * AS: O(m)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to check if a string is subsequence of other string.
    // a is subsequence, & b is original string
    bool isSubSequence(string a, string b){
        // iteration start from original string:
        for(int i=0;i<b.size();i++){
            // if current element is matched with sequence first character:
            if(b[i] == a[0]){
                int ptr = i;    // first pointer: this will keep iterating in original string & try to match with sequence character.
                int k = 1;  // second pointer: this will iterate in sequence string & try to match with original string characters.
                string s = "";  // string to check given sequence is correct or not?
                s+= a[0];   // storing the first element into string
                // now we have to match in original string, that's why pointer 1 will iterate in original string.
                for(int j=ptr+1;j<b.size();j++){
                    // if ptr1(original string) matched with ptr2(given subsequence)
                    if(b[j] == a[k]){
                        s += b[j];  // storing the character into string.
                        k++;    // increment the pointer of subsequence, so that we can match..
                    }
                }
                // if subsequence is matched with string that we have created..
                if(s == a){
                    return 1;   // return 1
                }
            }
        }
        return 0;   // else return 0
    }
};

int main(){
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans == true)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}