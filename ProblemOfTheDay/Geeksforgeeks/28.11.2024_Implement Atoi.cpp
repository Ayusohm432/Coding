/*
Problem Link : https://www.geeksforgeeks.org/problems/implement-atoi/1
*/

/*Implement Atoi

Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0.
Input: s = " 1231231231311133"
Output: 2147483647
Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.
Input: s = "-999999999999"
Output: -2147483648
Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.
Input: s = "  -0012gfg4"
Output: -12
Explanation: Nothing is read after -12 as a non-digit character ‘g’ was encountered.
Constraints:
1 ≤ |s| ≤ 15

*/

class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i = 0;
        int sign = 1;
        long result = 0;
        
        while(s[i] == ' '){
            i++;
        }
        
        if(s[i] == '+' || s[i] == '-'){
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        
        while(s[i] >= '0' && s[i] <= '9'){
            result = (result * 10) + (s[i] - '0');
            i++;
            
            if(sign * result > INT_MAX){
                return INT_MAX;
            }
            if(result * sign < INT_MIN){
                return INT_MIN;
            }
        }
        
        return (int)(sign * result);
    }
};
