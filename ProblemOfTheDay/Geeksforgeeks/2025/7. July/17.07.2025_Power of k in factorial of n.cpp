/*
Problem Link: https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1
*/

/*Power of k in factorial of n

Given two positive integers n and k, determine the highest value of x such that kx divides n! (n factorial) completely (i.e., n % (kx) == 0).

Examples :

Input: n = 7, k = 2
Output: 4
Explanation: 7! = 5040, and 24 = 16 is the highest power of 2 that divides 5040.
Input: n = 10, k = 9
Output: 2
Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.
Constraints:
1 ≤ n ≤ 105
2 ≤ k ≤ 105

*/

class Solution {
    unordered_map<int, int> primeFactors;
  public:
    int countFactorial(int n, int prime){
        int count = 0;
        long long power = prime;
        while(power <= n){
            count += n/power;
            power *= prime;
        }
        return count;
    }
    
    void factorize(int k){
        while(k % 2 == 0){
            primeFactors[2]++;
            k /= 2;
        }
        
        for(int i=3; i*i<=k; i+=2){
            while(k % i == 0){
                primeFactors[i]++;
                k /= i;
            }
        }
        
        if(k > 2){
            primeFactors[k]++;
        }
    }
    int maxKPower(int n, int k) {
        // code here
        factorize(k);
        int ans = INT_MAX;
        
        for(auto& pair : primeFactors){
            int num = pair.first;
            int power = pair.second;
            int count = countFactorial(n, num);
            ans = min(ans, count/power);
        }
        
        return ans;
    }
};