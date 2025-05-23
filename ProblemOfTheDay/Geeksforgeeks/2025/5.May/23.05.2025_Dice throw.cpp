/*
Problem Link: https://www.geeksforgeeks.org/problems/dice-throw5349/1
*/

/*Dice throw

Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
Constraints:
1 <= m,n,x <= 50


*/

class Solution {
    int help(int m, int n, vector<vector<int>>& dp, int sum, int x){
        if(n == 0){
            return (sum == x) ? 1 : 0;
        }
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        int waysCount = 0;
        for(int i=1; i<=m; i++){
            if(sum + i <= x){
                waysCount += help(m, n-1, dp, sum+i, x);
            }
        }
        
        return dp[n][sum] = waysCount;
    }
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        return help(m, n, dp, 0, x);
    }
};