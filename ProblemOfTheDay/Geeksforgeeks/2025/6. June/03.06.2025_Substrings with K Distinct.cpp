/*
Problem Link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
*/

/*Substrings with K Distinct

Given a string consisting of lowercase characters and an integer k, the task is to count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Examples :

Input: s = "abc", k = 2
Output: 2
Explanation: Possible substrings are ["ab", "bc"]
Input: s = "aba", k = 2
Output: 3
Explanation: Possible substrings are ["ab", "ba", "aba"]
Input: s = "aa", k = 1
Output: 3
Explanation: Possible substrings are ["a", "a", "aa"]
Constraints:
1 ≤ s.size() ≤ 106
1 ≤ k ≤ 26

*/

class Solution {
    int atMostK(string& s, int k){
        int n = s.length();
        int i=0, j=0;
        int count = 0;
        unordered_map<char, int> mp;
        
        for(j=0; j<n; j++){
            if(mp[s[j]] == 0){
                k--;
            }
            mp[s[j]]++;
            
            while(k < 0){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    k++;
                }
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
  public:
    int countSubstr(string& s, int k) {
        // code here.
        return atMostK(s, k) - atMostK(s, k-1);
    }
};