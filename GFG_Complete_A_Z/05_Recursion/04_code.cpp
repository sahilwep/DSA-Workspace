/*
// Practice on recursion Part 2:


// recursive call of func1() & Complexity analysis: 

    main()
        |---> func(16)
        |       |---> func(8)
        |       |       |---> func(4)
        |       |       |       |---> func(2)
        |       |       |       |       |---> func(1)
        |       |       |       |       |---> return 0;
        |       |       |       |
        |       |       |       |---> return 1 + 0;
        |       |       |       
        |       |       |---> return 1 + 1;
        |       |
        |       |---> return 1 + 2
        |
        |---> return 1 + 3


fun(1) = 0
fun(2) = 1 + func(1) = 1
fun(4) = 1 + func(2) = 2
fun(8) = 1 + func(4) = 3
fun(16) = 1 + func(8) = 4
...
...

TC : log(base2)n, logn


* When we use : (return 1+fun1(n/3);)
* for power of 3 also we will get the same answer..


* Note: if we divide it by 3, The complexity will be change, it works on base3
* We also have to change the base case: ((n < 3) return 0;)
TC : log(base3)n, 



// Recursive tree for func2(): 

    main()
      |---> func2(7);
      |       |---> func2(3);
      |       |         |---> func2(1);
      |       |         |       |---> func2(0)
      |       |         |               |---> return;
      |       |         |
      |       |         |---> print(n%2) : 1
      |       |
      |       |---> print(n%2) : 1
      |
      |---> print(n%2) : 1
      |
      |---> control  return to main()


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int func1(int x){
    if(x == 1) return 0;
    else
        return 1 + func1(x/2);
}

void func2(int x){
    if(x == 0) return;
    func2(x/2);
    cout << (x % 2); 
}

int main(void){
    
    // cout << func1(16) << endl;

    func2(7);

    
    
    return 0;
}