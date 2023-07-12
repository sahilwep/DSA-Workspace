/*
    * we know that when we extract the number, it extract it in reverse order.
    * when we have to add those extract no, for that we can use : 
        *  eg: 1 & 2 is two digit we need to make it => 12
            so if we do 1x10=>10
                          +2
                       -------
                          12 => this will become 12, so conclusion : num_1 * 10 + num_2

        * so we can say : our (previous_extract_value * 10 + next_extract_value) => will work as in reversing, because extracting is happening in reversed order.

*/

#include <iostream>
using namespace std;

int main(void){

    int n;
    cin >> n;
    int reverse = 0;
    while(n>0){
        int last_digit = n % 10;
        reverse = (reverse*10) + last_digit;
        n = n / 10; 
    }
    cout << reverse;

    return 0;
}