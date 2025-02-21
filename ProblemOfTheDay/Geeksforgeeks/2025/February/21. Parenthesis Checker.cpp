/*
Problem Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/

/*Parenthesis Checker

Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "([]"
Output: False
Explanation: The expression is not balanced as there is a missing ')' at the end.
Input: s = "([{]})"
Output: False
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
Constraints:
1 ≤ s.size() ≤ 106
s[i] ∈ {'{', '}', '(', ')', '[', ']'}

*/


  class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char> st;
          unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};
          for(char& ch : s){
              if(mapping.find(ch) != mapping.end()){
                  if(st.empty() || st.top() != mapping[ch]){
                      return false;
                  }
                  st.pop();
              } else {
                  st.push(ch);
              }
          }
          return st.empty();
      }
};