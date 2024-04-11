/*
// Bitwise Operators: 
      * These operators are the logic gates operators AND, OR, XOR...

    Bitwise: OR  |

          A | B  =>  C
        --------------
          0 | 0  =>  0       
          0 | 1  =>  1       
          1 | 0  =>  1       
          1 | 1  =>  1       

                * Example: 
                              3 = 00000000...0011
                              6 = 00000000...0110  (|) OR
                            -------------------------
                                  00000000...0111      => 7

  * Bitwise: AND  &

          A | B  =>  C
        --------------
          0 | 0  =>  0       
          0 | 1  =>  0       
          1 | 0  =>  0       
          1 | 1  =>  1       
          
                * Example: 
                              3 = 00000000...0011
                              6 = 00000000...0110  (&) AND
                            -------------------------
                                  00000000...0010      => 2

  * Bitwise: XOR  ^  : Same false, different true

          A | B  =>  C
        --------------
          0 | 0  =>  0       
          0 | 1  =>  1       
          1 | 0  =>  1       
          1 | 1  =>  0       

                * Example: 
                              3 = 00000000...0011
                              6 = 00000000...0110  (^) OR
                            -------------------------
                                  00000000...0101      => 5

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bitwiseOR(){
    int x = 3;
    int y = 6;

    cout << "OR: " <<  (x | y) << endl;
}

void bitwiseAND(){
    int x = 3;
    int y = 6;

    cout << "AND: " << (x & y) << endl;
}

void bitwiseXOR(){
    int x = 3;
    int y = 6;

    cout << "XOR: " << (x ^ y) << endl;
}


int main(void){
    
    bitwiseOR();
    bitwiseAND();
    bitwiseXOR();
    
    
    return 0;
}