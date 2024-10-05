/*
Problem Link : https://leetcode.com/problems/permutation-in-string/?envType=daily-question&envId=2024-10-05
*/

/*567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

//Approach-1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m){
            return false;
        }

        sort(begin(s1) , end(s1));

        for(int i=0 ; i <= m-n ; i++){
            string subString = s2.substr(i , n);

            sort(begin(subString) , end(subString));

            if(s1 == subString){
                return true;
            }
        }

        return false;
    }
};

//Approach - 2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        unordered_map<char, int> mp1, mp2;
        for (char& ch : s1) {
            mp1[ch]++;
        }
        
        for (int i = 0; i < s2.length(); i++) {
            mp2[s2[i]]++;
            if (i >= s1.length()) {
                mp2[s2[i - s1.length()]]--;
                if (mp2[s2[i - s1.length()]] == 0) {
                    mp2.erase(s2[i - s1.length()]);
                }
            }
            if (mp1 == mp2) {
                return true;
            }
        }
        
        return false;
    }
};

//Approach-3
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m){
            return false;
        }

        vector<int> freq1(26 , 0);
        vector<int> freq2(26 , 0);

        for(char& ch : s1){
            freq1[ch - 'a']++;
        }
        
        int i=0;
        int j=0;

        while(j < m){
            freq2[s2[j] - 'a']++;

            if(j-i+1 > n){
                freq2[s2[i] - 'a']--;
                i++;
            }

            if(freq1 == freq2){
                return true;
            }

            j++;
        }

        return false;
    }
};