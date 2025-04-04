/*
Problem Link : https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1
*/

/*Nearest multiple of 10

A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= str.size()<= 105

*/
class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.length();
        n--;
        if(str[n] <= '5'){
            str[n] = '0';
            return str;
        }
        
        str[n] = '0';
        n--;
        
        while(n>=0 && str[n] == '9'){
            str[n] = '0';
            n--;
        }
        if(n == -1){
            return '1'+ str;
        }
        str[n]+= 1;
        return str;
    }
};