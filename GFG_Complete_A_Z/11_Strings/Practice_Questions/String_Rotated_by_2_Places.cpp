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
                azon am clockwise   -> azonam

                amaz on
                on amaz Anti-clockwise   ->  onamaz


// Key Observations:
        * n = end()
        * Clockwise rotations: 
                amazon
                am azon 
                ma noza -> rev (0, 1) & rev(2, n)
                azonam  -> rev(0, n)

        * Anticlockwise rotations: 
                amazon
                amaz on
                zama no -> rev(0, n-2) & rev(n-2, n)
                onamaz  -> rev(0, n)


// Intrusion: 
    * rotate string by 2 place in clockwise & anticlockwise direction,
    * Check if any of these two matched with solution or not?

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isRotated(string a, string b){
        // common cases: 
        if(a.size() != b.size()) return 0;  // if size is not equal
        if(a == b) return 0;    // if string is same
        if(a.size() <= 2 || b.size() <= 2) return 0;    // if string size is less than 2

        // Clockwise:
        string clock = a;
        reverse(clock.begin(), clock.begin() + 2);
        reverse(clock.begin()+2, clock.end());
        reverse(clock.begin(), clock.end());


        // Anticlockwise: 

        string antiClock = a;
        reverse(antiClock.begin(), antiClock.end() - 2);
        reverse(antiClock.end()-2, antiClock.end());
        reverse(antiClock.begin(), antiClock.end());

        // checking clockwise or anticlockwise to match with string b.
        return (b == clock || b == antiClock);

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