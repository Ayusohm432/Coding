/*
Problem Link: https://www.geeksforgeeks.org/problems/coin-piles5152/1
*/

/*Coin Piles

You are given an array arr[] of integers, where each element represents the number of coins in a pile. You are also given an integer k.
Your task is to remove the minimum number of coins such that the absolute difference between the number of coins in any two updated piles is at most k.

Note: You can also remove a pile by removing all the coins of that pile.

Examples:

Input: arr[] = [2, 2, 2, 2], k = 0
Output: 0
Explanation: For any two piles the difference in the number of coins is <= 0. So no need to remove any coin. 
Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
Output: 2
Explanation: If we remove one coin each from both the piles containing 5 coins, then for any two piles the absolute difference in the number of coins is <= 3. 
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
0 ≤ k ≤ 104

*/

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];
        
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
        
        int result = INT_MAX;
        int previous = 0;
        
        for(int i=0; i<n; i++){
            if(i > 0){
                previous = prefixSum[i-1];
            }
            
            int pos = upper_bound(arr.begin()+i, arr.end(), arr[i]+k) - arr.begin();
            
            int total = pos > 0 ? prefixSum[n-1] - prefixSum[pos-1] : 0;
            int allowed = (n - pos) * (arr[i] + k);
            int extraCoins = previous + total - allowed;
            
            result = min(result, extraCoins);
        }
        
        return result;
    }
};
