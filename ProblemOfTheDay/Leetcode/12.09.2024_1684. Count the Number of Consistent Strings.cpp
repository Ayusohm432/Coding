/*
problem Link : https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12
*/

/*1684. Count the Number of Consistent Strings


You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.

*/

//Approach-1
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;

        for(auto& ch : allowed){
            st.insert(ch);
        }

        int count = 0;
        for(int i=0 ; i<words.size() ; i++){
            bool isConsistent = true;
            for(int j=0 ; j<words[i].length() ; j++){
                if(st.find(words[i][j]) == st.end()){
                    isConsistent = false;
                    break;
                }
            }
            if(isConsistent) count++;
        }

        return count;
    }
};

//Approach-2
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        for(char& ch : allowed){
            mask |= (1 << (ch - 'a'));
        }

        int count = 0;

        for(string& word : words){
            bool isConsistent = true;

            for(char& ch : word){
                if(((mask >> (ch - 'a')) & 1) == 0){
                    isConsistent = false;
                    break;
                }
            }

            if(isConsistent){
                count++;
            }
        }
        return count;
    }
};