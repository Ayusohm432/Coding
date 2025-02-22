/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
*/

/*Longest valid Parentheses

Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
Examples :

Input: s = "((()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Input: s = ")()())"
Output: 4
Explanation: The longest valid parenthesis substring is "()()".
Input: s = "())()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Constraints:
1 ≤ s.size() ≤ 106  
s consists of '(' and ')' only

*/

class Solution {
    public:
      int maxLength(string& s) {
          // code here
          int n = s.size();
          vector<int> dp(n+1, 0);
          stack<int> st;
          int length = 0;
          
          for(int i=1; i<=n; i++){
              if(s[i-1] == '('){
                  st.push(i);
              }else{
                  if(!st.empty()){
                      int j = st.top();
                      st.pop();
                      dp[i] = dp[j-1] + (i-j+1);
                      length = max(length, dp[i]);
                  }
              }
          }
          
          return length;
      }
  };