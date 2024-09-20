/*
Problem Link : https://leetcode.com/problems/shortest-palindrome/?envType=daily-question&envId=2024-09-20
*/

/*214. Shortest Palindrome

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

*/

//Approach-1
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));


        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) { 
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};


//Approach-2
class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;
    
        lps[0] = 0;
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0); 
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1];

        string culprit = rev.substr(0, s.length() - longestLPSLength); 

        return culprit + s;
    }
};