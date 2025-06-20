/*
Problem Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes?envType=daily-question&envId=2025-06-20
*/

/*3443. Maximum Manhattan Distance After K Changes

You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

'N' : Move north by 1 unit.
'S' : Move south by 1 unit.
'E' : Move east by 1 unit.
'W' : Move west by 1 unit.
Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 

Example 1:

Input: s = "NWSE", k = 1

Output: 3

Explanation:

Change s[2] from 'S' to 'N'. The string s becomes "NWNE".

Movement	Position (x, y)	Manhattan Distance	Maximum
s[0] == 'N'	(0, 1)	0 + 1 = 1	1
s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
s[3] == 'E'	(0, 2)	0 + 2 = 2	3
The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.

Example 2:

Input: s = "NSWWEW", k = 3

Output: 6

Explanation:

Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".

The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.

 

Constraints:

1 <= s.length <= 105
0 <= k <= s.length
s consists of only 'N', 'S', 'E', and 'W'.

*/

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int length = s.length();
        int up = 0, down = 0, right = 0, left = 0;
        int max_distance = 0;

        for (int index = 0; index < length; index++)
        {
            if (s[index] == 'N')
            {
                up++;
            }
            else if (s[index] == 'S')
            {
                down++;
            }
            else if (s[index] == 'E')
            {
                right++;
            }
            else if (s[index] == 'W')
            {
                left++;
            }

            int vertical_shift = abs(up - down);
            int horizontal_shift = abs(right - left);
            int base_distance = vertical_shift + horizontal_shift;

            int interfering_moves = min(up, down) + min(right, left);
            int max_possible_distance = base_distance + min(k, interfering_moves) * 2;

            max_distance = max(max_distance, min(index + 1, max_possible_distance));
        }

        return max_distance;
    }
};