/*
Problem Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row?envType=daily-question&envId=2025-05-03
*/

/*1007. Minimum Domino Rotations For Equal Row

n a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6

*/

class Solution {
    int track(vector<int>& tops, vector<int>& bottoms, int val){
        int n = tops.size();

        int swapToTop = 0;
        int swapToBottom = 0;

        for(int i=0; i<n; i++){
            if(tops[i] != val && bottoms[i] != val){
                return -1;
            }else if(tops[i] != val){
                swapToTop++;
            }else if(bottoms[i] != val){
                swapToBottom++;
            }
        }

        return min(swapToTop, swapToBottom);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = INT_MAX;

        for(int val=1; val<=6; val++){
            int swaps = track(tops, bottoms, val);

            if(swaps != -1){
                rotations = min(rotations, swaps);
            }
        }    

        return rotations == INT_MAX ? -1 : rotations;
    }
};