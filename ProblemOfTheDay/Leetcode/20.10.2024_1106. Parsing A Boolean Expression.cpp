/*
Problem Link : https://leetcode.com/problems/parsing-a-boolean-expression?envType=daily-question&envId=2024-10-20
*/

/*1106. Parsing A Boolean Expression

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

 

Example 1:

Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
Example 2:

Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
Example 3:

Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
 

Constraints:

1 <= expression.length <= 2 * 104
expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

*/
class Solution {
public:
    char evaluate(vector<char>& operand , char opr){
        if(opr == '!'){
            return operand[0] == 't' ? 'f' : 't';
        }

        if(opr == '&'){
            return any_of(begin(operand) , end(operand) , [](char ch) {return ch == 'f'; }) ? 'f' : 't';
        }

        if(opr == '|'){
            return any_of(begin(operand) , end(operand) , [](char ch) {return ch == 't'; }) ? 't' : 'f';
        }
        
        return 't';
    }
    
    bool parseBoolExpr(string expression) {
        int n = expression.length();

        stack<char> st;

        for(int i=0 ; i<n ; i++){
            if(expression[i] == ','){
                continue;
            }
            if(expression[i] == ')'){
                vector<char> Operand;
                while(st.top() != '('){
                    Operand.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char Operator = st.top();
                st.pop();
                st.push(evaluate(Operand , Operator));
            }
            else{
                st.push(expression[i]);
            }
        }

        return st.top() == 't' ? true : false;
    }
};