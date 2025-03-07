/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

/*Longest Palindromic Subsequence

Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.

Examples:

Input: s = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
Input: s = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
Input: s = "agbdba"
Output: 5
Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.
Constraints:
1 ≤ s.size() ≤ 1000
The string contains only lowercase letters.

*/

class Solution {
    public:
    
      int solve(string &s, int i, int j, vector<vector<int>> &dp){
          if(i > j){
              return 0;
          }
          
          if(i == j){
              return 1;
          }
          
          if(dp[i][j] != -1){
              return dp[i][j];
          }
          
          if(s[i] == s[j]){
              return dp[i][j] = 2 + solve(s, i+1, j-1, dp);
          }else{
              return dp[i][j] = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
          }
      }
      int longestPalinSubseq(string &s) {
          // code here
          int n = s.size();
          
          vector<vector<int>> dp(n, vector<int>(n, -1));
          
          return solve(s, 0, n-1, dp);
      }
  };
  