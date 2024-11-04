#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string s) {
        int n = s.size();
        string temp = "";
        int times = 1;
        char ch = s[0];
        for(int i=1;i<n;i++){
            if(s[i] == s[i-1]){
                times++;
            }
            else{
                // storing the previous computed strings..
                // Checking If the character is occurred more than 9 times:
                if(times < 10){
                    temp += to_string(times);
                    temp += ch;
                }else{
                    // while times is not equal to 0:
                    while(times > 0){
                        if(times > 9){
                            temp += to_string(9);
                            temp += ch;
                        }else{
                            temp += to_string(times);
                            temp += ch;
                        }
                        times = times - 9;
                    }
                }

                // reseting the values:
                times = 1;
                ch = s[i];
            }
        }
        // While storing leftover we will have to careful about the number grater than 9
        if(times < 10){
            temp += to_string(times);
            temp += ch;
        }else{
            // while times is not equal to 0:
            while(times > 0){
                if(times > 9){
                    temp += to_string(9);
                    temp += ch;
                }else{
                    temp += to_string(times);
                    temp += ch;
                }
                times = times - 9;
            }
        }

        return temp;
    }
};