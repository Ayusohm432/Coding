/*
Problem Link: https://www.geeksforgeeks.org/problems/number-of-coins1824/1
*/

/*Coin Change (Minimum Coins)

You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

Examples:

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation: Minimum 2 coins needed, 25 and 5  
Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1
Input: coins[] = [5, 1], sum = 0
Output: 0
Explanation: For 0 sum, we do not need a coin
Input: coins[] = [4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum.
 
Constraints:
1 ≤ sum * coins.size() ≤ 106
0 <= sum <= 104
1 <= coins[i] <= 104
1 <= coins.size() <= 103


*/

class Solution {
    public:
      int solve(vector<int>& coins, int sum, int index, vector<vector<int>>& dp){
          if(index == coins.size()){
              return INT_MAX;
          }
          
          if(sum == 0){
              return 0;
          }
          
          if(dp[sum][index] != -1){
              return dp[sum][index];
          }
          
          int count = INT_MAX;
          if(coins[index] <= sum){
              int temp = solve(coins, sum-coins[index], index, dp);
              if(temp != INT_MAX){
                  count = min(1+temp, count);
              }
          }
          count = min(solve(coins, sum, index+1, dp), count);
          return dp[sum][index] = count;
      }
      int minCoins(vector<int> &coins, int sum) {
          // code here
          int n = coins.size();
          vector<vector<int>> dp(sum+1, vector<int>(n+1, -1));
          sort(coins.begin(), coins.end(), greater<int>());
          int result = solve(coins, sum, 0, dp);
          return result == INT_MAX ? -1 : result;
      }
  };