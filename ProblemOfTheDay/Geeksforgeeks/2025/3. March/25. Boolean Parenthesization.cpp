/*
Problem link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

/*Boolean Parenthesization

You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).
Constraints:
1 ≤ |s| ≤ 100 

*/

class Solution {
    public:
      int countWays(string &s) {
          const int n = (s.size() + 1) / 2;
          
          vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n));
          for (int i = 0; i < n; ++i) {
              dp[i][i][s[i * 2] == 'T'] = 1;
          }
          
          for (int len = 1; len < n; ++len) {
              for (int r = len; r < n; ++r) {
                  const int l = r - len;
  
                  for (int k = l; k < r; ++k) {
                      for (int i = 0; i < 2; ++i) {
                          for (int j = 0; j < 2; ++j) {
                              bool idx;
                              if (s[k * 2 + 1] == '&') {
                                  idx = i & j;
                              }
                              else if (s[k * 2 + 1] == '|') {
                                  idx = i | j;
                              }
                              else {
                                  idx = i ^ j;
                              }
                              
                              dp[l][r][idx] += dp[l][k][i] * dp[k + 1][r][j];
                          }
                      }
                  }
              }
          }
          
          return dp[0][n - 1][1];
      }
  };