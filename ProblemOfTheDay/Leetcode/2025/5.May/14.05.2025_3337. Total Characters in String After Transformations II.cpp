/*
Problem Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii?envType=daily-question&envId=2025-05-14
*/

/*3337. Total Characters in String After Transformations II

You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:

Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2, nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]

Output: 7

Explanation:

First Transformation (t = 1):

'a' becomes 'b' as nums[0] == 1
'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'y' becomes 'z' as nums[24] == 1
'y' becomes 'z' as nums[24] == 1
String after the first transformation: "bcdzz"
Second Transformation (t = 2):

'b' becomes 'c' as nums[1] == 1
'c' becomes 'd' as nums[2] == 1
'd' becomes 'e' as nums[3] == 1
'z' becomes 'ab' as nums[25] == 2
'z' becomes 'ab' as nums[25] == 2
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.

Example 2:

Input: s = "azbk", t = 1, nums = [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]

Output: 8

Explanation:

First Transformation (t = 1):

'a' becomes 'bc' as nums[0] == 2
'z' becomes 'ab' as nums[25] == 2
'b' becomes 'cd' as nums[1] == 2
'k' becomes 'lm' as nums[10] == 2
String after the first transformation: "bcabcdlm"
Final Length of the string: The string is "bcabcdlm", which has 8 characters.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 109
nums.length == 26
1 <= nums[i] <= 25

*/

const int mod = 1e9+7;
class Solution {
    vector<vector<long long>> matrixMultiplication(vector<vector<long long>>& a, vector<vector<long long>>& b){
        vector<vector<long long>> result(26, vector<long long>(26, 0));

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                if(a[i][j] == 0){
                    continue;
                }
                for(int k=0; k<26; k++){
                    result[i][k] = (result[i][k] + a[i][j] * b[j][k]) % mod;
                }
            }
        }
        return result;
    }

    vector<vector<long long>> findMatrix(vector<vector<long long>>& mat, int power){
        vector<vector<long long>> result(26, vector<long long>(26, 0));
        for(int i=0; i<26; i++){
            result[i][i] = 1;
        }

        vector<vector<long long>> base = mat;

        while(power > 0){
            if(power % 2 == 1){
                result = matrixMultiplication(result, base);
            }
            base = matrixMultiplication(base, base);
            power /= 2;
        }
        return result;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> dp(26, vector<long long>(26, 0));

        for(int i=0; i<26; i++){
            for(int j=1; j<=nums[i]; j++){
                dp[i][(i + j) % 26]++;
            }
        }

        vector<vector<long long>> dp_exponent = findMatrix(dp, t);

        vector<long long> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }

        long long total = 0;
        for(int j=0; j<26; j++){
            long long sum = 0;
            for(int i=0; i<26; i++){
                sum = (sum + freq[i] * dp_exponent[i][j]) % mod;
            }
            total = (total + sum) % mod;
        }

        return total;
    }
};