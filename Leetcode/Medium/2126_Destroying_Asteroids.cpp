/*

//  2126. Destroying Asteroids


//  Problem Statement: 
    -> You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.
    -> You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.
    -> Return true if all asteroids can be destroyed. Otherwise, return false.

    
// Exapmle:
    Example 1:
        Input: mass = 10, asteroids = [3,9,19,5,21]
        Output: true
        Explanation: One way to order the asteroids is [9,19,5,3,21]:
        - The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
        - The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
        - The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
        - The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
        - The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
        All asteroids are destroyed.

    Example 2:
        Input: mass = 5, asteroids = [4,9,23,4]
        Output: false
        Explanation: 
        The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
        After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
        This is less than 23, so a collision would not destroy the last asteroid.


// Observations: 
    -> If we sort the give astroids, it will help us to encounter with lesser mass & we will add them up into our planet mass...

    Example:
        Input: mass = 10, asteroids = [3,9,19,5,21]

            m = 10,     [3,5,9,19,21] Sorted

                i = 0:  
                    10 > 3
                    newMass = 10 + 3 = 13

                i = 1:  
                    13 > 5
                    newMass = 13 + 5 = 18

                i = 2:  
                    18 > 9
                    newMass = 18 + 9 = 27
                
                i = 3:
                    27 > 19
                    newMass = 27 + 19 = 46

                i = 4: 
                    46 > 21
                    newMass = 46 + 21

                    Yes all astroid can be destroyed..

    Example:
        Input: mass = 5, asteroids = [4,9,23,4]

                m = 5   [4, 4, 9, 23]

                i = 0:
                    5 > 4
                    newMass = 5 + 4 = 9

                i = 1: 
                    9 > 4
                    newMass = 9 + 4 = 13

                i = 2: 
                    13 > 9
                    newMass = 13 + 9 = 22
                
                i = 3: 
                    22 < 23 => failed   return false..
                    

// Complexity:
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(begin(asteroids), end(asteroids));

        long long cmpMass = mass;
        for(auto &asMass: asteroids) {
            if(cmpMass < asMass) return false; // failed here...
            cmpMass += asMass;
        }
        
        return true;    // yes all asteroid can be destroyed..
    }
};s