/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
*/

/*Longest Palindrome in a String

Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
Input: s = “Geeks” 
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks". 
Input: s = “abc” 
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.
Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.

*/

class Solution {
    public:
      string longestPalindrome(string &s) {
          // code here
          int n = s.length();
          vector<vector<bool>> dp(n, vector<bool>(n, false));
          
          int index = -1;
          int length = -1;
          
          for(int len = 0 ; len < n; len++){
              int i, j; 
              
              for(i=0, j=i+len; j<n; i++, j++){
                  if(i == j){
                      dp[i][j] = true;
                  }else if(j == i+1 && s[i] == s[j]){
                      dp[i][j] = true;
                  }else if(s[i] == s[j] && dp[i+1][j-1]){
                      dp[i][j] = true;
                  }
                  
                  if(dp[i][j] && (length < (j - i + 1))){
                      index = i;
                      length = j - i + 1;
                  }
              }
          }
          
          return s.substr(index, length);
      }
  };