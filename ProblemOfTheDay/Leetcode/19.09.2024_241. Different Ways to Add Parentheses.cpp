/*
Problem Link : https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19
*/

/*241. Different Ways to Add Parentheses

Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

*/

class Solution {
public:
    vector<int> solve(string s){
        vector<int> result;

        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> leftResult = solve(s.substr(0 , i));
                vector<int> rightResult = solve(s.substr(i+1));

                for(int &x : leftResult){
                    for(int &y : rightResult){
                        if(s[i] == '+'){
                            result.push_back(x + y);
                        }
                        else if(s[i] == '-'){
                            result.push_back(x - y);
                        }
                        else{
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(s));
        }

        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};