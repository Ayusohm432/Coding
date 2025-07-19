/*
Problem Link: https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1
*/

/*Count Unique Vowel Strings
You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

Identify all unique vowels (a, e, i, o, u) present in the string.
For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times, each occurrence represents a unique selection choice.
Generate all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.
Return the total number of such distinct strings.

Examples:

Input: s = "aeiou"
Output: 120
Explanation: Each vowel appears once, so the number of different strings can form is 5! = 120.
Input: s = "ae"
Output: 2
Explanation: Pick a and e, make all orders → "ae", "ea".
Input: s = "aacidf"
Output: 4 
Explanation: Vowels in s are 'a' and 'i', Pick each 'a' once with a single 'i', make all orders → "ai", "ia", "ai", "ia".
Constraints:
1 ≤ s.size() ≤ 100

*/

class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                mp[s[i]]++;
            }
        }
        
        int count = mp.size();
        if(count == 0){
            return 0;
        }
        int first = 1;
        for(int i=1; i<=count; i++){
            first *= i;
        }
        int second = 1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            second *= itr->second;
        }
        
        return first*second;
    }
};
