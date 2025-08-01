/*
Problem Link: https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1
*/

/*Last Moment Before All Ants Fall Out

We have a wooden plank of length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second, with some moving left and others right.
When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time. When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

Given an integer n and two integer arrays left[] and right[], the positions of the ants moving to the left and the right, return the time when the last ant(s) fall out of the plank.

Examples :

Input: n = 4, left[] = [2], right[] = [0, 1, 3]
Output: 4
        
Explanation: As seen in the above image, the last ant falls off the plank at t = 4.
Input:  n = 4, left[] = [], right[] = [0, 1, 2, 3, 4]
Output: 4
        
Explanation: All ants are going to the right, the ant at index 0 needs 4 seconds to fall.
Input: n = 3, left[] = [0], right[] = [3]
Output: 0
Explanation: The ants will fall off the plank as they are already on the end of the plank.
Constraints:
1 ≤ n ≤ 105
0 ≤ left.length, right.length ≤ n + 1
0 ≤ left[i], right[i] ≤ n
1 ≤ left.length + right.length ≤ n + 1
All values of left and right are unique, and each value can appear only in one of the two arrays.

*/

// User function Template for C++
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int result = 0;
        
        for(int i=0; i<left.size(); i++){
            result = max(result, left[i]);
        }
        
        for(int i=0; i<right.size(); i++){
            result = max(result, n-right[i]);
        }
        
        return result;
    }
};
