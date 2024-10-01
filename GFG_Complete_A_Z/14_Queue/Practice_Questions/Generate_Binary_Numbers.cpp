/*

//  Generate Binary Numbers

//  Observations: 
    * We are given n, & We need to generate all the binary number with decimal value from 1 to n.


// Queue:
                 back
        push -> [    | | | | | | |    ] pop -> 
                                  front
            
            * Insertion at end, & deletion back 
            * deletions from the front, pop()

// Intrusion:
    * We are using queue, to print the prime number: 
    * Example: 
            n = 5   
            for(i = 0 ;i < n; i++)
                Initially: q = [1] 
                i = 0
                    curr = q.front() = 1
                    q.pop() = []
                    vec = [1]
                    q.push(curr + '0') -> [10]
                    q.push(curr + '1') -> [11 10]
                
                i = 1
                    curr = q.front() = 10
                    q.pop() = [11]
                    vec = [1 10]
                    q.push(curr + '0') -> [100, 11]
                    q.push(curr + '1') -> [101, 100, 11]

                i = 2
                    curr = q.front() = 11
                    q.pop() = [101, 100]
                    vec = [1, 10, 11]
                    q.push(curr + '0') = [110, 101, 100]
                    q.push(curr + '1') = [111, 110, 101, 100]
                i = 3
                    curr = q.front() = 100
                    q.pop() = [111, 110, 101]
                    vec = [1, 10, 11, 100]
                    q.push(curr + '0') = [1000, 111, 110, 101]
                    q.push(curr + '1') = [1001, 1000, 111, 110, 101]
                i = 4
                    curr = q.front() = 101
                    q.pop() = [1001, 1000, 111, 110]
                    vec = [1, 10, 11, 100, 101]
                    q.push(curr + '0') = [1010, 1001, 1000, 111, 110]
                    q.push(curr + '1') = [1011, 1010, 1001, 1000, 111, 110]

                break => vec = {1, 10, 11, 100, 101}


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<string> generate(int N){
    vector<string> res;
    queue<string> q;
    q.push("1");    // inserting first value into queue, i.e 1

    for(int i=0;i<N;i++){
        // storing the front value frm queue in curr, to generate next upcoming binary numbers.
        string curr = q.front();
        q.pop();    // removing that element from the queue.

        res.push_back(curr);    // inserting the first element into vector

        // now making next two number with the help of current, by adding '0' at the end, & '1' at the end of curr.
        q.push(curr + '0');
        q.push(curr + '1');
    }

    return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}