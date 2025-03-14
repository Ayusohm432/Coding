/*
Problem link: https://www.geeksforgeeks.org/problems/coin-change2448/1
*/

/*Coin Change (Count Ways)

Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
Answers are guaranteed to fit into a 32-bit integer. 

Examples:

Input: coins[] = [1, 2, 3], sum = 4
Output: 4
Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
Input: coins[] = [2, 5, 3, 6], sum = 10
Output: 5
Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
Input: coins[] = [5, 10], sum = 3
Output: 0
Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.
Constraints:
1 <= sum <= 103
1 <= coins[i] <= 104
1 <= coins.size() <= 103

*/

class Solution {
    public:
      int solve(int index, int sum, vector<int>& coins, vector<vector<int>>& dp){
          if(sum == 0){
              return 1;
          }
          
          if(index < 0){
              return 0;
          }
          
          if(dp[index][sum] != -1){
              return dp[index][sum];
          }
          
          int ways = 0;
          
          for(int i=0; i<=sum; i+=coins[index]){
              ways += solve(index-1, sum - i, coins, dp);
          }
          
          return dp[index][sum] = ways;
          
      }
      int count(vector<int>& coins, int sum) {
          // code here.
          int n = coins.size();
          vector<vector<int>> dp(n, vector<int>(sum+9, -1));
          return solve(n-1, sum, coins, dp);
      }
  };