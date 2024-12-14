/*
Problem Link: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
*/

/*Search in Rotated Sorted Array

Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
Output: 8
Explanation: 3 is found at index 8.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ key ≤ 106

*/

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == key){
                return mid;
            }
            
            if(arr[start] <= arr[mid]){
                if(key >= arr[start] && key<arr[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(key > arr[mid] && key <= arr[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};