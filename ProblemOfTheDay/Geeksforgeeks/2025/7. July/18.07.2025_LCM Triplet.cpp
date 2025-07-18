/*
Problem Link: https://www.geeksforgeeks.org/problems/lcm-triplet1501/1
*/

/*LCM Triplet

Given a number n. Find the maximum possible LCM that can be obtained by selecting three numbers less than or equal to n.
Note : LCM stands for Lowest Common Multiple.

Examples:

Input: n = 9
Output: 504
Explanation: 504 is the maximum LCM that can be attained by any triplet of numbers less than or equal 9. The triplet which has this LCM is {7, 8, 9}.
Input: n = 7
Output: 210
Explanation: 210 is the maximum LCM that can be attained by any triplet of numbers less than or equal 7. The triplet which has this LCM is {5, 6, 7}.
Constraints:
1 ≤ n ≤ 103

*/

class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        if(n < 3){
            return n;
        }
        if(n % 2 != 0){
            return n*(n-1)*(n-2);
        }
        if(n % 3 == 0){
            return (n-1)*(n-2)*(n-3);
        }
        return n*(n-1)*(n-3);
    }
};