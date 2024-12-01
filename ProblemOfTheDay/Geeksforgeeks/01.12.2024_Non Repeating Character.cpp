/*
Problem link: https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1
*/

/*Non Repeating Character

Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.
Constraints:
1 <= s.size() <= 105

*/

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> frequency(26, 0);
        
        for(char& ch : s){
            frequency[ch - 'a']++;
        }
        
        for(char& ch : s){
            if(frequency[ch - 'a'] == 1){
                return ch;
            }
        }
        return '$';
        
    }
};