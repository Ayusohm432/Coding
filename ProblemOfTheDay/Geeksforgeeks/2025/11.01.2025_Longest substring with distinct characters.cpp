/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1
*/

/*Longest substring with distinct characters

Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.
Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.
Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
Constraints:
1<= s.size()<=3*104
All the characters are in lowercase.

*/

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int res = 0;
        int i = 0, j = 0;
        unordered_map<char, int> m;
        
        while (j < n) {
            if (m.find(s[j]) != m.end()) {
                i = max(i, m[s[j]] + 1);
            }
            m[s[j]] = j;
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};


