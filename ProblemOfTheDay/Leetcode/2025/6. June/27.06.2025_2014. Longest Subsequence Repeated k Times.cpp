/*
Problem Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times?envType=daily-question&envId=2025-06-27
*/

/*2014. Longest Subsequence Repeated k Times

You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

Example 1:

example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
Example 2:

Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
Example 3:

Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.

*/

class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int len = sub.length();
        int n = s.length();

        while(i < n && j < k*len) {
            if(s[i] == sub[j%len])
                j++;
            
            i++;
        }

        return j == k * len;
    }

    void backtracking(string& s, string &curr, vector<bool>& temp, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(temp[i] == false || requiredFreq[i] == 0){
                continue;
            }
            
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;
            backtracking(s, curr, temp, requiredFreq, k, maxLen);
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        vector<int> freq(26);
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> temp(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                temp[i] = true;
                requiredFreq[i] = freq[i]/k;
            }
        }

        int maxLen = n / k;
        string curr;
        backtracking(s, curr, temp, requiredFreq, k, maxLen);
        return result;
    }
};
