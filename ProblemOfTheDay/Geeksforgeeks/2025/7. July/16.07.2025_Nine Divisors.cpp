/*
Problem Link: https://www.geeksforgeeks.org/problems/nine-divisors3751/1
*/

/*Nine Divisors

Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

Examples :

Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.
Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 
Constraints:
1 ≤ n ≤ 109

*/

class Solution {
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i=2; i*i<=n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
  public:
    int countNumbers(int n) {
        // Code Here
        vector<int> primes;
        for(int i=2; i*i<=n; i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        
        int count = 0;
        
        for(int prime : primes){
            long long val = 1;
            for(int i=0; i<8; i++){
                val *= prime;
            }
            if(val <= n){
                count++;
            }else{
                break;
            }
        }
        
        int len = primes.size();
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                long long val = 1LL * primes[i] * primes[i] * primes[j] * primes[j];
                if(val <= n){
                    count++;
                }else{
                    break;
                }
            }
        }
        
        return count;
    }
};