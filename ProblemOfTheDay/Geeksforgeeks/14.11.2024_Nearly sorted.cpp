/*
Problem Link : https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
*/

/*Nearly sorted

Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
DO NOT use the direct library sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106

*/

//Approach-1
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < k + 1 && i < arr.size(); i++){
            pq.push(arr[i]);
        }
        
        for(int i = 0; i < arr.size(); i++){
            int smallest = pq.top();
            pq.pop();
            arr[i] = smallest;
            if(i + k + 1 < arr.size()){
                pq.push(arr[i + k + 1]);
            }
        }
    }
};

//Approach-2
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int j = 0; 
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            if(i >= k){
                arr[j++] = pq.top();
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            arr[j++] = pq.top();
            pq.pop();
        }
    }
};

