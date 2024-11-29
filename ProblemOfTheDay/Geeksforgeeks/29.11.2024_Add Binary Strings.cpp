/*
Problem Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/add-binary-strings3805
*/

/*Add Binary Strings

Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106

*/  

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string answer; 
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        
        int carry = 0; 
        
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += (s1[i] - '0');
                i--;
            }
            if(j >= 0){
                sum += (s2[j] - '0');
                j--;
            }
            
            carry = sum / 2;
            
            int result = sum % 2;
            
            answer = (char)(result + '0') + answer;
        }
        
        while(answer.length() > 1 && answer[0] == '0'){
            answer.erase(answer.begin());
        }
        return answer;
    }
};