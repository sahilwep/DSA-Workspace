/*
// Tail recursion:
    * A tail recursive function is more optimized than normal recursive function...
    * Modern compiler takes less times in tail recursive function compare to normal recursive function...
        * when modern compiler see's tail recursive function, it changes to { n = (n -1), & add goto stat}, in tail recursive function that takes less times..
        * So, after recursive call, when there is no such work to do, function return to parent call in tail recursion..


    * func0()  -> Function with tail recursion:
                func0(5)        -> parent call
                   |---->print(5)
                   |---->func0(4)
                            |---->print(4)
                            |---->func0(3)
                                    |---->print(3)
                                    |---->func0(2)
                                            |---->print(2)
                                            |---->func0(1)
                                                    |---->print(1)
                                                    |---->func0(0)
                                                            |----->                 -> return to parent call, because there is no such work to do after recursive call.


                * In Modern compiler, it changes to: 
                    * recursive call changes to (n = n -1), & add {goto:start} ..
                       
                        func0(int x){
                            start:
                                if(x == 0) return;
                                print(n);
                                n = n-1;
                                goto:start
                        }

                * So, they remove recursion completely, & this is how it's optimized..




    * func1()  -> Normal function without tail recursion:

                func1(5)
                    |--->func1(4)
                    |       |--->func1(3)
                    |       |      |--->func1(2)
                    |       |      |      |--->func1(1)
                    |       |      |      |     |--->func1(0)   -> return
                    |       |      |      |     |
                    |       |      |      |     |--->print(1)   -> return to statement after the recursive call..
                    |       |      |      |
                    |       |      |      |--->print(2)
                    |       |      |
                    |       |      |--->print(3)
                    |       |
                    |       |--->print(4)
                    |
                    |--->print(5)



    * Now, how to make normal function to tail recursive function, in case of this fun1()
        * We can add one more parameter to the func1() -> this will make this as tail recursive..

    * If we see the Comparision b/w the merge sort & quick sort: 
        * quick sort uses tail recursion, where as merge sort is uses normal recursive calls..
            * In merge sort: 
                * we first recursively call for the merge sort for the first half..
                * Then we recursively call for the merge sort for the second half..
                * Then we call the function merge(), 
                    * This happen only when we have recursively sorted first & second half..
                    * On the other hand in quick sort.
            * In Quick sort: 
                * we first call the function partition..
                * Then we recursively call for the left of partition,
                * and then we recursively call for the right of partition...
                * So the last recursive call in quick sort his tail recursive.

    * When we see tree traversal like : preOrder, inOrder, & postOrder: 
        * perOrder & inOrder uses tail recursive..
        * postOrder is not tail recursive,
        * This is why postOrder is slower than these two...

    * NOTE: Not all normal recursive function can be converted into the tail recursive...


    * Factorial of a number: 
        * The function is not tail recursive: 
            * Because recursive call is not the last thing that happen in this function..
            * It need to know the result of (n-1) & multiply with n & then return...
            * So this is not the tail recursive...
            * Parent call is not finished immediate after child call, because it going to use the result of child call & multiply it with n..

    * We can make this to tail recursive with using additional parameter, (k = 1), which make it tail recursive..

    * It's good to have tail recursive function, because with modern compiler will takes less times..


*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// print n to 1:    tail recursive
void func0(int n){
    if(n == 0){
        return;
    }
    cout << n << " ";
    func0(n-1);
}

// print 1 to n:    not tail recursive
void func1(int n){
    if(n == 0){
        return;
    }
    func1(n-1);
    cout << n << " ";

}

// print 1 to n:    converting func1() into tail recursive
void func2(int n, int k){
    if(n == 0){
        return;
    }
    cout << k << " ";
    func2(n-1, k+1);

}


// factorial of number:  This is not tail recursive function.
int factorial(int n){
    if(n == 0 || n == 1) return 1;
    return n * factorial(n -1);         // we are multiply n with every (n-1) call..
}

// factorial of number:  Tail recursive function.
int factorial_tail(int n, int k){
    if(n == 0 || n == 1) return k;  // at las when n == 1 or 0, we return the value of k
    return factorial_tail(n - 1, k * n);    // at ever call k gets multiply with n...
}

int main(void){
    
    int n;
    cin >> n;
    func0(n);
    cout << endl;
    func1(n);
    cout << endl;
    func2(n, 1);
    cout << endl;
    cout << factorial(n) << endl;
    cout << factorial_tail(n, 1) << endl;
    
    
    return 0;
}