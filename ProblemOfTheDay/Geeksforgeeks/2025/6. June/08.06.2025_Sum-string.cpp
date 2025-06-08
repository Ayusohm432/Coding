/*
Problem Link: https://www.geeksforgeeks.org/problems/sum-string3151/1
*/

/*Sum-string

Given a string s consisting of digits, determine whether it can be classified as a sum-string.

A sum-string is a string that can be split into more than two non-empty substrings such that:


The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

This condition must apply recursively to the substrings before it.

The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

Examples:

Input: s = "12243660"
Output: true
Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
Input: s = "1111112223"
Output: true
Explanation: Split the string as {"1", "111", "112", "223"}, where:
112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
Input: s = "123456"
Output: false
Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
Constraints:
1 ≤ s.size() ≤ 100
String consists of characters from '0' to '9'.

*/

class Solution {
  public:
    string addString(string first, string second){
        string result;
        int carry = 0;
        int i = first.length() - 1;
        int j = second.length() - 1;
        
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += first[i--] - '0';
            }
            if(j >= 0){
                sum += second[j--] - '0';
            }
            
            result.insert(result.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        
        return result;
    }
    bool isValid(string& first, string& second, string remaining){
        string sum = addString(first, second);
        if(remaining.substr(0, sum.size()) != sum){
            return false;
        }
        if(remaining == sum){
            return true;
        }
        return isValid(second, sum, remaining.substr(sum.size()));
    }
    bool isSumString(string &s) {
        // code here
        int n = s.length();
        
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                string first = s.substr(0, i);
                string second = s.substr(i, j-i);
                
                if((first.length() > 1 && first[0] == '0') || (second.length() > 1 && second[0] == '0')){
                    continue;
                }
                
                if(isValid(first, second, s.substr(j))){
                    return true;
                }
            }
        }
        
        return false;
    }
};