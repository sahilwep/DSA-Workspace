/*

// Nth number made of prime digits

// Observations:
    * we have to find the sequence whose each digits are prime number, i.e: 2, 3, 5, 7.
    * In other word we have to find the nth number of this sequence: 2, 3, 5, 7, 22, 23, 25, 27, 32, 33....
    * In simple word, we are given n, & we have to find the nth prime sequence..


// Example: 
    Input: n = 10
    Output: 33
    Explanation: 10th number in the sequence of numbers whose each digit is prime is 33.

    Input: n = 21
    Output: 222
    Explanation: The 21st number in the sequence of numbers whose each digit is prime is 222.



// Intrusion:
    // Using Queue: 
        * First we initializes the first set of number into the queue.
        * at every iterations, we remove 1 element from front, & we insert the entire sequence of that element.
        * we will keep repeating this until the counter is equal to n, when counter is equal 1, we will have our nth element removed & stored into current.
        * We will return the current.

        * Example: n = 10th

                *  Sequence of number {2, 3, 5, 7}
                    first we will insert set of number into queue: [2 3 5 7]
                    * First iterations: 
                        removed 2, & insert whole element of sequence with the removed element: 
                                [3 5 7 22 23 25 27]
                    * Second iterations: 
                        removed 3, & insert whole element of sequence with the removed element: 
                                [5 7 22 23 25 27 32 33 35 37]
                    * Third iterations: 
                        removed 5, & insert whole element of sequence with the removed element: 
                                [7 22 23 25 27 32 33 35 37 52 53 55 57]
                    * Fourth iterations: 
                        removed 7, & insert whole element of sequence with the removed element: 
                                [22 23 25 27 32 33 35 37 52 53 55 57 72 73 75 77]
                    * Fifth iterations: 
                        removed 22, & insert whole element of sequence with the removed element: 
                                [23 25 27 32 33 35 37 52 53 55 57 72 73 75 77 222 223 225 227]
                    * Sixth iterations: 
                        removed 23, & insert whole element of sequence with the removed element: 
                                [25 27 32 33 35 37 52 53 55 57 72 73 75 77 222 223 225 227 232 233 235 237]
                    * seventh iterations: 
                        removed 25, & insert whole element of sequence with the removed element: 
                                [27 32 33 35 37 52 53 55 57 72 73 75 77 222 223 225 227 232 233 235 237 253 253 255 257]
                    * Eight iterations: 
                        removed 27, & insert whole element of sequence with the removed element: 
                                [32 33 35 37 52 53 55 57 72 73 75 77 222 223 225 227 232 233 235 237 253 253 255 257 272 273 275 277]
                    * Ninth iterations: 
                        removed 32, & insert whole element of sequence with the removed element: 
                                [33 35 37 52 53 55 57 72 73 75 77 222 223 225 227 232 233 235 237 253 253 255 257 272 273 275 277 322 323 325 327]
                    * Tenth iterations: 
                        removed 33, & insert whole element of sequence with the removed element: 
                                [35 37 52 53 55 57 72 73 75 77 222 223 225 227 232 233 235 237 253 253 255 257 272 273 275 277 322 323 325 327 332 333 335 337]
                    
                    i = 10, break & return the front element: 33


*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int primeDigits(int n){

        char sequence[4] = {'2', '3', '5', '7'};  // initialize the first 4 prime numbers
        queue<string> q;    // using queue to get the sequence of the series.

        //  First inserting the set of sequence into the queue
        for (char c : sequence) {
            q.push(string(1, c));
        }
        
        // Generating the sequence: 
        string result = "";     // result string that will store the every removed element of queue.
        int cnt = 0;    // counter that will count the every iteration, until we reach n.
        while (cnt < n) {
            string current = q.front(); // storing the front element of queue into current.
            q.pop();    // removing the front element,

            // s = s + ' ' current; // with this statement we can print the series.

            result = current;    // making result as our current, i.e front element of the queue, that we have just removed.
            cnt++;  // increment the counter.

            // at every iteration, we append the whole sequence of prime number with current removed element of queue
            for (char c : sequence) {
                q.push(current + c);    // pushing every item of sequence with prefix of "current"
            }
        }

        return stoi(result); // returning the last element that we have stored into string result, & we are converting it into integer.
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.primeDigits(n) << "\n";
    }
}