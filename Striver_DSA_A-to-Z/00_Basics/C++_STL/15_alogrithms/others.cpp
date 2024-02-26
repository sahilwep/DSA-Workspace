/*
    Binary : use __builtin_popcount()  or  __builtin_popcountll() function to know no of setbits in binary of any number.  
    
    Permutation : eg : 123
                        (123, 132, 213, 231, 312, 321) 

            next_permutation()  is used to know all the permutation of any number.

    NOTE : 231 has permutation : 
            (231, 312, 321)
        * It's important if we want to print all permutation, we started in sorted. 
        So, we can sort(s.begin(), s.end())
        then, use next_permutation() function.

*/  

#include <bits/stdc++.h>
using namespace std;

void explainOthers(){

    // binary : 
    int num = 7;    // in binary : 7 is 111
    int cnt = __builtin_popcount(num);  // this will give the number of "setbits"
    cout << endl << cnt;    // print 3

    int num_0 = 8;  // in binary : 8 is 1000, so set bits are 1
    cout << endl <<  __builtin_popcount(num_0); // return set bits

    long long num_1 = 12231241231;
    int cnt_1 = __builtin_popcountll(num_1); // this will return number of set bits;
    cout << endl << cnt_1 << endl;  // print number of sign bits in num_1

    // permutation :
    string s = "123";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(), s.end()));
    cout << endl << endl;

    // what if the string is 213: it gives 213, 231, 312, 321
    string s_1 = "213";
    // before sorted
    do{
        cout << s_1 << endl;
    }while(next_permutation(s_1.begin(), s_1.end()));
    cout << endl << endl;
    // sorting
    sort(s_1.begin(), s_1.end());
    // after sorted.
    do{
        cout << s_1 << endl;
    }while(next_permutation(s_1.begin(), s_1.end()));
    cout << endl << endl;


    // finding the max & min element in array
    vector<int> a = {12, 32, 42, 13, 48};

    cout << endl << *max_element(a.begin(), a.end());
    cout << endl << *min_element(a.begin(), a.end());

}

// simple function that find max & min element
void max(vector<int> a){
    int max = a[0]; // let consider as max element
    int min = a[0]; // let consider as min element
    for(int i = 0; i<a.size(); i++){
        if(max < a[i]) max = a[i];
        else min = a[i];
    }
    cout << endl << "max element is : " << max;
    cout << endl << "max element is : " << min;
}


int main(void){

    explainOthers();
    cout << endl;
    vector<int> a = {12, 32, 42, 13, 48};

    max(a);

    return 0;
}