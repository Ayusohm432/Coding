/*
Problem Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1
*/

/*Search Pattern (KMP-Algorithm)Search Pattern (KMP-Algorithm)

Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 
Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.
Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
Explanation:

Constraints:
1 ≤ txt.size() ≤ 106
1 ≤ pat.size() < txt.size()
Both the strings consist of lowercase English alphabets.

*/

class Solution {
  public:
    void computeLPS(string pattern, vector<int>& lps){
        int m = pattern.length();
        int len = 0;
        lps[0] = 0;
        
        int i = 1;
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int n = txt.length();
        int m = pat.length();
        vector<int> result;
        
        vector<int> lps(m, 0);
        computeLPS(pat, lps);
        
        int i = 0;
        int j = 0;
        
        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }
            
            if(j == m){
                result.push_back(i-j);
                j = lps[j-1];
            }
            else if(i < n && pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }
        return result;
    }
};