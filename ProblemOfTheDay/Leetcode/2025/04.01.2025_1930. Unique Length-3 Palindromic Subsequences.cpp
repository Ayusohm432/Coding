/*
Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences?envType=daily-question&envId=2025-01-04
*/

/*1930. Unique Length-3 Palindromic Subsequences

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.

*/

//Approach - 1
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unique_letters;
        
        for(char &ch : s) {
            unique_letters.insert(ch);
        }
        
        int result = 0;
        
        for(char letter : unique_letters) {
            
            int first_idx = -1;
            int last_idx  = -1;
            
            for(int i = 0; i<n; i++) {
                if(s[i] == letter) {
                    
                    if(first_idx == -1) {
                        first_idx = i;
                    }
                    
                    last_idx = i;
                    
                }
            }
            
                            
            unordered_set<char> st;
            for(int middle = first_idx+1; middle <= last_idx-1; middle++) {
                st.insert(s[middle]);
            }

            result += st.size();
            
        }
        
        return result;
    }
};

//Approach - 2

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        
        for(int i = 0; i<n; i++) {
            char ch = s[i];
            int idx = ch-'a';
            
            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        
        int result = 0;
        for(int i = 0; i<26; i++) {
            if(indices[i] == make_pair(-1, -1)) {
                continue;
            }
            
            unordered_set<char> st;
            for(int middle = indices[i].first+1; middle <= indices[i].second-1; middle++) {
                
                st.insert(s[middle]);
                
            }
            
            result += st.size();
        }
        
        return result;
    }
};



