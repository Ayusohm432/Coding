/*
Problem Link: https://www.geeksforgeeks.org/problems/check-frequencies4211/1
*/

/*Check if frequencies can be equal

Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:

Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.
Constraints:
1 ≤ s.size() ≤ 105

*/

class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> freq(26, 0);
        for(auto& ch : s){
            freq[ch - 'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<>());
        
        set<int> st;
        for(auto& ch : freq){
            if(ch > 0){
                st.insert(ch);
            }
        }
        
        if(st.size() > 2){
            return false;
        }
        
        if(st.size() == 1){
            return true;
        }
        
        if(*st.begin() == 1){
            return true;
        }
        
        if(freq[0] != freq[1]+1){
            return false;
        }
        
        return true;
    }
};