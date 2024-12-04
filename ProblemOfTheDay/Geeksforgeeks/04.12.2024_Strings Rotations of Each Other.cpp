/*
Problem Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
*/

/*Strings Rotations of Each Other

You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
Constraints:
1 <= s1.size(), s2.size() <= 105

*/

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string str = s2 + '|' + s1 + s1;
        int n = str.length();
        int i = 0;
        int j = 1;
        int m = s2.length();
        
        vector<int> lps(n, 0);
        while(j < n){
            if(str[i] == str[j]){
                lps[j++] = ++i;
                if(i == m){
                    return true;
                }
            }
            else if(i){
                i = lps[i - 1];
            }
            else{
                j++;
            }
        }
        return false;
    }
};