/*
Problem link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii?envType=daily-question&envId=2025-03-10
*/

/*3306. Count of Substrings Containing Every Vowel and K Consonants II

You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5

*/

class Solution {
    public:
        bool isVowel(char &ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        }
        long long countOfSubstrings(string word, int k) {
            int n = word.length();
            unordered_map<char, int> mp;
            vector<int> nextCons(n);
            int lastConsIdx = n;
    
            for(int i=n-1; i>=0; i--){
                nextCons[i] = lastConsIdx;
                if(!isVowel(word[i])){
                    lastConsIdx = i;
                }
            }
    
            int i = 0;
            int j = 0;
            long long count = 0;
            int cons = 0;
    
            while(j < n){
                char ch = word[j];
                if(isVowel(ch)){
                    mp[ch]++;
                }else{
                    cons++;
                }
    
                while(cons > k){
                    char ch = word[i];
                    if(isVowel(ch)){
                        mp[ch]--;
                        if(mp[ch] == 0){
                            mp.erase(ch);
                        }
                    }else{
                        cons--;
                    }
                    i++;
                }
    
                while(i < n && mp.size() == 5 && cons == k){
                    int idx = nextCons[j];
                    count += idx - j;
                    char ch = word[i];
    
                    if(isVowel(ch)){
                        mp[ch]--;
                        if(mp[ch] == 0){
                            mp.erase(ch);
                        }
                    }else{
                        cons--;
                    }
                    i++;
                }
                j++;
            }
            return count;
        }
    };