/*
// Practice on recursion Part 1: 


// Recursive tree of func1(): 

    main()
       |---> func1(3)
       |        |---> print(3)      *
       |        |
       |        |---> func1(2)
       |        |       |---> print(2)      *
       |        |       |
       |        |       |---> func1(1)
       |        |       |       |---> print(1)      *
       |        |       |       |
       |        |       |       |---> func(0)
       |        |       |       |
       |        |       |       |---> print(1)      *
       |        |       |
       |        |       |---> print(2)      *
       |        |       
       |        |---> print(3)      *
       |
       |---> return to main() 


// Recursive tree of func2(): 

    main()
       |---> func2(3)
       |        |---> func1(2)
       |        |       |---> func1(1)
       |        |       |       |---> func(0)
       |        |       |       |---> print(1)          *
       |        |       |       |---> func(0)
       |        |       |
       |        |       |---> print(2)          *
       |        |       |---> func1(1)
       |        |               |--->func(0);
       |        |               |---> print(1);         *
       |        |               |--->func(0);
       |        |
       |        |---> print(3)          *
       |        |---> func(2)
       |                |---> func(1)
       |                |       |---> func(0);
       |                |       |---> print(1);     *
       |                |       |---> func(0);
       |                |
       |                |---->print(2)          *
       |                |--->func(1)
       |                        |--->func(0);
       |                        |--->print(1);      *
       |                        |--->func(0);
       |
       |--> return to main()


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void func1(int x){
    if(x==0) return;
    cout << x << endl;
    func1(x-1);
    cout << x << endl;
}

void func2(int x){
    if(x == 0) return;
    func2(x-1);
    cout << x << endl;
    func2(x-1);
}


int main(void){
    
    // func1(3);
    func2(3);
    
    
    return 0;
}