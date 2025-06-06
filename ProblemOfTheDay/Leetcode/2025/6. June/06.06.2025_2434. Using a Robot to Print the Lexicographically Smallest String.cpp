/*
Problem Link: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string?envType=daily-question&envId=2025-06-06
*/

/*2434. Using a Robot to Print the Lexicographically Smallest String

You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

 

Example 1:

Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
Example 2:

Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".
Example 3:

Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

*/

class Solution {
public:
    string robotWithString(string input) {
        int length = input.length();
        vector<char> smallestRight(length);
        
        smallestRight[length - 1] = input[length - 1];
        for (int idx = length - 2; idx >= 0; idx--) {
            smallestRight[idx] = min(input[idx], smallestRight[idx + 1]);
        }

        string stackStr = "";
        string result = "";

        int ptr = 0; 
        while (ptr < length) {
            stackStr.push_back(input[ptr]);

            char nextMin = (ptr + 1 < length) ? smallestRight[ptr + 1] : input[ptr];

            while (!stackStr.empty() && stackStr.back() <= nextMin) {
                result += stackStr.back();
                stackStr.pop_back();
            }

            ptr++;
        }

        while (!stackStr.empty()) {
            result += stackStr.back();
            stackStr.pop_back();
        }

        return result;
    }
};
