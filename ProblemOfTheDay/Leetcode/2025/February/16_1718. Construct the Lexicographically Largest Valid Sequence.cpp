/*
Problem Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence?envType=daily-question&envId=2025-02-16
*/

/*1718. Construct the Lexicographically Largest Valid Sequence

Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20

*/

class Solution {
    public:
    
        bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
            if(i >= result.size()) {
                return true; //gauranteed answer - we were filling largest numbers first
            }
    
            if(result[i] != -1) {
                return solve(i+1, n, result, used);
            }
    
            for(int num = n; num >= 1; num--) {
                if(used[num]) {
                    continue;
                }
    
                //try
                used[num] = true;
                result[i] = num;
    
                //EXPLORE
                if(num == 1) {
                    if(solve(i+1, n, result, used) == true) {
                        return true;
                    }
                } else {
                    int j = result[i] + i;
    
                    if(j < result.size() && result[j] == -1) {
                        result[j] = num;
                        if(solve(i+1, n, result, used) == true) {
                            return true;
                        }
                        result[j] = -1;
                    }
                }
    
                //UNDO
                used[num] = false;
                result[i] = -1;
            }
    
            return false;
        }
    
        vector<int> constructDistancedSequence(int n) {
            vector<int> result(2*n-1, -1);
    
            vector<bool> used(n+1, false);
    
            solve(0, n, result, used);
    
            return result;
        }
    };
    