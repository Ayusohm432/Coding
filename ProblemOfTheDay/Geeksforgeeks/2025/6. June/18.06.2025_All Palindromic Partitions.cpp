/*
Problem Link: https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
*/

/*All Palindromic Partitions

Given a string s, find all possible ways to partition it such that every substring in the partition is a palindrome.

Examples:

Input: s = "geeks"
Output: [[g, e, e, k, s], [g, ee, k, s]]
Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.
Input: s = "abcba"
Output: [[a, b, c, b, a], [a, bcb, a], [abcba]]
Explanation: [a, b, c, b, a], [a, bcb, a] and [abcba] are the only partitions of "abcba" where each substring is a palindrome.
Constraints:
1 ≤ s.size() ≤ 20

*/

class Solution {
    bool isPalindrome(const string&s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void help(string&s, vector<string>& temp, vector<vector<string>>& result, int start){
        if(start >= s.length()){
            result.push_back(temp);
            return;
        }
        
        for(int i=start; i<s.length(); i++){
            if(isPalindrome(s, start, i)){
                temp.push_back(s.substr(start, i-start+1));
                help(s, temp, result, i+1);
                temp.pop_back();
            }
        }
    }
  public:
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> result;
        vector<string> temp;
        help(s, temp, result, 0);
        return result;
    }
};