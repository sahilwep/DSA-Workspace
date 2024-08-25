/*

// Case-specific Sorting of Strings

// Observations: 
    * we are given string that contains uppercase & lowercase letter..
    * We have to sort them in a way such that ith character of lower case have sorted lowercase & position of uppercase have sorted uppercase...


// Example: 
    Input:  N = 12  S = defRTSersUXI
    Output: deeIRSfrsTUX
        Explanation: Sorted form of given string
        with the same case of character as that
        in original string is deeIRSfrsTUX

    Input:  N = 6   S = srbDKi
    Output: birDKs
        Explanation: Sorted form of given string
        with the same case of character will
        result in output as birDKs.

// Intrusion: 
    * store all upper & lower character separately, & then sort them...
    * In place of lower character insert sorted lower, & in place of upper character insert sorted upper.
    * TC: O(n*logn)
    * AS: O(n)


ASCII Values: 
    A = 65, Z = 90
    a = 97, z = 122
    0 = 48, 9 = 59


*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string caseSort(string s, int n){
        string lower = "";
        string upper = "";

        // Extracting lower & upper character:
        for(int i=0;i<n;i++){
            // Upper case:
            if(s[i] >= 65 && s[i] <= 90){
                upper += s[i];
            }
            // lower case:
            else{
                lower += s[i];
            }
        }

        // Sorting:
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Reinserting sorted lower & upper case:
        int p1 = 0, p2 = 0;
        for(int i=0;i<n;i++){
            // upper:
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = upper[p1++];
            }
            // lower:
            else{
                s[i] = lower[p2++];
            }
        }

        return s;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}