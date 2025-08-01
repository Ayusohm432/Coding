/*
Problem Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order?envType=daily-question&envId=2025-06-09
*/

/*440. K-th Smallest in Lexicographical Order


Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109

*/

class Solution {
public:
    int calSteps(int n , long n1 , long n2){
        int steps = 0;
        while(n1 <= n){
            steps += min((long)n+1 , n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k-1;
        while(k > 0){
            int steps = calSteps(n , curr , curr+1);
            if(steps <= k){
                curr += 1;
                k -= steps;
            }
            else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};