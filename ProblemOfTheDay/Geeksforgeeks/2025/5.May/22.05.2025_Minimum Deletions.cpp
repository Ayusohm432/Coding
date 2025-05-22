/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1
*/

/*Minimum Deletions

Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103

*/

class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n = s.length();
        string reverseString = s;
        reverse(reverseString.begin(), reverseString.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == reverseString[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int longestPalindromicSubsequence = dp[n][n];
        return n-longestPalindromicSubsequence;
    }
};