/*
Problem Link: https://leetcode.com/problems/valid-word?envType=daily-question&envId=2025-07-15
*/

/*3136. Valid Word


A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 

Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.

 

Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.


*/

class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3){
            return false;
        }
        bool isVowel = false;
        bool isConsonant = false;
        
        for(char ch : word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(vowels.count(ch)){
                    isVowel = true;
                }else{
                    isConsonant = true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }
        return isVowel && isConsonant;
    }   
};