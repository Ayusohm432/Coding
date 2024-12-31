/*
Problem Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/

/*Longest Consecutive Subsequence

Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
Output: 4
Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
Output: 7
Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 105

*/

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int ans=1;
        unordered_map<int,int> mm;
        for(int x:arr){
            if(!mm[x]){
                int left = mm[x-1];
                int right = mm[x+1];
                int total = left+right+1;
                mm[x]=total;
                mm[x-left]=total;
                mm[x+right]=total;
                ans=max(ans,total);
            }
        }
        return ans;
    }

};