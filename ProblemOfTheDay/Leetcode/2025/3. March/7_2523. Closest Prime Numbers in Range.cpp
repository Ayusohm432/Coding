/*
Problem Link: https://leetcode.com/problems/closest-prime-numbers-in-range?envType=daily-question&envId=2025-03-07
*/

/*2523. Closest Prime Numbers in Range

Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106

*/

class Solution {
    public:
        bool isPrime(int num){
            if(num == 1){
                return false;
            }
            for(int div = 2; div*div <= num; div++){
                if(num % div == 0){
                    return false;
                }
            }
            return true;
        }
    
        vector<int> closestPrimes(int left, int right) {
            vector<int> primes;
    
            for(int num = left; num <= right; num++){
                if(isPrime(num) == true){
                    if(!primes.empty() && num - primes.back() <= 2){
                        return {primes.back(), num};
                    }
                    primes.push_back(num);
                }
            }
    
            int minDiff = INT_MAX;
            vector<int> result = {-1, -1};
    
            for(int i=1; i<primes.size(); i++){
                int diff = primes[i] - primes[i-1];
                if(diff < minDiff){
                    minDiff = diff;
                    result = {primes[i-1], primes[i]};
                }
            }
            return result;    
        }
    };