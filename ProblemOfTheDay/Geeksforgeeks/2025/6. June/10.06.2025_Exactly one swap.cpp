/*
Problem Link: https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1
*/

/*Exactly one swap

Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

Examples:

Input: s = "geek"
Output: 6
Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
Input: s = "aaaa"
Output: 1
Explanation: Only one distinct string is possible after one swap(i.e "aaaa")
Constraints:
2 ≤ s.size() ≤ 104

*/

class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n = s.length();
        
        unordered_map<char, int> mp;
        for(char& ch: s){
            mp[ch]++;
        }
        
        int result = 0;
        bool flag = false;
        
        for(char ch : s){
            if(mp[ch] > 1){
                flag = true;
            }
            result += n - mp[ch];
        }
        
        result /= 2;
        if(flag){
            result += 1;
        }
        
        return result;
    }
};
