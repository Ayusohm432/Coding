/*
Problem Link: https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1
*/

/*Equalize the Towers

You are given an array heights[] representing the heights of towers and another array cost[] where each element represents the cost of modifying the height of respective tower.

The goal is to make all towers of same height by either adding or removing blocks from each tower.
Modifying the height of tower (add or remove) 'i' by 1 unit costs cost[i].
Return the minimum cost to equalize the heights of all towers.

Examples:

Input: heights[] = [1, 2, 3], cost[] = [10, 100, 1000]
Output: 120
Explanation: The heights can be equalized by either "Removing one block from 3 and adding one in 1" or "Adding two blocks in 1 and adding one in 2". Since the cost of operation in tower 3 is 1000, the first process would yield 1010 while the second one yields 120.
Input: heights[] = [7, 1, 5], cost[] = [1, 1, 1]
Output: 6
Explanation: The minimum cost to equalize the towers is 6, achieved by setting all towers to height 5.
Constraints:
1 ≤ heights.size() = cost.size() ≤ 105
1 ≤ heights[i] ≤ 104
1 ≤ cost[i] ≤ 103

*/

class Solution {
    int help(vector<int>& heights, vector<int>& cost, int k){
        int amount = 0;
        int n = heights.size();
        
        for(int i=0; i<n; i++){
            amount += abs(heights[i] - k) * cost[i];
        }
        
        return amount;
    }
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int low = INT_MAX;
        int high = INT_MIN;
        
        int n = heights.size();
        for(int i=0; i<n; i++){
            low = min(low, heights[i]);
            high = max(high, heights[i]);
        }
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(help(heights, cost, mid) >= help(heights, cost, mid+1)){
                low = mid + 1;
            }else if(help(heights, cost, mid) < help(heights, cost, mid+1)){
                high = mid;
            }
        }
        
        return help(heights, cost, low);
    }
};
