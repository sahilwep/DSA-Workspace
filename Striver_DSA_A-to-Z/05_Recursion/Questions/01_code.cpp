// print names for n times

// Note : Base case decides by the problem statement 
#include<iostream>
using namespace std;

//  TC : O(n)   // since function call n times
//  SC : O(n)   // because at base case it will return and our base condition when (i>n) near about when (i = n), so SC is Ow(n)

// Method : 2 
// we can print 1 to n times
void print(int i, int n){
    // base condition
    if(i>n) return;
    cout << "Sahil" << endl;
    // function call itself;
    print(i+1,n);
}

int main(void){
    int n;
    cin >> n;
    print(1,n);

    return 0;

}


/*
// Method : 1
void print(int times, string name){
    if(times==0){
        return;
    }
    else{
        cout << name << endl;
        print(times-1, name);
    }
}

int main(void){

    int times = 5;
    string name = "Sahil";

    print(times, name);

    return 0;
}
*/