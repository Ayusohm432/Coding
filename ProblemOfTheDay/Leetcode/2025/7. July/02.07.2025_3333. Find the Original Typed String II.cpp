/*
Problem Link; https://leetcode.com/problems/find-the-original-typed-string-ii?envType=daily-question&envId=2025-07-02
*/

/*3333. Find the Original Typed String II

Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: word = "aabbccdd", k = 7

Output: 5

Explanation:

The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".

Example 2:

Input: word = "aabbccdd", k = 8

Output: 1

Explanation:

The only possible string is "aabbccdd".

Example 3:

Input: word = "aaabbb", k = 3

Output: 8

 

Constraints:

1 <= word.length <= 5 * 105
word consists only of lowercase English letters.
1 <= k <= 2000

*/

class Solution {
    int mod = 1e9+7;
public:
    int possibleStringCount(string word, int k) {
        int n = word.length();
        int streak = 1;
        vector<int> groupLengths;

        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]){
                streak++;
            }else{
                groupLengths.push_back(streak);
                streak = 1;
            }
        }

        groupLengths.push_back(streak);

        long long totalWays = 1;
        for(int count : groupLengths){
            totalWays = (totalWays*count) % mod;
        }

        if(groupLengths.size() >= k){
            return static_cast<int>(totalWays);
        }

        vector<int> dp(k), prefixSum(k, 1);
        dp[0] = 1;

        for(int group : groupLengths){
            vector<int> newDp(k);
            for(int i=1; i<k; i++){
                newDp[i] = prefixSum[i-1];
                if(i-group-1 >= 0){
                    newDp[i] = (newDp[i] - prefixSum[i-group-1] + mod) % mod;
                }
            }

            vector<int> newPrefix(k);
            newPrefix[0] = newDp[0];
            for(int i=1; i<k; i++){
                newPrefix[i] = (newPrefix[i-1] + newDp[i]) % mod;
            }

            dp = move(newDp);
            prefixSum = move(newPrefix);
        }
        return (totalWays - prefixSum[k-1] + mod) % mod;
    }
};