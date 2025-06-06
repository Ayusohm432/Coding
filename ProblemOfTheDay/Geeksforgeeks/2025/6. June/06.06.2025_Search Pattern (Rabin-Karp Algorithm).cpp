/*
Problem Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
*/

/*Search Pattern (Rabin-Karp Algorithm)

Given two strings:

A text string in which you want to search.

A pattern string that you are looking for within the text.

Return all positions (1-based indexing) where the pattern occurs as a substring in the text. If the pattern does not occur, return an empty list.

All characters in both strings are lowercase English letters (a to z).

Examples:

Input: text = "birthdayboy", pattern = "birth"
Output: [1]
Explanation: The string "birth" occurs at index 1 in text.
Input: text = "geeksforgeeks", pattern = "geek"
Output: [1, 9]
Explanation: The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
Constraints:
1<= text.size() <=5*105
1<= pattern.size() <= text.size()

*/

class Solution {
  public:
    vector<int> search(string &pattern, string &text) {
        int patternLength = pattern.length();
        int textLength = text.length();

        vector<int> lpsArray(patternLength, 0);
        int prefixIndex = 0;

        for (int suffixIndex = 1; suffixIndex < patternLength; suffixIndex++) {
            while (prefixIndex > 0 && pattern[prefixIndex] != pattern[suffixIndex]) {
                prefixIndex = lpsArray[prefixIndex - 1];
            }
            if (pattern[prefixIndex] == pattern[suffixIndex]) {
                prefixIndex++;
            }
            lpsArray[suffixIndex] = prefixIndex;
        }

        vector<int> matchPositions;
        int patternIndex = 0;

        for (int textIndex = 0; textIndex < textLength; textIndex++) {
            while (patternIndex > 0 && pattern[patternIndex] != text[textIndex]) {
                patternIndex = lpsArray[patternIndex - 1];
            }
            if (text[textIndex] == pattern[patternIndex]) {
                patternIndex++;
            }

            if (patternIndex == patternLength) {
                matchPositions.push_back(textIndex - patternLength + 2);
                patternIndex = lpsArray[patternLength - 1];
            }
        }

        return matchPositions;
    }
};
