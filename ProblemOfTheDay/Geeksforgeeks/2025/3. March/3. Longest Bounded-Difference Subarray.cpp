/*
Problem link: https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1
*/

/*Longest Bounded-Difference Subarray

Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.

Examples: 

Input: arr[] = [8, 4, 2, 6, 7], x = 4 
Output: [4, 2, 6] 
Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is greater than 4.
Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5 
Output: [2, 4, 7, 2] 
Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5. 
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 109
0 <= x<= 109

*/

class Solution {
    public:
      vector<int> longestSubarray(vector<int>& arr, int x) {
          // code here
          int n = arr.size();
          vector<int> result;
          deque<int> maxi, mini;
          int maxDifference = 0;
          int index1 = -1;
          int index2 = -1;
          
          int i=0, j=0;
          
          for(; j<n; j++){
              while(!maxi.empty() && maxi.back() < arr[j]){
                  maxi.pop_back();
              }
              while(!mini.empty() && mini.back() > arr[j]){
                  mini.pop_back();
              }
              maxi.push_back(arr[j]);
              mini.push_back(arr[j]);
              
              for(; i<n && ((abs(maxi.front() - arr[j]))>x || abs(mini.front() - arr[j]) > x); i++){
                  if(maxi.front() == arr[i]){
                      maxi.pop_front();
                  }
                  if(mini.front() == arr[i]){
                      mini.pop_front();
                  }
              }
              
              if(j - i + 1 > maxDifference){
                  index1 = i;
                  index2 = j;
                  maxDifference = j-i+1;
              }
          }
          for(int i=index1; i<=index2; i++){
              result.push_back(arr[i]);
          }
          
          return result;
      }
  };