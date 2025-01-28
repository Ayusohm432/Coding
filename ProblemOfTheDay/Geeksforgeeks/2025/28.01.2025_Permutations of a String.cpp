/*
Problem Link: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
*/

/*Permutations of a String

Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.
Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
Constraints:
1 <= s.size() <= 9
s contains only Uppercase english alphabets

*/



class Solution {
  public:
    vector<string> findPermutation(string &s) {
        vector<string> result;
        permute(s, 0, s.size() - 1, result);
        set<string> uniquePermutations(result.begin(), result.end());
        result.assign(uniquePermutations.begin(), uniquePermutations.end());
        return result;
    }

    void permute(string &s, int left, int right, vector<string> &result) {
        if (left == right) {
            result.push_back(s);
        } else {
            for (int i = left; i <= right; i++) {
                swap(s[left], s[i]);
                permute(s, left + 1, right, result);
                swap(s[left], s[i]);
            }
        }
    }
};