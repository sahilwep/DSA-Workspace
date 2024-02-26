/*
     what is armstrong number ?
        eg : 371 => if (3^3 + 7^3 + 1^3) = 371, then number is armstrong.
        eg : 1634 => if (1^4 + 6^4 + 3^4 + 4^4) = 1643, then number is armstrong.
        eg : 51 => if(5^2 + 1^2) != 52, so this number is not armstrong.

        Conclusion : 
            * we have to find the number of digits in number, for that we can use "log10(num)"
            * we can extract the individual bits in number and perform this operation : 
            * we can use "pow()" function which will does this operation.
                * Like number is given to pos is : pow(4,3) => 4*4*4 : 4^3 , pow(5, 2) => 2*2*2*2*2 : 2^5
            * or we can create a function that will work like "pow()" function.
            * then we can compare the result with the original value, & if it's true then number is armstrong.
        Resource : 
                    * https://mathworld.wolfram.com/NarcissisticNumber.html        
                    * https://www.geeksforgeeks.org/power-function-c-cpp/

*/  

#include <bits/stdc++.h>
using namespace std;

// Optional :  This function is equivalent to pow() function, we can use in a place of pow(), & it will work same.
int power(int base_value, int power_value){
    int result = 1;
    for(int i = 1; i <= power_value; i++){
        result = result  * base_value;
    }
    return result;
}

int main(void){
    
    // Test Case : 
    // int num = 371;
    // int num = 1634;      // these numbers are armstrong numbers.
    // int num = 54748;     // these numbers are armstrong numbers.
    // long long num = 32164049651;     // these numbers are armstrong numbers.
    // int num = 121;      // this is not armstrong number
    
    int num;
    cin >> num;
    long long int temp_num = num;
    long long int result = 0;
    int count_digit = (log10(num) + 1 );    // this will count the number of digit.
    while (temp_num > 0){
        long long last_digit = temp_num % 10; // for extracting bits.
        result = result + pow(last_digit, count_digit);    // this will store the result number.
        temp_num = temp_num / 10;   // for making number from 1234 -> 123
    }
    (result == num ) ? cout << "True" : cout << "False";    // comparision case.

    return 0;   
}