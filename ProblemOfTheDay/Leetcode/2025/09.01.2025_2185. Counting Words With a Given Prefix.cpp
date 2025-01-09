/*
Problem link: https://leetcode.com/problems/counting-words-with-a-given-prefix?envType=daily-question&envId=2025-01-09
*/

/*2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.


*/

class Solution {
public:
    bool isPrefix(string& str1, string& str2){
        int l1 = str1.length();
        int l2 = str2.length();

        if(l1 > l2){
            return false;
        }

        if(str2.substr(0, l1) != str1){
            return false;
        }

        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string& word : words){
            if(isPrefix(pref, word)){
                count++;
            }
        }

        return count;
    }
};