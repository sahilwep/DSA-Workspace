/*

//  Bit Difference

//  Observations: 
    * We are given two integer, & we need to find the number of bits that needs to be flipped to make A equal to B

// Example:

    Input: A = 10, B = 20
    Output: 4
    Explanation:
        A  = 01010
        B  = 10100
        As we can see, the bits of A that need 
        to be flipped are 01010. If we flip 
        these bits, we get 10100, which is B.


// Key Observations: 
        A  = 01010
        B  = 10100
        ------------
        XOR  11110

        XOR -> If the bits are same return 0, else return 1

// Intrusion: 
    // Converting decimal -> boolean string
        * Convert decimal to bool string..
        * Make sure that the total digits of string is 32, because for 4 bytes we have 32 bits.
        * Then compare it by iterating..

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    int countBitsFlip(int a, int b){
        // Convert decimal to binary:
        string strA = "";
        string strB = "";
        while(a){
            if(a & 1){
                strA += '1';
            }else{
                strA += '0';
            }
            a >>= 1;  // right shift by 1
        }

        while(b){
            if(b & 1){
                strB += '1';
            }else{
                strB += '0';
            }
            b >>= 1;  // right shift by 1
        }


        // making string size to 32, by stuffing 0 in front.
        for(int i=strA.size();i<=32;i++){
            strA += '0';
        }

        for(int i=strB.size();i<=32;i++){
            strB += '0';
        }

        // Reversing will flip the string in correct order.

        reverse(strA.begin(), strA.end());
        reverse(strB.begin(), strB.end());


        // Now Counting difference:
        int cntDiff = 0;
        for(int i=32;i>0;i--){
            if(strA[i] != strB[i]) cntDiff++;
        }

        return cntDiff;
    }
};


int main(){
	int t;
	cin>>t;// input the testcases
	while(t--){
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}