/*
Problem Link: https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1
*/

/*Find the longest string

Given an array of strings words[]. Find the longest string in words[] such that every prefix of it is also present in the array words[]. 

Note: If multiple strings have the same maximum length, return the lexicographically smallest one.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: pros
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
Input: words[] = ["ab", "a", "abc", "abd"]
Output: abc
Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".
Constraints:
1 ≤ words.length() ≤ 103
1 ≤ words[i].length ≤ 103

*/

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        unordered_set<string> st(words.begin(), words.end());
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            if(a.length() != b.length()){
                return a.length() > b.length();
            }
            return a < b;
        });
        
        for(string& word : words){
            bool prefix = true;
            for(int i=1; i<=word.length(); i++){
                if(st.find(word.substr(0, i)) == st.end()){
                    prefix = false;
                    break;
                }
            }
            if(prefix){
                return word;
            }
        }
        
        return "";
    }
};