/*
Problem Link: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements?envType=daily-question&envId=2025-06-17
*/

/*3405. Count the Number of Arrays with K Matching Adjacent Elements

You are given three integers n, m, k. A good array arr of size n is defined as follows:

Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, m = 2, k = 1

Output: 4

Explanation:

There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
Hence, the answer is 4.
Example 2:

Input: n = 4, m = 2, k = 2

Output: 6

Explanation:

The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
Hence, the answer is 6.
Example 3:

Input: n = 5, m = 2, k = 0

Output: 2

Explanation:

The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
 

Constraints:

1 <= n <= 105
1 <= m <= 105
0 <= k <= n - 1

*/

class Solution {
    const int mod = 1e9+7;
    long long modPower(long long x, int exp){
        if(exp == 0){
            return 1;
        }
        long long half = modPower(x, exp/2);
        half = (half * half) % mod;
        if(exp % 2 == 1){
            half = (half * x) % mod;
        }

        return half;
    }

    int modInverse(int a){
        int m = mod;
        int x0 = 1;
        int x1 = 0;
        while(m != 0){
            int q = a/m;
            int temp = m;
            m = a % m;
            a = temp;
            temp = x1;
            x1 = x0 - q * x1;
            x0 = temp;
        }

        if(x0 < 0){
            x0 += mod;
        }

        return x0;
    }

    long long combination(int n, int k){
        if(k > n){
            return 0;
        }

        if(n - k < k){
            k = n-k;
        }

        long long num = 1, den = 1;
        for(int i=1; i<=k; i++){
            den = (den*i) % mod;
            num = (num * (n-i+1)) % mod;
        }
        return (num * modInverse(den)) % mod;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        long long result = m;
        result = (result * modPower(m-1, n-k-1)) % mod;
        result = (result * combination(n-1, k)) % mod;

        return result;
    }
};