/*
Problem Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i?envType=daily-question&envId=2025-07-03
*/

/*3304. Find the K-th Character in String Game I

Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.

 

Example 1:

Input: k = 5

Output: "b"

Explanation:

Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".
Example 2:

Input: k = 10

Output: "c"

 

Constraints:

1 <= k <= 500

*/

class Solution {
    char findChar(int k, int level){
        if(level == 0){
            return 'a';
        }

        int len = 1 << level;
        int mid = len/2;

        if(k <= mid){
            return findChar(k, level-1);
        }else{
            return findChar(k-mid, level-1)+1;
        }
    }
public:
    char kthCharacter(int k) {
        int level = 0;
        while((1 << level) < k){
            level++;
        }
        return findChar(k, level);
    }
};