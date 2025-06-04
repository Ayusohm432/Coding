/*
Problem Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i?envType=daily-question&envId=2025-06-04
*/

/*3403. Find the Lexicographically Largest String From the Box I

You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.

 

Example 1:

Input: word = "dbca", numFriends = 2

Output: "dbc"

Explanation: 

All possible splits are:

"d" and "bca".
"db" and "ca".
"dbc" and "a".
Example 2:

Input: word = "gggg", numFriends = 4

Output: "g"

Explanation: 

The only possible split is: "g", "g", "g", and "g".

 

Constraints:

1 <= word.length <= 5 * 103
word consists only of lowercase English letters.
1 <= numFriends <= word.length

*/

class Solution {
    int startPoint(string& word, int n){
        int i = 0;
        int j = 1;

        while(j < n){
            int k = 0;

            while(j+k < n && word[i+k] == word[j+k]){
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]){
                i = j;
                j = j+1;
            }else{
                j = j + k + 1;
            }
        }

        return i;
    }
public:
    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1){
            return word;
        }

        int start = startPoint(word, n);

        int longestPath = n - (numFriends - 1);
        int possiblePath = min(longestPath, n-start);

        return word.substr(start, possiblePath);
    }
};