/*
Problem Link: https://leetcode.com/problems/count-the-number-of-ideal-arrays?envType=daily-question&envId=2025-04-22
*/

/*2338. Count the Number of Ideal Arrays

You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
Example 2:

Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays): 
   - With no other distinct values (1 array): [1,1,1,1,1] 
   - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
 

Constraints:

2 <= n <= 104
1 <= maxValue <= 104

*/

const int Mod = 1e9+7;
const int MaxN = 10010;
const int MaxK = 15;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        static bool initialized = false;
        static int comb[MaxN + MaxK][MaxK + 1] = {};
        static vector<vector<int>> factors(MaxN);
        static int spf[MaxN] = {};

        if(!initialized){
            initialized = true;

            comb[0][0] = 1;
            for(int i=1; i<MaxN+MaxK; i++){
                comb[i][0] = 1;
                for(int j=1; j<=min(i, MaxK); j++){
                    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % Mod;
                }
            }

            for(int i=2; i<MaxN; i++){
                if(spf[i] == 0){
                    for(int j=i; j<MaxN; j+=i){
                        if(spf[j] == 0){
                            spf[j] = i;
                        }
                    }
                }
            }

            for(int i=2; i<MaxN; i++){
                int x = i;
                while(x > 1){
                    int P = spf[x], cnt = 0;
                    while(x % P == 0){
                        x /= P;
                        cnt++;
                    }
                    factors[i].push_back(cnt);
                }
            }
        }    
        long long res = 0;
        for(int x = 1; x <= maxValue; x++){
            long long ways = 1;
            for(int cnt : factors[x]){
                ways = ways * comb[n + cnt - 1][cnt] % Mod;
            }
            res = (res + ways) % Mod;
        }

        return res;
    }
};