/*

// String Rotated by 2 Places


// Observations: 
    * We are given two string a, & b, we have to check whether the string b is obtained by rotating(in any direction) string 'a' exactly by 2 places
    * 


// Example: 
    Input:
        a = amazon
        b = azonam
    Output: 1
        Explanation: 
        amazon can be rotated anti-clockwise by two places, which will make it as azonam.

    Input:
        a = geeksforgeeks
        b = geeksgeeksfor
    Output: 0
        Explanation: 
        If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.


        a = amazon, b = azonam

                am azon
                azonam

                am azon
                ma noza

                azonam



*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isRotated(string a, string b){
        if(a == b) return 0;
        map<char, int> mp;
        

    }

};

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}