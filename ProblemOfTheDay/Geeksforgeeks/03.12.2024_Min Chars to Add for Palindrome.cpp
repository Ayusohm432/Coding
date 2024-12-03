/*
Problem link: https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1
*/

/*Min Chars to Add for Palindrome

Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
Constraints:
1 <= s.size() <= 106

*/

class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        string pat = s + "|" + rev;
        
        int k = pat.size();
        vector<int> lps(k, 0);
        
        for(int i=1, len=0; i < k;){
            if(pat[i] == pat[len]){
                lps[i++] = ++len;
            }
            else if(len){
                len = lps[len - 1];
            }
            else{
                lps[i++] = 0;
            }
        }
        
        return s.size() - lps[k-1];
    }
};
