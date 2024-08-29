/*
    Recursion : When function calling itself until a specific condition is met.
    * When the function call itself, it goes into a loop of calling itself again & again, & if we didn't specify any condition to it, that is when the segmentation fault happened or we generally say StackOverFlows. 
    * Stack is a memory, which holds the instruction that should have to executed by CPU.
    * This is why infinite recursion are not written, So we use some condition to break the recursion.
    
    * BASE CONDITION : The condition that we use to stop recursion is known as "Base Condition" 

    * RECURSION TREE : A representation from of recursion which depicts how function are called and return as a series of event happening conductively.It is a pictorial description of the process as illustration.
                f()
                    f()
                        f()
                            f()

    * When recursion call get completed, the control returns back to it's parent function which is then further executed until the last function waiting.
*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void func(){
    // Base Condition
    if(cnt == 5){
        return; 
    }
    else{
        // function call itself.
        cout << cnt << " ";      // this will the value of count.
        cnt++;                // this condition to increase the count, so it can break when (count==5)
        func();              // function call itself.
    }
}

int main(void){
   
    func();

    return 0;
}