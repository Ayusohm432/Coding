/*
Problem Link: https://leetcode.com/problems/partition-labels?envType=daily-question&envId=2025-03-30
*/

/*763. Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.length();
    
            vector<int> result;
            vector<int> mp(26, -1);
    
            for(int i=0; i<n; i++){
                mp[s[i] - 'a'] = i;
            }
    
            int i = 0;
            while(i < n){
                int end = mp[s[i] - 'a'];
                int j = i;
                while(j < end){
                    end = max(end, mp[s[j] - 'a']);
                    j++;
                }
                result.push_back(j-i+1);
                i = j+1;
            }
            return result;
        }
    };