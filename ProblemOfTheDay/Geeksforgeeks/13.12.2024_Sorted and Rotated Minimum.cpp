/*
Problem Link: https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
*/

/*Sorted and Rotated Minimum

A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109

*/

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int start = 0;
        int end = arr.size()-1;
        
        while(start < end){
            int mid = start + (end - start)/2;
            if(arr[mid] <= arr[end]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return arr[start];
    }
};