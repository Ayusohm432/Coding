/*
Problem Link: https://leetcode.com/problems/letter-tile-possibilities?envType=daily-question&envId=2025-02-17
*/

/*1079. Letter Tile Possibilities

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1
 

Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/

class Solution {
    public:
        int total;
        void findSequences(vector<int>& count) {
            total++;
    
            for (int pos = 0; pos < 26; pos++) {
                if (count[pos] == 0) {
                    continue;
                }
    
                count[pos]--;
                findSequences(count);
                count[pos]++;
            }
        }
    
        int numTilePossibilities(std::string tiles) {
            total = 0;
    
            vector<int> count(26, 0);
            for (char c : tiles) {
                count[c - 'A']++;
            }
    
            findSequences(count);
            return total-1;
        }
    };