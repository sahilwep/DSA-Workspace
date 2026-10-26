/*

//  2409. Count Days Spent Together


//  Problem Statement: 
    - Alice and Bob are traveling to Rome for separate business meetings.
    - You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
    - Return the total number of days that Alice and Bob are in Rome together.
    - You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

 
// Example:
    Example 1:
        Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
        Output: 3
        Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

    Example 2:
        Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
        Output: 0
        Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

 

// Observations:
    - Alice and bob are traveling to rome to separate business meetings.
    - you are given 4 strings, arriveAlice, leaveAlice, arriveBob, and leaveBob. 
        - Alice will be in the city form the dates arriveAlice to leaveAlice (inclusive)
        - bob will be in the city same as alive (inclusive)
    - each will be 5-character string int he format "MM-DD", corresponding to the month and day of the date.
    - return the total number of days that alice and bob are in rome together.
    - You can assume that all dates occur in the same calender year, which is not a leap year.
    - NOTE: the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    // ApproachH:
        - from the given each month number of days:
            - we can check the month they will stay together:
                - suppose:
                    alice arrive at: 
                            8-th month, and leave in same 8th month
                        OR
                            8-th month, and leave in 9th month

                        we will calculate the total number of days:
                    and same with the bob:
                        - and check their journey overlapping.

                        Possible overlapping:   

                                    |---------|                     A
                                |------------------|                B
                                    |_________|                     overlapped area



                                |------------------|                A
                                    |----------|                    B



                                |-----------|                       A
                                    |-----------|                   B



                                    |-----------|                   A
                                |------------|                      B


                            start = max(aStart, bStart);            This will be our starting point
                            end = min(aliceEnd, bobEnd);            This is our ending point.

                            To get total days together, we only need that overlapping points.
                            - Now, we only have to incorporate the overlapping value from large range of days.


                        These are the 4 possible overlapping:
                            - we will have to check this, and calculate the number of overlapping:

// Complexity:
    - TC: O(n)
    - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int convertToDays(string &s, vector<int>& totalDays) {
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));

        int ans = 0;
        for(int i = 0; i < month - 1; i++) {
            ans += totalDays[i];
        }

        ans += day;

        return ans;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        // total number of days:
        vector<int> totalDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int start = max(convertToDays(arriveAlice, totalDays), convertToDays(arriveBob, totalDays));    // get the start range
        int end = min(convertToDays(leaveAlice, totalDays), convertToDays(leaveBob, totalDays));           // get the end range
        
        // Getting the total range:
        int ans = max(0, end - start + 1);

        return ans;
    }
};