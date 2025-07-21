/*
Problem Link: https://www.geeksforgeeks.org/problems/count-the-coprimes/1
*/

/*Count the Coprimes

You are given an array arr[] of positive integers. Your task is to count the number of pairs (i, j) such that:


0 ≤ i < j ≤ n-1
gcd(arr[i], arr[j]) = 1
In other words, count the number of unordered pairs of indices (i, j) where the elements at those positions are co-prime.

Examples:

Input: arr[] = [1, 2, 3]
Output: 3
Explanation: (0,1), (0,2), (1,2) are the pair of indices where gcd(arr[i], arr[j]) = 1
Input: arr[] = [4, 8, 3, 9]
Output: 4
Explanation: (0,2), (0,3), (1,2), (1,3) are the pair of indices where gcd(arr[i], arr[j]) = 1
Constraints:
2 ≤ arr.size() ≤ 104
1 ≤ arr[i] ≤ 104

*/

class Solution {
  public:
    int cntCoprime(vector<int>& arr) {
        // code here
        int MaxSize = 10000;
        vector<int> mp(MaxSize+1, 0);
        
        for(int num : arr){
            mp[num]++;
        }
        
        vector<int> divisibleCount(MaxSize+1, 0);
        for(int i=1; i<=MaxSize; i++){
            for(int j=i; j<=MaxSize; j+=i){
                divisibleCount[i] += mp[j];
            }
        }
        
        vector<long long> gcdPairCount(MaxSize+1, 0);
        for(int i=MaxSize; i>=1; i--){
            long long curr = divisibleCount[i];
            gcdPairCount[i] = curr*(curr-1)/2;
            for(int j=2*i; j<=MaxSize; j+=i){
                gcdPairCount[i] -= gcdPairCount[j];
            }
        }
        
        return (int)gcdPairCount[1];
    }
};
