/*

// Naive Pattern Search


// Observations: 
    * Given a string s, & pattern p, both of lowercase characters.
    * Task to check the given pattern exist in string or not?
    * Return 1, if present : Else return -1
    * If string has no space in them, we have to match those patterns also..

// Example: 
    Input:
        S = aabaacaadaabaaabaa
        P = aaba
    Output: Yes
        Explanation: Given pattern aaba is found
        in the string at index 0.


    Input:
        S = aabaacaadaabaaabaa
        P = ccda
    Output: No
        Explanation: Given pattern ccda doesn't
        exists in the string at all.


// Intrusion: 
    * we can use window approach, when the first character of both the string is matched, we can increment the window size & check..
    * By doing this same operations we will do this again & again once until we found that pattern.
    * If we that pattern is not found we will return 0, else return 1

// Complexity: 
    * TC: O(n*m)
    * AS: O(1)


*/

#include<bits/stdc++.h> 
using namespace std; 


class Solution{
public:
    bool search(string pat, string txt){ 
        // outer loop will be the original text
        for(int i=0;i<txt.size();i++){
            // if character of original text matched with the first value of pattern
            if(txt[i] == pat[0]){
                int ptr = i;    // creating original text pointer that will matched with pattern.
                bool isFound = 1;   // making flag that will help us to find whether we have found the pattern or not?
                // inner loop will be the patter, because we are matching it again & again with every character of outer loop until we found the pattern.
                for(int j=0;j<pat.size();j++){
                    // checking the matching conditions.
                    if(txt[ptr] == pat[j]){
                        ptr++;
                    }
                    // if the patterns & original string character differ, we break the loop, & make flag false
                    else{
                        isFound = 0;
                        break;
                    }
                }
                // if flag is true, we return 1, means we have found
                if(isFound){
                    return 1;
                }
            }
        }
        return 0;
    }
};

int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    Solution obj;
	    if(obj.search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}