/*
Problem Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
*/

/*Evaluation of Postfix Expression

You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Key Details:

The valid operators are '+', '-', '*', and '/'.
Each operand is guaranteed to be a valid integer or another expression.
The division operation between two integers always rounds the result towards zero, discarding any fractional part.
No division by zero will occur in the input.
The input is a valid arithmetic expression in Reverse Polish Notation.
The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
Examples:

Input: arr = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
Input: arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
Output: 757
Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7  = 150 * 5 + 7 = 757.
Constraints:

1 <= arr.size() <= 105
arr[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-104, 104]

*/

class Solution {
    public:
      int applyOperator(int num1, int num2, string& opr){
          if(opr == "+"){
              return num1 + num2;
          }
          if(opr == "-"){
              return num1 - num2;
          }
          if(opr == "*"){
              return num1 * num2;
          }
          if(opr == "/"){
              return num1 / num2;
          }
      }
      int evaluate(vector<string>& arr) {
          // code here
          stack<int> st;
          int n = arr.size();
          
          unordered_set<string> Operator = {"+", "-", "*", "/"};
          
          for(int i=0; i<n; i++){
              if(!st.empty() && Operator.find(arr[i]) != Operator.end()){
                  int num1 = st.top();
                  st.pop();
                  if(!st.empty()){
                      int num2 = st.top();
                      st.pop();
                      int result = applyOperator(num2, num1, arr[i]);
                      st.push(result);
                  }else{
                      st.push(num1);
                  }
              }else{
                  st.push(stoi(arr[i]));
              }
          }
          return st.top();
      }
  };