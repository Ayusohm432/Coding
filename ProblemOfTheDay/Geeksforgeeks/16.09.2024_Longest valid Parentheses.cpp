/*
Problem Link ; https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
*/

/*Longest valid Parentheses

Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105  

*/

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int mx = 0, mx2 = 0 , cl = 0, op = 0;
        
        for(int i=0 ; i<str.length() ; i++){
            if(str[i] == '('){
                op++;
            }
            else{
                cl++;
            }
            if(cl > op){
                cl = op = 0;
            }
            if(cl == op){
                mx = max(mx , op * 2);
            }
        }
        
        op = cl = 0;
        
        for(int i = str.length()-1 ; i>=0 ; i--){
            if(str[i] == '('){
                op++;
            }
            else{
                cl++;
            }
            if(op > cl){
                op = cl = 0;
            }
            if(op == cl){
                mx2 = max(mx2 , op * 2);
            }
        }
        
        return max(mx , mx2);
    }
};